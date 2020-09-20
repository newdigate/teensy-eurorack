#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Adafruit_GFX.h>    // Core graphics library
#include <ST7735_t3.h>

#define sclk 14//27  // SCLK can also use pin 13,14,
#define mosi 7
#define cs_ 6
#define dc 12//  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define rst 17// RST can use any pin

//Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, mosi, sclk, rst);
ST7735_t3 tft = ST7735_t3(cs_, dc, mosi, sclk, rst);


#include "BALibrary.h"
using namespace BALibrary;

// GUItool: begin automatically generated code
AudioPlaySdRawResampled           playSdRaw1;     //xy=179,396
AudioInputI2S            i2s1;           //xy=200,285
AudioMixer4              mixer2;         //xy=468,455
AudioMixer4              mixer1;         //xy=484,302
AudioRecordQueue         queue1;         //xy=732,413
AudioRecordQueue         queue2;         //xy=733,479
AudioOutputI2S           i2s2;           //xy=739,347
AudioConnection          patchCord1(playSdRaw1, 0, mixer1, 1);
AudioConnection          patchCord2(playSdRaw1, 0, mixer2, 1);
AudioConnection          patchCord3(i2s1, 0, mixer1, 0);
AudioConnection          patchCord4(i2s1, 1, mixer2, 0);
AudioConnection          patchCord5(mixer2, 0, i2s2, 1);
AudioConnection          patchCord6(mixer2, queue2);
AudioConnection          patchCord7(mixer1, 0, i2s2, 0);
AudioConnection          patchCord8(mixer1, queue1);
// GUItool: end automatically generated code


BAAudioControlWM8731      codecControl;

int sensorValue = 0, sensorValue2 =0;
const int analogInPin = A14;
const int analogInPin2 = A15;

int16_t buffer[128];
int16_t lastbuffer[128];
uint32_t oscilliscope_x = 0;

int16_t buffer2[128];
int16_t lastbuffer2[128];
uint32_t oscilliscope_x2 = 0;

void setup() {
  analogReference(0);
  pinMode(analogInPin, INPUT);
  pinMode(analogInPin2, INPUT);
 
  Serial.begin(57600);
  if (!(SD.begin(BUILTIN_SDCARD))) {
    // stop here if no SD card, but print a message
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
 
  AudioMemory(24);
  codecControl.disable();
  delay(100);
   
  codecControl.enable();
  delay(100);
  playSdRaw1.setPlaybackRate(-0.5);
  playSdRaw1.play("DEMO2.RAW");


  tft.initR(INITR_GREENTAB); // initialize a ST7735R chip, green tab
  tft.setRotation(1);
  tft.setTextWrap(true);
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_BLUE);   
  tft.println("Teensy");
  tft.println(".raw");
  tft.println("audio");
  tft.println("resampler...");

  Serial.println("playing...");
  queue1.begin();
  queue2.begin();
}

void loop() {

  int newsensorValue = analogRead(analogInPin);
  if (newsensorValue / 16 != sensorValue / 16) {
    sensorValue = newsensorValue;
    float rate = (sensorValue - 512.0) / 512.0;
    playSdRaw1.setPlaybackRate(rate);
    Serial.printf("rate: %f %x\n", rate, sensorValue );
  }

  int newsensorValue2 = analogRead(analogInPin2);
  if (newsensorValue2 / 16 != sensorValue2 / 16) {
    sensorValue2 = newsensorValue2;
    float volume = sensorValue2 / 1024.0;
    mixer1.gain(1, volume);
    mixer2.gain(1, volume);
    Serial.printf("volume is: %f %x\n", volume, sensorValue2 );
  }

  if ( queue1.available() ) {
    if (oscilliscope_x < 128) {
      // completely discard record buffers until x location >= 128
      while (queue1.available()) {
        queue1.readBuffer();     
        queue1.freeBuffer();   
      }
    } else  {
      // oscilliscope_x >= 128
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

  if ( queue2.available() ) {
    if (oscilliscope_x2 < 128) {
      // completely discard record buffers until x location >= 128
      while (queue2.available()) {
        queue2.readBuffer();     
        queue2.freeBuffer();   
      }
    } else  {
      // oscilliscope_x >= 128
      while (queue2.available() > 1) {
        queue2.readBuffer();     
        queue2.freeBuffer();   
      }
      memcpy(lastbuffer2, buffer2, 256);
      memcpy(buffer2, queue2.readBuffer(), 256);
      oscilliscope_x2= 0;
      queue2.freeBuffer();
    }
  }
  
  updateScope1();      
  updateScope2(); 
  
  // put your main code here, to run repeatedly:
  if (!playSdRaw1.isPlaying()) {
    //Serial.println("playing...");

    playSdRaw1.play("demo2.raw");
  }
}


void updateScope1() {
  oscilliscope_x = oscilliscope_x + 1;
  if (oscilliscope_x > 127) {
    return;
  }

  tft.drawLine(oscilliscope_x, 64 + (lastbuffer[oscilliscope_x-1] >> 9), oscilliscope_x + 1,  64 + (lastbuffer[oscilliscope_x] >> 9), ST7735_BLACK);
  tft.drawLine(oscilliscope_x, 64 + (buffer[oscilliscope_x-1] >> 9),     oscilliscope_x + 1,      64 + (buffer[oscilliscope_x] >> 9), ST7735_GREEN);
}


void updateScope2() {
  oscilliscope_x2 = oscilliscope_x2 + 1;
  if (oscilliscope_x2 > 127) {
    return;
  }

  tft.drawLine(oscilliscope_x2, 64 + (lastbuffer2[oscilliscope_x2-1] >> 9), oscilliscope_x2 + 1,  64 + (lastbuffer2[oscilliscope_x2] >> 9), ST7735_BLACK);
  tft.drawLine(oscilliscope_x2, 64 + (buffer2[oscilliscope_x2-1] >> 9),     oscilliscope_x2 + 1,    64 + (buffer2[oscilliscope_x2] >> 9), ST7735_BLUE);
}
