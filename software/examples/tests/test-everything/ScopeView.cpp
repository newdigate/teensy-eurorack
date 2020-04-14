#include "ScopeView.h"

void ScopeView::drawScope() {
    oscilliscope_x = oscilliscope_x + 1;
    if (oscilliscope_x > 127) {
        return;
    }

    _tft->drawLine(oscilliscope_x, _yOffset + (lastbuffer[oscilliscope_x-1] >> 8), oscilliscope_x + 1, _yOffset + (lastbuffer[oscilliscope_x] >> 8),  _backgroundColor);
    _tft->drawLine(oscilliscope_x, _yOffset + (buffer[oscilliscope_x-1] >> 8),     oscilliscope_x + 1, _yOffset + (buffer[oscilliscope_x] >> 8),      _color);
}

void ScopeView::takeBuffer() {
    if (_getBufferFn != nullptr) {
      memcpy(lastbuffer, buffer, 256);
      memcpy(buffer, _getBufferFn(), 256);
      oscilliscope_x = 0;
    }
}
