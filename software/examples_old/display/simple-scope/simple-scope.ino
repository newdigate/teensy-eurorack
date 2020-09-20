#include "Adafruit_GFX.h"
#include <ST7735_t3.h>

// Adapter from http://www.pjrc.com/store/audio_tutorial_kit.html
// Part 1-3: First "Hello World" program, play a music file

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

//Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, mosi, sclk, rst);
ST7735_t3 tft = ST7735_t3(6, 12, 7, 14, 17);

#include "BALibrary.h"
// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=492.8571472167969,517.1428833007812
AudioOutputAnalogStereo  dacs1;          //xy=640.0000228881836,705.4285697937012
AudioRecordQueue         queue1;         //xy=742.8571281433105,597.1428470611572
AudioAnalyzeFFT1024      fft256_1;       //xy=798.8571472167969,546.1428833007812
AudioOutputI2S           i2s1;           //xy=825.8571472167969,466.14288330078125
AudioConnection          patchCord1(i2s2, 0, i2s1, 0);
AudioConnection          patchCord2(i2s2, 0, dacs1, 0);
AudioConnection          patchCord3(i2s2, 0, fft256_1, 0);
AudioConnection          patchCord4(i2s2, 0, queue1, 0);
AudioConnection          patchCord5(i2s2, 1, i2s1, 1);
AudioConnection          patchCord6(i2s2, 1, dacs1, 1);
// GUItool: end automatically generated code


using namespace BALibrary;
BAAudioControlWM8731      codecControl;


#define BUTTON1 25  //NEXT
#define BUTTON2 28  //Play Pause
#define BUTTON3 32  //PREV 
#define BUTTON4 38  //PREV 
Bounce button0 = Bounce(BUTTON1, 15);
Bounce button1 = Bounce(BUTTON2, 15);
Bounce button2 = Bounce(BUTTON3, 15);
Bounce button3 = Bounce(BUTTON4, 15);

#define ENC1A 26
#define ENC1B 27
#define ENC2A 29 
#define ENC2B 30 
#define ENC3A 36  
#define ENC3B 37  

Encoder Knob1(ENC1A, ENC1B);
Encoder Knob2(ENC2A, ENC2B);
Encoder Knob3(ENC3A, ENC3B);

long knob1 = 0, knob2 = 0, knob3 = 0; 
int sensorValue, sensorValue2, sensorValue3, sensorValue4 = 0;        // value read from the pot
long lastMillis = 0;
uint32_t oscilliscope_x = 0;

void setup() {
  pinMode(BUTTON1,INPUT_PULLUP);
  pinMode(BUTTON3,INPUT_PULLUP);
  pinMode(BUTTON2,INPUT_PULLUP);  
  pinMode(BUTTON4,INPUT_PULLUP);  
  
  codecControl.disable();
  delay(100);
  AudioMemory(40); 

  Serial.println("Enabling codec...\n");
  codecControl.enable();
  Serial.println("Enabled...\n");
  delay(100);

  
  tft.initR(INITR_GREENTAB); // initialize a ST7735R chip, green tab
  tft.setRotation(1);
  tft.setTextWrap(false);
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_BLUE);   
  //fft256_1.begin();
  //fft256_1.windowFunction(AudioWindowHanning1024);

  //queue2.begin();
}

int currX = 0;
int mode = 0;


void updateControls() {
  long newKnob1, newKnob2, newKnob3;
  newKnob1 = Knob1.read();
  newKnob2 = Knob2.read();
  newKnob3 = Knob3.read();
  
  if (newKnob1 != knob1 || newKnob2 != knob2 || newKnob3 != knob3) {
    Serial.print("1 = ");
    Serial.print(newKnob1);

    
    Serial.print(", 2 = ");
    Serial.print(newKnob2);
    
    Serial.print(", 3 = ");
    Serial.print(newKnob3);
    
    Serial.println();
    
    knob1 = newKnob1;
    knob2 = newKnob2;
    knob3 = newKnob3;
  }
  
  // Read the buttons and knobs, scale knobs to 0-1.0
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  
  if (button0.fallingEdge()) {
     Serial.println("Button 0");
  }
  
  if (button1.fallingEdge()) {
     Serial.println("Button 1");

  }
  
  if (button2.fallingEdge()) {
     Serial.println("Button 2");
  }
  
  if (button3.fallingEdge()) {
     Serial.println("Button 3");
     if (mode == 0) mode = 1; else mode = 0;
     
     if (mode == 1)
       queue1.begin();
     else {  
       queue1.end();
       queue1.clear();
     }
  }
}

int16_t buffer[128];
int16_t lastbuffer[128];

void updateScope() {



  oscilliscope_x = oscilliscope_x + 1;
  if (oscilliscope_x > 127) {
    return;
  }

  tft.drawLine(oscilliscope_x, 64 + (lastbuffer[oscilliscope_x-1] >> 8), oscilliscope_x + 1, 64 + (lastbuffer[oscilliscope_x] >> 8), ST7735_BLACK);
  tft.drawLine(oscilliscope_x, 64 + (buffer[oscilliscope_x-1] >> 8), oscilliscope_x + 1, 64 + (buffer[oscilliscope_x] >> 8), ST7735_GREEN);

  
}

void updateFFT() {
  
    if (fft256_1.available()) {

      currX ++;
      if (currX > 128)
        currX = 0;
      
      for (int i=0; i<128; i++) {
        float n = fft256_1.read(i);
        int16_t j = 40 * log(n * 2000 + 1);
        tft.drawPixel(i, currX, color565(j,j,j) );
      }
    }    
}

// Pass 8-bit (each) R,G,B, get back 16-bit packed color
uint16_t color565(uint8_t r, uint8_t g, uint8_t b) {
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

void loop() {
  updateControls();
  
  switch(mode) {
    case 0 : 
      while (queue1.available()) {
        queue1.freeBuffer();
      }
      updateFFT(); 
      break;
      
    case 1 : 
      if ( queue1.available() ) {   

        if (oscilliscope_x < 128) {
          // completely discard record buffers until x location >= 100
          while (queue1.available()) {
            queue1.readBuffer();     
            queue1.freeBuffer();   
          }
        } else  {
          while (queue1.available() > 1) {
            queue1.readBuffer();     
            queue1.freeBuffer();   
          }
          memcpy(lastbuffer, buffer, 256);
          memcpy(buffer, queue1.readBuffer(), 256);
          oscilliscope_x = 0;
          queue1.freeBuffer();
        }
      }
      updateScope(); 
      break;
      
    default : 
      while (queue1.available()) {
        queue1.freeBuffer();
      }
      break;
  }
}
