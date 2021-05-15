#ifndef TFTPROGRESSBAR_H
#define TFTPROGRESSBAR_H

#include "Arduino.h"
#include <ST7735_t3.h> // Hardware-specific library

class TFTProgressBar {
public:
  TFTProgressBar(ST7735_t3 &tft) : _tft(tft) {
    
  }

  void drawProgress(unsigned long numerator, unsigned long denominator) {
    unsigned long x = ((numerator/1000) * 128) / (denominator/1000);
    if (x != _lastProgress) {
      Serial.printf("%d -- %d   %d\n", x, numerator/1000, denominator/1000);
      _tft.drawLine( 0, 120, x, 120, 0xFFFF);
      _tft.drawLine( x+1, 120, 127, 120, 0x0000);
      _lastProgress = x;
    }
  }
 
  
private: 
  unsigned _lastProgress = 0;
    ST7735_t3 &_tft;
 
};

#endif
