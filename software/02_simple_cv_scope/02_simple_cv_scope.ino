#include <Audio.h>
#include "input_shared_ad7606.h"
#include "output_shared_ad5754_dual.h"

// GUItool: begin automatically generated code
AudioInputTDM            tdm1;           //xy=401,330
AudioRecordQueue         queue2;         //xy=671,170
AudioOutputTDM           tdm3;           //xy=962,420
AudioOutputSharedAD5754Dual     ad5754;           //xy=514,291
AudioInputSharedAD7606          ad7606;
AudioConnection          patchCord18(ad7606, 0, queue2, 0);
AudioControlCS42448      cs42448_1;      //xy=614,540
// GUItool: end automatically generated code

#define TFT_SCLK 13  // SCLK can also use pin 14
#define TFT_MOSI 11  // MOSI can also use pin 7
#define TFT_CS   6  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC    2  //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST   0 // RST can use any pin
#include <ST7735_t3.h> // Hardware-specific library
ST7735_t3 tft = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup() {
  AudioMemory(80);
  SPI.begin();
 
  tft.initR(INITR_GREENTAB);
  tft.setRotation(3);
  
  tft.fillScreen(ST7735_BLACK);
  Serial.begin(9600);
  queue2.begin();  
}

uint32_t oscilliscope_x2 = 0;
int16_t buffer2[128];
int16_t lastbuffer2[128];

void updateScope2() {

  oscilliscope_x2 = oscilliscope_x2 + 1;
  if (oscilliscope_x2 > 127) {
    return;
  }

  tft.drawLine(oscilliscope_x2, 64 + (lastbuffer2[oscilliscope_x2-1] >> 8), oscilliscope_x2 + 1, 64 + (lastbuffer2[oscilliscope_x2] >> 8), ST7735_BLACK);
  tft.drawLine(oscilliscope_x2, 64 + (buffer2[oscilliscope_x2-1] >> 8), oscilliscope_x2 + 1, 64 + (buffer2[oscilliscope_x2] >> 8), ST7735_RED);
}

unsigned count = 0;
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

  if (count % 5000000 == 0) {
    Serial.print("all=");
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


unsigned memfree(void) {
  extern unsigned long _ebss;
  extern unsigned long _sdata;
  extern unsigned long _estack;
  const unsigned DTCM_START = 0x20000000UL;
  unsigned dtcm = (unsigned)&_estack - DTCM_START;
  unsigned stackinuse = (unsigned) &_estack -  (unsigned) __builtin_frame_address(0);
  unsigned varsinuse = (unsigned)&_ebss - (unsigned)&_sdata;
  unsigned freemem = dtcm - (stackinuse + varsinuse);
  return freemem;
}