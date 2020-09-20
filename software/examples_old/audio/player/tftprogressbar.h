#ifndef TFTPROGRESSBAR_H
#define TFTPROGRESSBAR_H

#include "Arduino.h"
#include <Adafruit_GFX.h> 

class TFTProgressBar {
public:
  TFTProgressBar(Adafruit_GFX &tft) : _tft(tft) {
    
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
  Adafruit_GFX &_tft;
 
};

#endif
