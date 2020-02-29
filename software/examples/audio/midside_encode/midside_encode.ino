#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>


// GUItool: begin automatically generated code
AudioInputTDM            tdm1;           //xy=136,352
AudioRecordQueue         queue1;         //xy=406,192
AudioEffectMidSide       midside1;       //xy=425,246
AudioOutputTDM           tdm3;           //xy=697,442
AudioConnection          patchCord1(tdm1, 0, tdm3, 0);
AudioConnection          patchCord2(tdm1, 0, queue1, 0);
AudioConnection          patchCord3(tdm1, 0, midside1, 0);
AudioConnection          patchCord4(tdm1, 2, tdm3, 2);
AudioConnection          patchCord5(tdm1, 2, midside1, 1);
AudioConnection          patchCord6(midside1, 0, tdm3, 4);
AudioConnection          patchCord7(midside1, 0, tdm3, 6);
AudioConnection          patchCord8(midside1, 1, tdm3, 8);
AudioConnection          patchCord9(midside1, 1, tdm3, 10);
AudioControlCS42448      cs42448_1;      //xy=349,562
// GUItool: end automatically generated code


#define TFT_SCLK 13  // SCLK can also use pin 14
#define TFT_MOSI 11  // MOSI can also use pin 7
#define TFT_CS   6  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC    2  //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST   0 // RST can use any pin

#include <Adafruit_GFX.h>    // Core graphics library
#include <ST7735_t3.h> // Hardware-specific library

ST7735_t3 tft = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

int led = 13;
int sda = 18;

void setup() {
  AudioMemory(32);
  Wire.begin();  

  SPI.begin();
  delay(100);
  tft.initR(INITR_GREENTAB);
  tft.setRotation(1);
  
  tft.fillScreen(ST7735_BLACK);
  Serial.begin(9600);
  Serial.println("init...");
  tft.println("init...");
  
  AudioNoInterrupts();  
  cs42448_1.setAddress(0);
  cs42448_1.enable();
  cs42448_1.volume(1);
  cs42448_1.inputLevel(1);
  
  AudioInterrupts();   
  delay(100);
  queue1.begin();
  midside1.encode();
    
}

uint32_t oscilliscope_x = 0;
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

void loop() {
   
  // put your main code here, to run repeatedly:        
  if ( queue1.available() ) {   
    //Serial.print(".");
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

}
