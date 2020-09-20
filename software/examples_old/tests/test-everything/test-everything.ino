#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <ST7735_t3.h> // Hardware-specific library
#include "AD5754.h"
#include "ScopeView.h"

// GUItool: begin automatically generated code
AudioInputTDM            tdm1;           //xy=193,432
AudioRecordQueue         queue1;         //xy=334,55
AudioRecordQueue         queue2;         //xy=351,93
AudioRecordQueue         queue3;         //xy=373,133
AudioRecordQueue         queue4;         //xy=382,188
AudioSynthWaveformSine   sine1;          //xy=422,496
AudioRecordQueue         queue5;         //xy=431,240
AudioSynthWaveformSine   sine2;          //xy=437,555
AudioRecordQueue         queue6;         //xy=443,301
AudioOutputTDM           tdm3;           //xy=697,442
AudioConnection          patchCord1(tdm1, 0, tdm3, 10);
AudioConnection          patchCord2(tdm1, 0, queue1, 0);
AudioConnection          patchCord3(tdm1, 2, tdm3, 8);
AudioConnection          patchCord4(tdm1, 2, queue2, 0);
AudioConnection          patchCord5(tdm1, 4, tdm3, 4);
AudioConnection          patchCord6(tdm1, 4, queue3, 0);
AudioConnection          patchCord7(tdm1, 6, tdm3, 6);
AudioConnection          patchCord8(tdm1, 6, queue4, 0);
AudioConnection          patchCord9(tdm1, 8, tdm3, 0);
AudioConnection          patchCord10(tdm1, 8, queue5, 0);
AudioConnection          patchCord11(tdm1, 10, tdm3, 2);
AudioConnection          patchCord12(tdm1, 10, queue6, 0);
AudioConnection          patchCord13(sine1, 0, tdm3, 12);
AudioConnection          patchCord14(sine2, 0, tdm3, 14);
AudioControlCS42448      cs42448_1;      //xy=391,647
// GUItool: end automatically generated code



#define TFT_SCLK 13  // SCLK can also use pin 14
#define TFT_MOSI 11  // MOSI can also use pin 7
#define TFT_CS   6  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC    2  //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST   0 // RST can use any pin
#define SD_CS     4  // CS for SD card, can use any pin
ST7735_t3 TFT = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

#define SCALE_FACTOR 0.000152587890625              // 10/(2^16) = 0.000152587890625

#define BUSY 3
#define RESET 4
#define START_CONVERSION 5
#define CHIP_SELECT 10
#define MISO 12
#define MOSI 11
#define LED 13
#define TOTAL_RAW_BYTES 16

#define TFT_CS 6


int bytesToRead = TOTAL_RAW_BYTES;  
byte raw[TOTAL_RAW_BYTES];  
uint16_t parsed[8];
int x = 0;
uint16_t oldpos[8] = {0,0,0,0,0,0,0,0};
int16_t colors[8] = {ST7735_GREEN,ST7735_RED,ST7735_BLUE,ST7735_CYAN,ST7735_MAGENTA,ST7735_YELLOW,0x00AA,ST7735_WHITE};

int resetCount = 0;
int16_t cvlastbuffer[8][128];
int16_t cvbuffer[8][128];

ScopeView scopeView1 = ScopeView(TFT, [&] (){ return queue1.readBuffer(); }, colors[0], (int16_t)ST7735_BLACK, 64);
ScopeView scopeView2 = ScopeView(TFT, [&] (){ return queue2.readBuffer(); }, colors[1], (int16_t)ST7735_BLACK, 64);
ScopeView scopeView3 = ScopeView(TFT, [&] (){ return queue3.readBuffer(); }, colors[2], (int16_t)ST7735_BLACK, 64);
ScopeView scopeView4 = ScopeView(TFT, [&] (){ return queue4.readBuffer(); }, colors[3], (int16_t)ST7735_BLACK, 64);
ScopeView scopeView5 = ScopeView(TFT, [&] (){ return queue5.readBuffer(); }, colors[4], (int16_t)ST7735_BLACK, 64);
ScopeView scopeView6 = ScopeView(TFT, [&] (){ return queue6.readBuffer(); }, colors[5], (int16_t)ST7735_BLACK, 64);

ScopeView scopeViewCV1 = ScopeView(TFT, [&] (){ return cvlastbuffer[0]; }, colors[1], (int16_t)ST7735_BLACK, 0);
ScopeView scopeViewCV2 = ScopeView(TFT, [&] (){ return cvlastbuffer[1]; }, colors[2], (int16_t)ST7735_BLACK, 0);
ScopeView scopeViewCV3 = ScopeView(TFT, [&] (){ return cvlastbuffer[2]; }, colors[3], (int16_t)ST7735_BLACK, 0);
ScopeView scopeViewCV4 = ScopeView(TFT, [&] (){ return cvlastbuffer[3]; }, colors[4], (int16_t)ST7735_BLACK, 0);
ScopeView scopeViewCV5 = ScopeView(TFT, [&] (){ return cvlastbuffer[4]; }, colors[5], (int16_t)ST7735_BLACK, 0);
ScopeView scopeViewCV6 = ScopeView(TFT, [&] (){ return cvlastbuffer[5]; }, colors[6], (int16_t)ST7735_BLACK, 0);
ScopeView scopeViewCV7 = ScopeView(TFT, [&] (){ return cvlastbuffer[6]; }, colors[7], (int16_t)ST7735_BLACK, 0);
ScopeView scopeViewCV8 = ScopeView(TFT, [&] (){ return cvlastbuffer[7]; }, colors[8], (int16_t)ST7735_BLACK, 0);

uint16_t control_voltage1 = 0x0000;

const ScopeView* scopes[] = {&scopeView1, &scopeView2, &scopeView3, &scopeView4, &scopeView5, &scopeView6};
const ScopeView* cvscopes[] = {&scopeViewCV1, &scopeViewCV2, &scopeViewCV3, &scopeViewCV4, &scopeViewCV5, &scopeViewCV6, &scopeViewCV7, &scopeViewCV8};


AudioRecordQueue* queues[6] = {&queue1, &queue2, &queue3, &queue4, &queue5, &queue6};

void setup() {  
  
  AudioMemory(100);
  SPI.begin();
  pinMode(DA_SYNC, OUTPUT);
  digitalWrite(DA_SYNC, HIGH); 

  
  pinMode(BUSY, INPUT);
  pinMode(RESET, OUTPUT);
  pinMode(TFT_CS, OUTPUT);
  pinMode(START_CONVERSION, OUTPUT);
  pinMode(CHIP_SELECT, OUTPUT);

  Serial.begin(115200);

  //TFT.begin();
  TFT.initR(INITR_144GREENTAB);
  TFT.setRotation(3);
  TFT.fillScreen(ST7735_BLACK);

  //digitalWrite(TFT_CS, HIGH); 

  digitalWrite(START_CONVERSION, HIGH);  
  digitalWrite(CHIP_SELECT, HIGH);
  digitalWrite(RESET, HIGH);
  delay(100);
  digitalWrite(RESET, LOW);
  delay(100);

  AD5754R_SetRegisterValue(AD5754R_REG_POWER_CONTROL,0x00,0x0f);
  //AD5754R_SetPower(AD5754R_DAC_ALL, 1);
  AD5754R_ControlFunction(AD5754R_SDO_DISABLE, 1);
  AD5754R_RangeSelect(AD5754R_DAC_ALL, AD5754R_UNIPOLAR_10_RANGE);
  AD5754R_LoadDac(AD5754R_DAC_ALL, 0xffff);



  AudioNoInterrupts();  // disable audio library momentarily
  cs42448_1.enable();
  cs42448_1.volume(1);
  cs42448_1.inputLevel(1);
  AudioInterrupts();    // enable, both tones will start together
  delay(50);
  queue1.begin();
  queue2.begin();
  queue3.begin();
  queue4.begin();
  queue5.begin();
  queue6.begin();
  sine1.amplitude(0.25f);
  sine1.frequency(440);
  
  sine2.amplitude(0.25);
  sine2.frequency(88);  
}



void loop() {  

  for (int i=0; i<6; i++) {
    AudioRecordQueue *currentQueue = queues[i];
    if ( currentQueue->available() ) {    
      if (scopes[i]->oscilliscope_x < 128) {
        // completely discard record buffers until x location >= 100
        while (currentQueue->available()) {
          currentQueue->readBuffer();     
          currentQueue->freeBuffer();   
        }
      } else  {
        while (currentQueue->available() > 1) {
          currentQueue->readBuffer();     
          currentQueue->freeBuffer();   
        }
        scopes[i]->takeBuffer();
        currentQueue->freeBuffer();
      }
    }
    scopes[i]->drawScope(); 
  }

  control_voltage1+=1;
  AD5754R_LoadDac(AD5754R_DAC_ALL, control_voltage1);
  
  int i;
  //SPI.begin();
  digitalWrite(START_CONVERSION, LOW);
  //Serial.print("L");
  delayMicroseconds(100);
  digitalWrite(START_CONVERSION, HIGH);
  //Serial.print("H");
    
  while (digitalRead(BUSY) == HIGH) {
    // wait for conversion to complete
    delayMicroseconds(1);
  }
  SPI.beginTransaction(_spiSettings);
  digitalWrite(CHIP_SELECT, LOW);
  while (bytesToRead > 0) {
    raw[TOTAL_RAW_BYTES - bytesToRead] = SPI.transfer(0x00);
    bytesToRead--;
  }
  digitalWrite(CHIP_SELECT, HIGH);
  SPI.endTransaction(); 
  bytesToRead = TOTAL_RAW_BYTES;

  parseRawBytes();
  x++;
  if (x < 126) {
    for(i=0; i<8; i++) {
      if (parsed[i] > 0xffe0)
        parsed[i] = 0;
      uint16_t value = parsed[i];    
      cvbuffer[i][x] = value;
    } 
  } else {
    for (int i=0; i<8; i++) {
      memcpy(cvlastbuffer[i], cvbuffer[i], 256); 
      cvscopes[i]->takeBuffer();     
    }
    x = 0;   
  }   

  for (int i=0; i<8; i++) { 
    cvscopes[i]->drawScope();  
  } 
}

void parseRawBytes() {
  parsed[0] = (raw[0] << 8) + raw[1];
  parsed[1] = (raw[2] << 8) + raw[3];
  parsed[2] = (raw[4] << 8) + raw[5];
  parsed[3] = (raw[6] << 8) + raw[7];
  parsed[4] = (raw[8] << 8) + raw[9];
  parsed[5] = (raw[10] << 8) + raw[11];
  parsed[6] = (raw[12] << 8) + raw[13];
  parsed[7] = (raw[14] << 8) + raw[15];
}
