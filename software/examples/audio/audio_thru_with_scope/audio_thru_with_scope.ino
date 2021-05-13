#include <Audio.h>
#include <SPI.h>
#include <ST7735_t3.h> // Hardware-specific library
#include "teensy_eurorack.h"

// GUItool: begin automatically generated code
AudioInputTDM            tdm1;           //xy=257,403
AudioRecordQueue         queue1;         //xy=527,243
AudioOutputTDM           tdm3;           //xy=671,431
AudioConnection          patchCord1(tdm1, 0, tdm3, 0);
AudioConnection          patchCord2(tdm1, 0, queue1, 0);
AudioConnection          patchCord3(tdm1, 0, tdm3, 12);
AudioConnection          patchCord4(tdm1, 2, tdm3, 2);
AudioConnection          patchCord5(tdm1, 2, tdm3, 14);
AudioConnection          patchCord6(tdm1, 4, tdm3, 4);
AudioConnection          patchCord7(tdm1, 6, tdm3, 6);
AudioConnection          patchCord8(tdm1, 8, tdm3, 8);
AudioConnection          patchCord9(tdm1, 10, tdm3, 10);
AudioControlCS42448      cs42448_1;      //xy=470,613
// GUItool: end automatically generated code

ST7735_t3 tft = ST7735_t3(TFT_CS, TFT_DC, TFT_RST);

int led = 13;
int sda = 18;

void setup() {
  //pinMode(led, INPUT);  
  AudioMemory(180);
  //Wire.begin();  
  //SPI.setSCK  (14);
  //SPI.setMOSI (7 );
  //SPI.setMISO (12);
  
  SPI.begin();
  delay(100);
  tft.initR(INITR_GREENTAB);
  tft.setRotation(3);
  
  tft.fillScreen(ST7735_BLACK);
  Serial.begin(9600);
  Serial.println("init...");
  tft.println("init...");
  
  AudioNoInterrupts();  // disable audio library momentarily
  // put your setup code here, to run once:
  //cs42448_1.setAddress(0);
  cs42448_1.enable();
  cs42448_1.volume(1);

  //cs42448_1.inputLevel(1, 15.0);
  //cs42448_1.inputLevel(2, 15.0);
  //cs42448_1.inputLevel(1);
  
  AudioInterrupts();    // enable, both tones will start together
  delay(100);
  queue1.begin();
    
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

unsigned count = 0;
void loop() {
   count++;
   
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
