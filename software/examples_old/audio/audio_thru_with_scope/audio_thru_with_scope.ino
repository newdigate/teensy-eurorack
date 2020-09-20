#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputTDM            tdm1;           //xy=401,330
AudioRecordQueue         queue1;         //xy=671,170
AudioOutputTDM           tdm3;           //xy=962,420
AudioConnection          patchCord1(tdm1, 0, tdm3, 0);
AudioConnection          patchCord2(tdm1, 0, queue1, 0);
AudioConnection          patchCord3(tdm1, 1, tdm3, 1);
AudioConnection          patchCord4(tdm1, 2, tdm3, 2);
AudioConnection          patchCord5(tdm1, 3, tdm3, 3);
AudioConnection          patchCord6(tdm1, 4, tdm3, 4);
AudioConnection          patchCord7(tdm1, 5, tdm3, 5);
AudioConnection          patchCord8(tdm1, 6, tdm3, 6);
AudioConnection          patchCord9(tdm1, 7, tdm3, 7);
AudioConnection          patchCord10(tdm1, 8, tdm3, 8);
AudioConnection          patchCord11(tdm1, 9, tdm3, 9);
AudioConnection          patchCord12(tdm1, 10, tdm3, 10);
AudioConnection          patchCord13(tdm1, 11, tdm3, 11);
AudioConnection          patchCord14(tdm1, 12, tdm3, 12);
AudioConnection          patchCord15(tdm1, 13, tdm3, 13);
AudioConnection          patchCord16(tdm1, 14, tdm3, 14);
AudioConnection          patchCord17(tdm1, 15, tdm3, 15);
AudioControlCS42448      cs42448_1;      //xy=614,540
// GUItool: end automatically generated code



#define TFT_SCLK 13  // SCLK can also use pin 14
#define TFT_MOSI 11  // MOSI can also use pin 7
#define TFT_CS   6  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC    2  //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST   0 // RST can use any pin

#include <Adafruit_GFX.h>    // Core graphics library
#include <ST7735_t3.h> // Hardware-specific library
//#include <Adafruit_ST7735.h> // Hardware-specific library


// Option 1: use any pins but a little slower
ST7735_t3 tft = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
// Option 1: use any pins but a little slower
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
// give it a name:
int led = 13;
int sda = 18;

void setup() {
  //pinMode(led, INPUT);  
  AudioMemory(64);
  Wire.begin();  
  //SPI.setSCK  (14);
  //SPI.setMOSI (7 );
  //SPI.setMISO (12);
  
  SPI.begin();
 delay(100);
  tft.initR(INITR_GREENTAB);
  tft.setRotation(1);
  
  tft.fillScreen(ST7735_BLACK);
  Serial.begin(9600);
  Serial.println("init...");
  tft.println("init...");
  
  AudioNoInterrupts();  // disable audio library momentarily
  // put your setup code here, to run once:
  cs42448_1.setAddress(0);
  cs42448_1.enable();
  cs42448_1.volume(1);

  //cs42448_1.inputLevel(1, 15.0);
  //cs42448_1.inputLevel(2, 15.0);
  cs42448_1.inputLevel(1);
  
//  sine1.frequency(100.0);
  //sine1.amplitude(1.0);
  
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
