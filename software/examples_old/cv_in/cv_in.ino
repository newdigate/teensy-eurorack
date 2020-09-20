#include <SPI.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <ST7735_t3.h> // Hardware-specific library

#define TFT_SCLK 13  // SCLK can also use pin 14
#define TFT_MOSI 11  // MOSI can also use pin 7
#define TFT_CS   6  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC    2  //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST   0 // RST can use any pin
#define SD_CS     4  // CS for SD card, can use any pin
ST7735_t3 TFT = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

#define SCALE_FACTOR 0.000152587890625

// 10/(2^16) = 0.000152587890625

#define BUSY 3
#define RESET 4
#define START_CONVERSION 5
#define CHIP_SELECT 10
#define MISO 12
#define MOSI 11
#define LED 13
#define TOTAL_RAW_BYTES 16

#define TFT_CS 6
#define DA_SYNC 16

SPISettings _spiSettings;

int bytesToRead = TOTAL_RAW_BYTES;  
byte raw[TOTAL_RAW_BYTES];  
uint16_t parsed[8];
int x = 0;
uint16_t oldpos[8] = {0,0,0,0,0,0,0,0};
int16_t colors[8] = {ST7735_GREEN,ST7735_RED,ST7735_BLUE,ST7735_CYAN,ST7735_MAGENTA,ST7735_YELLOW,0x00AA,ST7735_WHITE};

void setup() {  
  pinMode(DA_SYNC, OUTPUT);
  digitalWrite(DA_SYNC, HIGH); 
  
  pinMode(BUSY, INPUT);
  pinMode(RESET, OUTPUT);
  pinMode(TFT_CS, OUTPUT);
  pinMode(START_CONVERSION, OUTPUT);
  pinMode(CHIP_SELECT, OUTPUT);
  //pinMode(MISO, INPUT);

  Serial.begin(115200);
/*  while (!Serial) {
    delay(100);
  }
  Serial.println("hello"); */
/*  SPI.setSCK(13);
  SPI.setMISO(MISO);
  SPI.setMOSI(MOSI); */


  //TFT.begin();
  TFT.initR(INITR_144GREENTAB);
  TFT.setRotation(3);
  TFT.fillScreen(ST7735_BLACK);

  //digitalWrite(TFT_CS, HIGH); 
  SPI.begin();
  digitalWrite(START_CONVERSION, HIGH);  
  digitalWrite(CHIP_SELECT, HIGH);
  digitalWrite(RESET, HIGH);
  delay(100);
  digitalWrite(RESET, LOW);
  delay(100);
}

int resetCount = 0;
void loop() {  
  int i;

  digitalWrite(START_CONVERSION, LOW);

  delayMicroseconds(100);
  digitalWrite(START_CONVERSION, HIGH);
    
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



  for(i=0; i<8; i++) {

    if (parsed[i] > 0xffe0)
      parsed[i] = 0;
    uint8_t value = parsed[i] >> 8;
    TFT.drawLine(x, oldpos[i], x+1, value, colors[i]);
    oldpos[i] = value;
  }

  x++;
  if (x > 126) {
    x = 0;
    TFT.fillScreen(ST7735_BLACK);
  }
  
  //delay(100);
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
