#include <MIDI.h>
#include <ST7735_t3.h> // Hardware-specific library
#include "teensy_eurorack.h"

ST7735_t3 tft = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI)

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
    tft.printf("+ %02x %02x %02x\n", channel, pitch, velocity);
    tft.updateScreen();
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
    tft.printf("- %02x %02x %02x\n", channel, pitch, velocity);
    tft.updateScreen();
}

void setup()
{  
  Serial.begin(115200);

  tft.initR(INITR_144GREENTAB); // initialize a ST7735R chip, green tab
  tft.setRotation(3);
  tft.useFrameBuffer(true);
  tft.fillScreen(ST7735_BLACK);
  //tft.updateScreenAsync(true);
  
  //tft.setTextWrap(true);
  tft.enableScroll();
  tft.setScrollBackgroundColor(ST7735_BLACK);
  tft.setScrollTextArea(0,0,120,120);

  tft.setCursor(0, 0);
  tft.setTextColor(ST7735_BLUE);   
  tft.println("midi test...");
  tft.setTextColor(ST7735_WHITE);   
   
  MIDI.setHandleNoteOn(handleNoteOn);  
  MIDI.setHandleNoteOff(handleNoteOff);
  MIDI.begin(MIDI_CHANNEL_OMNI);   
  //pinMode(0, INPUT_PULLUP);                   
}

uint8_t cursor_y = 0;
uint32_t count = 0;

void loop()
{
  MIDI.read();

  count++;
  if (count % 2000 == 0) {
    MIDI.sendNoteOn(60, 127, 01);
  } else if (count % 2000 == 1000) {
    MIDI.sendNoteOff(60, 127, 01);
  }
  //delay(1);
  if (count % 500 == 0) 
    tft.updateScreen();
}

