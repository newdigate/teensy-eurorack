#include <MIDI.h>
#include <ST7735_t3.h> // Hardware-specific library
#include "teensy_eurorack.h"

ST7735_t3 tft = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI)

void setup()
{
  Serial.begin(115200);

  tft.initR(INITR_144GREENTAB); // initialize a ST7735R chip, green tab
  tft.setRotation(3);
  tft.setTextWrap(true);
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_BLUE);   
  tft.println("midi test...");
  tft.setTextColor(ST7735_WHITE);   
   
  MIDI.begin(MIDI_CHANNEL_OMNI);                      
}

uint8_t cursor_y = 0;

void loop()
{
  MIDI.sendNoteOn(60, 128, 01);
  delay(1000);
  MIDI.sendNoteOff(60, 128, 01);
  delay(1000);
}
