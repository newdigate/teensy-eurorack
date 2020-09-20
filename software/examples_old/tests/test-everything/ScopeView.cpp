//
// Created by Nicholas Newdigate on 13/04/2020.
//

#ifndef ARDUINO_MIDI_WRITER_SCOPEVIEW_H
#define ARDUINO_MIDI_WRITER_SCOPEVIEW_H

#include "Arduino.h"
#include <ST7735_t3.h> // Hardware-specific library


#undef swap
#include <functional>
using namespace std;
#undef swap
#define swap(a, b) { typeof(a) t = a; a = b; b = t; }

class ScopeView {
public:
    inline ScopeView(
            ST7735_t3 &tft,
            function<int16_t*()> getBufferFn,
            int16_t color,
            int16_t backgroundColor,
            int8_t yOffset) :
            _tft(&tft),
            _getBufferFn(getBufferFn),
            _backgroundColor(backgroundColor),
            _color(color),
            _yOffset(yOffset){
    };

    void drawScope();
    void takeBuffer();
    uint16_t oscilliscope_x = 0;
    
private:
    ST7735_t3 *_tft;

    int16_t buffer[128];
    int16_t lastbuffer[128];
    int16_t _backgroundColor;
    int16_t _color;
    int8_t _yOffset;

    function<int16_t*()> _getBufferFn;
};



#endif //ARDUINO_MIDI_WRITER_SCOPEVIEW_H
