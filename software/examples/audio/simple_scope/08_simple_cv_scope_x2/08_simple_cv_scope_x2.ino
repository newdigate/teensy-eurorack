#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "input_shared_ad7606.h"
#include "output_shared_ad5754_dual.h"


// GUItool: begin automatically generated code
AudioOutputTDM           tdm3;           //xy=962,420
AudioOutputSharedAD5754Dual     ad5754;           //xy=514,291
AudioInputSharedAD7606          ad7606;
AudioRecordQueue         queue1;
AudioRecordQueue         queue2;
AudioConnection          patchCord9(ad7606, 0, queue1, 0);
AudioConnection          patchCord10(ad7606, 1, queue2, 0);

#include <ST7735_t3.h> // Hardware-specific library
#include <SPI.h>

#define TFT_SCLK 13  // SCLK can also use pin 14
#define TFT_MOSI 11  // MOSI can also use pin 7
#define TFT_CS   6  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC    2  //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST   -1 // RST can use any pin

ST7735_t3 TFT = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup() {
  Serial.begin(9600);
  AudioMemory(280);
  TFT.initR(INITR_144GREENTAB);
  TFT.setRotation(3);
  TFT.fillScreen(ST7735_BLACK);
  queue1.begin();
  queue2.begin();
}
unsigned count = 0;

uint32_t oscilliscope_x = 0;
int16_t buffer[128];
int16_t lastbuffer[128];

uint32_t oscilliscope_x2 = 0;
int16_t buffer2[128];
int16_t lastbuffer2[128];


void loop() {
  count++;

  if ( queue2.available() ) {
    //Serial.print(".");
    if (oscilliscope_x2 < 126) {
      // completely discard record buffers until x location >= 100
      while (queue2.available()) {
        queue2.readBuffer();
        queue2.freeBuffer();
      }
    } else  {
      while (queue2.available() > 1) {
        queue2.readBuffer();
        queue2.freeBuffer();
      }
      memcpy(lastbuffer2, buffer2, 256);
      memcpy(buffer2, queue2.readBuffer(), 256);
      oscilliscope_x2 = 0;
      queue2.freeBuffer();
    }
  }
  updateScope2();

  if ( queue1.available() ) {
    //Serial.print(".");
    if (oscilliscope_x < 126) {
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


  if (count % 50000 == 0) {
    Serial.print("all=");
    Serial.print(AudioProcessorUsage());
    Serial.print(",");
    Serial.print(AudioProcessorUsageMax());
    Serial.print("    ");
    Serial.print("Memory: ");
    Serial.print(AudioMemoryUsage());
    Serial.print(",");
    Serial.print(AudioMemoryUsageMax());
    Serial.println();
  }
}


void updateScope() {

  oscilliscope_x = oscilliscope_x + 1;
  if (oscilliscope_x > 126) {
    return;
  }

  if (oscilliscope_x < 3) {
    return;
  }
  TFT.drawLine(oscilliscope_x, 64.0f + (lastbuffer[oscilliscope_x - 1] / 512.0f), oscilliscope_x + 1, 64.0f + (lastbuffer[oscilliscope_x] / 512.0f), ST7735_BLACK);
  TFT.drawLine(oscilliscope_x, 64.0f + (buffer[oscilliscope_x - 1] / 512.0f), oscilliscope_x + 1, 64.0f + (buffer[oscilliscope_x] / 512.0f), ST7735_MAGENTA);

  //  canvas.drawLine(oscilliscope_x2, 64.0f + (buffer2[oscilliscope_x2-1] / 256.0f), oscilliscope_x2 + 1, 64.0f + (buffer2[oscilliscope_x2] / 256.0f), ST7735_RED, LineEndpointStyle::NoneAntialiased, LineEndpointStyle::None);
}

void updateScope2() {

  oscilliscope_x2 = oscilliscope_x2 + 1;
  if (oscilliscope_x2 > 126) {
    return;
  }

  if (oscilliscope_x2 < 3) {
    return;
  }
  TFT.drawLine(oscilliscope_x2, 64.0f + (lastbuffer2[oscilliscope_x2 - 1] / 512.0f), oscilliscope_x2 + 1, 64.0f + (lastbuffer2[oscilliscope_x2] / 512.0f), ST7735_BLACK);
  TFT.drawLine(oscilliscope_x2, 64.0f + (buffer2[oscilliscope_x2 - 1] / 512.0f), oscilliscope_x2 + 1, 64.0f + (buffer2[oscilliscope_x2] / 512.0f), ST7735_CYAN);

  //  canvas.drawLine(oscilliscope_x2, 64.0f + (buffer2[oscilliscope_x2-1] / 256.0f), oscilliscope_x2 + 1, 64.0f + (buffer2[oscilliscope_x2] / 256.0f), ST7735_RED, LineEndpointStyle::NoneAntialiased, LineEndpointStyle::None);
}
