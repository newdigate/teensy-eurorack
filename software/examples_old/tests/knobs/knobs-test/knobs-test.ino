// Target micro-controller: Teensy 4.0
// interface with breakout board via serial RX/TX
// display incomming serial on TFT display

#define TFT_SCLK 13  // SCLK can also use pin 14
#define TFT_MOSI 11  // MOSI can also use pin 7
#define TFT_CS   6  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC    2  //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST   0 // RST can use any pin
#define SD_CS     4  // CS for SD card, can use any pin

#include <Adafruit_GFX.h>    // Core graphics library
#include <ST7735_t3.h> // Hardware-specific library
#include <ST7789_t3.h> // Hardware-specific library
#include <SPI.h>
#include <MIDI.h>

// Option 1: use any pins but a little slower
// Note: code will detect if specified pins are the hardware SPI pins
//       and will use hardware SPI if appropriate
// For 1.44" and 1.8" TFT with ST7735 use
ST7735_t3 TFT = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
MIDI_CREATE_INSTANCE(HardwareSerial, Serial3,    MIDI);
// ----------------------------------------------
// setup
// ----------------------------------------------
void setup() {
  Serial.begin(9600);
  MIDI.begin();   
  TFT.initR(INITR_144GREENTAB);
  TFT.setRotation(3);
  TFT.fillScreen(ST7735_BLACK);
}

int ypos = 0;

void loop() {

  TFT.setTextSize(0);
  if (MIDI.read())                // Is there a MIDI message incoming ?
 {
      TFT.printf("%2x %2x %2x %2x\n", MIDI.getType(), MIDI.getChannel(), MIDI.getData1(), MIDI.getData2() );
      ypos ++;     
  }

  
  // read from port 0, send to port 1:
  while (Serial.available()) {
    int inByte = Serial.read();
    Serial3.write(inByte);
  }
/*
  // read from port 0, send to port 1:
  while (Serial3.available()) {
    char inByte = Serial3.read();
    Serial.write(inByte);
    TFT.print(inByte);
    if (inByte == '\n') ypos ++;    
  }
*/
  if (ypos > 15) {
      TFT.fillScreen(ST7735_BLACK);
      TFT.setCursor(0,0);
      ypos = 0;
  }
}
