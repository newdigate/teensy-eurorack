#include <Audio.h>
#include "teensy_eurorack.h"
#include "teensy_eurorack_audio.h"

// GUItool: begin automatically generated code
AudioInputTDM                   tdm1;           //xy=401,330
AudioOutputTDM                  tdm3;           //xy=962,420
AudioRecordQueue                queue2;         //xy=671,170
AudioRecordQueue                queue1;         //xy=671,170
AudioOutputSharedAD5754Dual     ad5754;           //xy=514,291
AudioInputSharedAD7606          ad7606;
AudioConnection                 patchCord19(tdm1, 0, queue1, 0);
AudioConnection                 patchCord18(ad7606, 0, queue2, 0);
AudioConnection                 patchCord1(tdm1, 0, ad5754, 0);
AudioConnection                 patchCord2(tdm1, 0, ad5754, 1);
AudioConnection                 patchCord3(tdm1, 0, ad5754, 2);
AudioConnection                 patchCord4(tdm1, 0, ad5754, 3);
AudioConnection                 patchCord5(tdm1, 0, ad5754, 4);
AudioConnection                 patchCord6(tdm1, 0, ad5754, 5);
AudioConnection                 patchCord7(tdm1, 0, ad5754, 6);
AudioConnection                 patchCord8(tdm1, 0, ad5754, 7); 
AudioControlCS42448             cs42448_1;      //xy=614,540
// GUItool: end automatically generated code

#define TFT_SCLK 13  // SCLK can also use pin 14
#define TFT_MOSI 11  // MOSI can also use pin 7
#define TFT_CS   6  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC    2  //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST   0 // RST can use any pin
#include <ST7735_t3.h> // Hardware-specific library
ST7735_t3 tft = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

unsigned long start_time;

void setup() {

  Serial.begin(9600);
  AudioNoInterrupts();  

  AudioMemory(160);
  //ad5754.begin(AD7607_BUSY, AD7607_START_CONVERSION, AD7607_CHIP_SELECT, AD7607_RESET, AD7607_RANGE_SELECT,DA_SYNC,LRCLK_CPY);
  //ad7606.begin(AD7607_BUSY, AD7607_START_CONVERSION, AD7607_CHIP_SELECT, AD7607_RESET, AD7607_RANGE_SELECT,DA_SYNC,LRCLK_CPY);
  cs42448_1.enable();
  cs42448_1.volume(1);
  AudioInterrupts();    // enable, both tones will start together
  delay(100);
  //pinMode(40, INPUT); 
  tft.initR(INITR_GREENTAB);
  tft.setRotation(3);
  tft.fillScreen(ST7735_BLACK);
   
  queue1.begin();  
  queue2.begin();  

  start_time = millis();
}


uint32_t oscilliscope_x = 0;
int16_t buffer[128];
int16_t lastbuffer[128];


uint32_t oscilliscope_x2 = 0;
int16_t buffer2[128];
int16_t lastbuffer2[128];

void updateScope() {

  oscilliscope_x = oscilliscope_x + 1;
  if (oscilliscope_x > 126) {
    return;
  }

  if (oscilliscope_x < 3) {
    return;
  }
  tft.drawLine(oscilliscope_x, 64.0f + (lastbuffer[oscilliscope_x-1] / 512.0f), oscilliscope_x + 1, 64.0f + (lastbuffer[oscilliscope_x] / 512.0f), ST7735_BLACK);
  tft.drawLine(oscilliscope_x, 64.0f + (buffer[oscilliscope_x-1] / 512.0f), oscilliscope_x + 1, 64.0f + (buffer[oscilliscope_x] / 512.0f), ST7735_MAGENTA);

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
  tft.drawLine(oscilliscope_x2, 64.0f + (lastbuffer2[oscilliscope_x2-1] / 512.0f), oscilliscope_x2 + 1, 64.0f + (lastbuffer2[oscilliscope_x2] / 512.0f), ST7735_BLACK);
  tft.drawLine(oscilliscope_x2, 64.0f + (buffer2[oscilliscope_x2-1] / 512.0f), oscilliscope_x2 + 1, 64.0f + (buffer2[oscilliscope_x2] / 512.0f), ST7735_CYAN);

//  canvas.drawLine(oscilliscope_x2, 64.0f + (buffer2[oscilliscope_x2-1] / 256.0f), oscilliscope_x2 + 1, 64.0f + (buffer2[oscilliscope_x2] / 256.0f), ST7735_RED, LineEndpointStyle::NoneAntialiased, LineEndpointStyle::None);
}


unsigned count = 0, count2 = 0;
void loop() {
   count++;

  if ( queue2.available() ) {   
    //Serial.print(".");
    if (oscilliscope_x2 < 128) {
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

  if (count % 5000000 == 0) {
    unsigned long newmillis = millis() - start_time;
     
    count2++;
    Serial.print(newmillis / (1000.0 * 60.0));
    Serial.print(" minutes: ");
    Serial.print(count2);
    Serial.print(" all=");
    Serial.print(AudioProcessorUsage());
    Serial.print(",");
    Serial.print(AudioProcessorUsageMax());
    Serial.print("    ");
    Serial.print("Memory: ");
    Serial.print(AudioMemoryUsage());
    Serial.print(",");
    Serial.print(AudioMemoryUsageMax());
    Serial.print("    ");
    Serial.print("Free Mem: ");
    Serial.print(memfree());
    Serial.println();
  }
}
