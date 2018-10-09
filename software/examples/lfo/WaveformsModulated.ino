// Waveform Modulation Example - Create waveforms with 
// modulated frequency
//
// This example is meant to be used with 3 buttons (pin 0,
// 1, 2) and 2 knobs (pins 16/A2, 17/A3), which are present
// on the audio tutorial kit.
//   https://www.pjrc.com/store/audio_tutorial_kit.html
//
// Use an oscilloscope to view the 2 waveforms.
//
// Button0 changes the waveform shape
//
// Knob A2 changes the amount of frequency modulation
//
// Knob A3 varies the shape (only for Pulse & Variable Triangle)
//
// This example code is in the public domain.

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce.h>
#include <Encoder.h>
#include "BAGuitar.h"
using namespace BAGuitar;

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#define TFT_SCLK 14  // SCLK can also use pin 14
#define TFT_MOSI 7  // MOSI can also use pin 7
#define TFT_CS   6  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC    12  //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST   17  // RST can use any pin
#define SD_CS     4  // CS for SD card, can use any pin

#include <Adafruit_GFX.h>    // Core graphics library
//#include <Adafruit_ST7735.h> // Hardware-specific library
#include <ST7735_t3.h> // Hardware-specific library
#include <SPI.h>

// Option 1: use any pins but a little slower
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
ST7735_t3 tft = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

// GUItool: begin automatically generated code
AudioSynthWaveformModulated sine1;          //xy=307,132
AudioInputI2S            i2s2;           //xy=432,240
AudioSynthWaveformModulated waveformMod1;   //xy=528,104
AudioRecordQueue         queue1;         //xy=704,357
AudioMixer4              mixer1;         //xy=760,162
AudioOutputI2S           i2s1;           //xy=917,171
AudioConnection          patchCord1(sine1, 0, waveformMod1, 0);
AudioConnection          patchCord2(i2s2, 0, mixer1, 2);
AudioConnection          patchCord3(i2s2, 1, mixer1, 3);
AudioConnection          patchCord4(waveformMod1, queue1);
AudioConnection          patchCord5(waveformMod1, 0, mixer1, 0);
AudioConnection          patchCord6(mixer1, 0, i2s1, 0);
AudioConnection          patchCord7(mixer1, 0, i2s1, 1);
// GUItool: end automatically generated code

BAAudioControlWM8731      codecControl;

Bounce button0 = Bounce(4, 15);
Bounce button1 = Bounce(24, 15);
Bounce button2 = Bounce(27, 15);

Encoder knobLeft(2, 3);
Encoder knobCenter(10, 16);
Encoder knobRight(25, 26);

int current_waveform=0;
int current_mod_waveform=0;

long positionLeft  = -999;
long positionCenter  = -999;
long positionRight = -999;


float offset_sine1amplitude = 0.5;
float offset_sine1frequency = 0.01;
float offset_waveformMod1frequency = 261.63;
extern const int16_t myWaveform[256];  // defined in myWaveform.ino

void setup() {
  Serial.begin(9600);
  pinMode(4, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);

  delay(300);
  Serial.println("Waveform Modulation Test");
  
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(48);

  // Comment these out if not using the audio adaptor board.
  // If the codec was already powered up (due to reboot) power itd own first
  codecControl.disable();
  mixer1.gain(0, 0.03);
  mixer1.gain(2, 0.4);
  mixer1.gain(3, 0.4);
  
  delay(100);
  //AudioMemory(24);

  Serial.println("Enabling codec...\n");
  codecControl.enable();
  delay(100);
  // Confirgure both to use "myWaveform" for WAVEFORM_ARBITRARY
  waveformMod1.arbitraryWaveform(myWaveform, 172.0);

  // Configure for middle C note without modulation
  waveformMod1.frequency(offset_waveformMod1frequency);
  waveformMod1.amplitude(1.0);
  sine1.begin(WAVEFORM_SINE);
  sine1.frequency(offset_sine1frequency); // Sine waves are low frequency oscillators (LFO)
  sine1.amplitude(offset_sine1amplitude);
  current_waveform = WAVEFORM_TRIANGLE_VARIABLE;
  waveformMod1.begin(current_waveform);

  tft.initR(INITR_GREENTAB);
  tft.fillScreen(ST7735_BLACK);
  tft.setRotation(3);
  tft.setTextColor(ST7735_BLUE);
  tft.setTextSize(4);
  tft.println("LFO");
  tft.setTextSize(1);
  // uncomment to try modulating phase instead of frequency
  //waveformMod1.phaseModulation(720.0);

  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor(1,1);
  tft.print("mod frq:");

  tft.setCursor(1,9);
  tft.print("mod amp:");
   
  tft.setCursor(1,17);
  tft.print("freq:");

  tft.setCursor(1,97);
  tft.print("wave:");

  tft.setCursor(1,105);
  tft.print("mod wave:");

        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,97);
        tft.println("Sine");  
        
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,105);
        tft.println("Sine");  
        
  queue1.begin();
}
int16_t buffer[128];
int16_t lastbuffer[128];
long last_millis_scope =0;

byte b = 0;
bool refreshDisplay = true;
bool clearDisplay = false;
bool lastCycleDisplayWasRefreshed = false;

float lastsine1amplitude = 0;
float lastsine1frequency = 0;
float lastwaveformMod1frequency = 0;

void loop() {
  long current_millis = millis();
  
  if (queue1.available() ) {
    if (!refreshDisplay) {
      queue1.readBuffer();
      queue1.freeBuffer();
    } else {
      if (clearDisplay) {
        //tft.fillScreen(ST7735_BLACK);
        tft.fillRect(1,48, 127, 32, ST7735_BLACK);
        clearDisplay = false;
        lastCycleDisplayWasRefreshed = true;
      } else 
            lastCycleDisplayWasRefreshed = false;

      last_millis_scope = current_millis;
      memcpy(lastbuffer, buffer, 256);
      memcpy(buffer, queue1.readBuffer(), 256);
      queue1.freeBuffer();
      refreshDisplay = false;
      b = 0;
    }
  }
  
  b = b + 1;
  if (b == 127) 
  {
    b = 1;
    refreshDisplay = true;
    //delay (10);
  }


  if (current_millis > last_millis_scope + 50) {
    refreshDisplay = true;
    clearDisplay = true;
    return;
  }
  
  if (buffer[b] >> 11 != lastbuffer[b] >> 11 || buffer[b-1] >> 11 != lastbuffer[b-1] >> 11) {
    if (!lastCycleDisplayWasRefreshed)
      tft.drawLine(b, 64 + (lastbuffer[b-1] >> 11), b + 1, 64 + (lastbuffer[b] >> 11), ST7735_BLACK);
    tft.drawLine(b, 64 + (buffer[b-1] >> 11), b + 1, 64 + (buffer[b] >> 11), ST7735_GREEN);
  }
  //lastbuffer[b] = buffer[b];
  
  long newLeft, newRight, newCenter;
  newLeft = knobLeft.read();
  newRight = knobRight.read();
  newCenter = knobCenter.read();
  if (newLeft != positionLeft || newRight != positionRight || newCenter != positionCenter) {
    Serial.print("Left = ");
    Serial.print(newLeft);

    
    Serial.print(", Center = ");
    Serial.print(newCenter);
    
    Serial.print(", Right = ");
    Serial.print(newRight);
    Serial.println();
    positionLeft = newLeft;
    positionRight = newRight;
    positionCenter = newCenter;

    float sine1amplitude = offset_sine1amplitude + (float)positionLeft / 256.0;
    float sine1frequency = offset_sine1frequency + (float)positionRight / 256.0;
    float waveformMod1frequency = offset_waveformMod1frequency + (float)positionCenter;
    
    // use Knobsto adjust the amount of modulation
    sine1.amplitude(sine1amplitude);
    sine1.frequency(sine1frequency);
    waveformMod1.frequency(waveformMod1frequency);

    if ( lastsine1frequency != sine1frequency ) {
      tft.setTextColor(ST7735_BLACK);
      tft.setCursor(64,1);
      tft.println(lastsine1frequency);
      
      tft.setTextColor(ST7735_YELLOW);
      tft.setCursor(64,1);
      tft.println(sine1frequency);
    }
    
    if ( lastsine1amplitude != sine1amplitude ) {
      tft.setTextColor(ST7735_BLACK);
      tft.setCursor(64,9);
      tft.println(lastsine1amplitude);  
      
      tft.setTextColor(ST7735_YELLOW);
      tft.setCursor(64,9);
      tft.println(sine1amplitude);  
     }

    if (lastwaveformMod1frequency != waveformMod1frequency) {
      tft.setTextColor(ST7735_BLACK);
      tft.setCursor(64,17);
      tft.println(lastwaveformMod1frequency);   
       
      tft.setTextColor(ST7735_YELLOW);
      tft.setCursor(64,17);
      tft.println(waveformMod1frequency);   
    }

    lastsine1amplitude = sine1amplitude;
    lastsine1frequency = sine1frequency;
    lastwaveformMod1frequency = waveformMod1frequency;
  }
  
  // Read the buttons and knobs, scale knobs to 0-1.0
  button0.update();
  button1.update();
  button2.update();
  

  
  // Button 0 or 2 changes the waveform type
  if (button0.fallingEdge()) {
    switch (current_waveform) {
      case WAVEFORM_SINE:
        current_waveform = WAVEFORM_SAWTOOTH;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,97);
        tft.println("Sine");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,97);
        tft.println("Sawtooth");   
        Serial.println("Sawtooth");
        break;
      case WAVEFORM_SAWTOOTH:
        current_waveform = WAVEFORM_SAWTOOTH_REVERSE;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,97);
        tft.println("Sawtooth");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,97);
        tft.println("Rev Saw");   
        Serial.println("Rev Saw");
        break;
      case WAVEFORM_SAWTOOTH_REVERSE:
        current_waveform = WAVEFORM_SQUARE;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,97);
        tft.println("Rev Saw");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,97);
        tft.println("Square");   
        Serial.println("Square");
        break;
      case WAVEFORM_SQUARE:
        current_waveform = WAVEFORM_TRIANGLE;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,97);
        tft.println("Square");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,97);
        tft.println("Triangle");   
        Serial.println("Triangle");
        break;
      case WAVEFORM_TRIANGLE:
        current_waveform = WAVEFORM_TRIANGLE_VARIABLE;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,97);
        tft.println("Triangle");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,97);
        tft.println("Var Tri");   
        Serial.println("Var Tri");
        break;
      case WAVEFORM_TRIANGLE_VARIABLE:
        current_waveform = WAVEFORM_ARBITRARY;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,97);
        tft.println("Var Tri");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,97);
        tft.println("Arbwave");  
        Serial.println("Arbwave");
        break;
      case WAVEFORM_ARBITRARY:
        current_waveform = WAVEFORM_PULSE;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,97);
        tft.println("Arbwave");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,97);
        tft.println("Pulse");  
        Serial.println("Pulse");
        break;
      case WAVEFORM_PULSE:
        current_waveform = WAVEFORM_SAMPLE_HOLD;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,97);
        tft.println("Pulse");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,97);
        tft.println("Samp&Hold");  
        Serial.println("Samp&Hold");
        break;
      case WAVEFORM_SAMPLE_HOLD:
        current_waveform = WAVEFORM_SINE;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,97);
        tft.println("Samp&Hold");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,97);
        tft.println("Sine");         
        Serial.println("Sine");
        break;
    }
    waveformMod1.begin(current_waveform);
  }
  
  if (button1.fallingEdge()) {
    switch (current_mod_waveform) {
      case WAVEFORM_SINE:
        current_mod_waveform = WAVEFORM_SAWTOOTH;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,105);
        tft.println("Sine");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,105);
        tft.println("Sawtooth");   
        Serial.println("Sawtooth");
        break;
      case WAVEFORM_SAWTOOTH:
        current_mod_waveform = WAVEFORM_SAWTOOTH_REVERSE;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,105);
        tft.println("Sawtooth");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,105);
        tft.println("Rev Saw");  
        Serial.println("Rev Saw");
        break;
      case WAVEFORM_SAWTOOTH_REVERSE:
        current_mod_waveform = WAVEFORM_SQUARE;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,105);
        tft.println("Rev Saw");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,105);
        tft.println("Square");   
        Serial.println("Square");
        break;
      case WAVEFORM_SQUARE:
        current_mod_waveform = WAVEFORM_TRIANGLE;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,105);
        tft.println("Square");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,105);
        tft.println("Triangle");   
        Serial.println("Triangle");
        break;
      case WAVEFORM_TRIANGLE:
        current_mod_waveform = WAVEFORM_TRIANGLE_VARIABLE;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,105);
        tft.println("Triangle");   
  
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,105);
        tft.println("Var Tri");   
        Serial.println("Var Tri");
        break;
      case WAVEFORM_TRIANGLE_VARIABLE:
        current_mod_waveform = WAVEFORM_ARBITRARY;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,105);
        tft.println("Var Tri");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,105);
        tft.println("Arbwave");  
        Serial.println("Arbitary Waveform");
        break;
      case WAVEFORM_ARBITRARY:
        current_mod_waveform = WAVEFORM_PULSE;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,105);
        tft.println("Arbwave");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,105);
        tft.println("Pulse");
        Serial.println("Pulse");
        break;
      case WAVEFORM_PULSE:
        current_mod_waveform = WAVEFORM_SAMPLE_HOLD;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,105);
        tft.println("Pulse");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,105);
        tft.println("Samp&Hold");  
        Serial.println("Sample & Hold");
        break;
      case WAVEFORM_SAMPLE_HOLD:
        current_mod_waveform = WAVEFORM_SINE;
        tft.setTextColor(ST7735_BLACK);
        tft.setCursor(64,105);
        tft.println("Samp&Hold");   
         
        tft.setTextColor(ST7735_YELLOW);
        tft.setCursor(64,105);
        tft.println("Sine");      
        Serial.println("Sine");
        break;
    }
    sine1.begin(current_mod_waveform);
  }
}

