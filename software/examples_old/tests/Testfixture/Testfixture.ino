#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Encoder.h>
//#include <Bounce.h>

#define TFT_SCLK 14  // SCLK can also use pin 14
#define TFT_MOSI 7  // MOSI can also use pin 7
#define TFT_CS   6  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC    12  //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST   17  // RST can use any pin
#define SD_CS     4  // CS for SD card, can use any pin

#include <Adafruit_GFX.h>    // Core graphics library
//#include <Adafruit_ST7735.h> // Hardware-specific library
#include <ST7735_t3.h> // Hardware-specific library

// Option 1: use any pins but a little slower
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
ST7735_t3 tft = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

#include <Audio.h>
#include "BALibrary.h"
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


// GUItool: begin automatically generated code
//AudioSynthWaveformModulated sine1;          //xy=310,556
//AudioSynthWaveformSine   sine2;          //xy=310,612
//AudioOutputAnalogStereo  dacs1;          //xy=480,568
//AudioConnection          patchCord1(sine1, 0, dacs1, 0);
//AudioConnection          patchCord2(sine2, 0, dacs1, 1);
// GUItool: end automatically generated code

const int analogInPin = A14;  // Analog input pin that the potentiometer is attached to
const int analogInPin2 = A15;  // Analog input pin that the potentiometer is attached toconst int analogOutPin = A21; 
const int analogInCvPin = A20;  // Analog input pin that the potentiometer is attached to
const int analogInCvPin2 = A16;
// Analog output pin that the LED is attached to

const int analogOutPin = A21; // Analog output pin that the LED is attached to
const int analogOutPin2 = A22; // Analog output pin that the LED is attached to

void setup() {

  analogReference(0);
   
  Serial.begin(9600);
  pinMode(BUTTON1,INPUT_PULLUP);
  pinMode(BUTTON3,INPUT_PULLUP);
  pinMode(BUTTON2,INPUT_PULLUP);  
  pinMode(BUTTON4,INPUT_PULLUP);  

  pinMode(analogInPin, INPUT);  
  pinMode(analogInPin2, INPUT); 
  pinMode(analogInCvPin, INPUT);  
  pinMode(analogInCvPin2, INPUT); 
    
  pinMode(analogOutPin, OUTPUT);  
  pinMode(analogOutPin2, OUTPUT);  
  
  Serial.println("Ubuntu Test fixture");

  tft.initR(INITR_GREENTAB);
    tft.setRotation(1);
    // If the codec was already powered up (due to reboot) power itd own first
  //codecControl.disable();
  delay(100);
  AudioMemory(24);

  Serial.println("Enabling codec...\n");
  //codecControl.enable();
  delay(100);

  //sine1.frequency(5);
  //sine1.amplitude(1);
  //sine1.begin(WAVEFORM_SINE);
  //sine2.frequency(2);
  //sine2.amplitude(1);

}


long knob1 = 0, knob2 = 0, knob3 = 0; 


int sensorValue, sensorValue2, sensorValue3, sensorValue4 = 0;        // value read from the pot
long lastMillis = 0;

bool needsUpdate = true;

uint32_t oscilliscope_x = 0;

void loop() { 
  long current_millis = millis();
  
  long newKnob1, newKnob2, newKnob3;
  newKnob1 = Knob1.read();
  newKnob2 = Knob2.read();
  newKnob3 = Knob3.read();
  
  if (newKnob1 != knob1 || newKnob2 != knob2 || newKnob3 != knob3) {
    needsUpdate = true;
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
     needsUpdate = true;
  }
  
  if (button1.fallingEdge()) {
     Serial.println("Button 1");
     needsUpdate = true;
  }
  
  if (button2.fallingEdge()) {
     Serial.println("Button 2");
     needsUpdate = true;
  }
  
  if (button3.fallingEdge()) {
     Serial.println("Button 3");
     needsUpdate = true;
  }


  //if (current_millis > lastMillis + 1) 
  {
    uint16_t oldValue = sensorValue*128/1024;
    uint16_t oldValue2 = sensorValue2*128/1024;
    uint16_t oldValue3 = sensorValue3*128/2048;
    uint16_t oldValue4 = sensorValue4*128/2048;
    //tft.drawPixel(oscilliscope_x-1, sensorValue*128/1024, ST7735_GREEN );
  
    int newsensorValue = analogRead(analogInPin);
    if (sensorValue != newsensorValue) {
      sensorValue = newsensorValue;
      //Serial.print("a0 in: ");
      //Serial.println(sensorValue, DEC);
      analogWrite(analogOutPin, sensorValue);
    }
    
    int newsensorValue2 = analogRead(analogInPin2);
    if (sensorValue2 != newsensorValue2) {
      sensorValue2 = newsensorValue2;
      //Serial.print("a1 in: ");
      //Serial.println(sensorValue2, DEC);
      analogWrite(analogOutPin2, sensorValue2);
    }

    int newsensorValue3 = analogRead(analogInCvPin);
    if (sensorValue3 != newsensorValue3) {
      sensorValue3 = newsensorValue3;
    }
    int newsensorValue4 = analogRead(analogInCvPin2);
    if (sensorValue4 != newsensorValue4) {
      sensorValue4 = newsensorValue4;
    }

    tft.drawLine(oscilliscope_x-1, oldValue+1, oscilliscope_x, sensorValue*128/1024+1, ST7735_RED ); 
    
    
    tft.drawLine(oscilliscope_x-1, oldValue2+1, oscilliscope_x, sensorValue2*128/1024 + 1, ST7735_BLUE );    
    tft.drawLine(oscilliscope_x-1, oldValue3+1, oscilliscope_x, sensorValue3*128/2048 + 1 , ST7735_YELLOW ); 
    tft.drawLine(oscilliscope_x-1, oldValue4+1, oscilliscope_x, sensorValue4*128/2048 + 1, ST7735_GREEN ); 
    oscilliscope_x++;
    if (oscilliscope_x >= 128)
      needsUpdate = true;
    oscilliscope_x%=128;
    lastMillis = current_millis;
  }


  
  if (needsUpdate) {
    updateDisplay();
    needsUpdate = false;
  }

}

void updateDisplay() {
  tft.fillScreen(ST7735_BLACK);

  tft.setTextColor(ST7735_BLUE);

  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor(1,1);
  tft.print("knob1:");
  tft.print(knob1, HEX);
  
  tft.setCursor(1,9);
  tft.print("knob2:");
    tft.print(knob2, HEX);
   
  tft.setCursor(1,17);
  tft.print("knob3:");
  tft.print(knob3, HEX);
  
  tft.setCursor(1,97);
  tft.print("---");

  
  tft.setCursor(1,105);
  tft.print("---");

 
}
