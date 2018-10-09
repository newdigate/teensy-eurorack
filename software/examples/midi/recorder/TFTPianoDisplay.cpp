#include "Arduino.h"
#include "TFTPianoDisplay.h"

TFTPianoDisplay::TFTPianoDisplay(Adafruit_GFX &tft, unsigned int octaves, unsigned int startOctave){
    _tft = &tft;
    _x = 5;
    _y = 24;
    _height = 32;
    _width = 128;
    _octaves = octaves;
    _startOctave = startOctave; 
    _offsetKeyZero = ( 12 * 3 ) -1; 
    _shouldUpdatePiano = true;
    
    for (unsigned int i=0; i < sizeof(_keysWhichArePressed); i++) {
      _keysWhichArePressed[i] = 0x00;
    }
}

bool TFTPianoDisplay::displayNeedsUpdating() {
  return _shouldUpdatePiano;
}

void TFTPianoDisplay::setPosition(byte x, byte y) {
    _x = x;
    _y = y;
}

void TFTPianoDisplay::keyDown(byte key) {
  byte byteNumberOfKey = key / 8;
  byte bitNumberOfKey = key % 8;
  
  //Serial.printf("ON: %d,%d ON\n", byteNumberOfKey, bitNumberOfKey);
  byte b = _keysWhichArePressed[byteNumberOfKey];
  //Serial.printf("before ON: %d,%d ::%x\n", byteNumberOfKey, bitNumberOfKey, b);
  bitSet( b, bitNumberOfKey);
  //Serial.printf("ON: %d,%d ::%x\n", byteNumberOfKey, bitNumberOfKey, b);
  _keysWhichArePressed[byteNumberOfKey] = b;
  _shouldUpdatePiano = true;
}

void TFTPianoDisplay::keyUp(byte key) {
  byte byteNumberOfKey = key / 8;
  byte bitNumberOfKey = key % 8;
  byte b = _keysWhichArePressed[byteNumberOfKey];
  //Serial.printf("before OFF: %d,%d ::%x\n", byteNumberOfKey, bitNumberOfKey, b);
  bitClear( b, bitNumberOfKey);
  _keysWhichArePressed[byteNumberOfKey] = b;
  //Serial.printf("OFF: %d,%d ::%x\n", byteNumberOfKey, bitNumberOfKey, b);
  _shouldUpdatePiano = true;
}

bool TFTPianoDisplay::isKeyPressed(byte key) {
    byte byteNumberOfKey = key / 8;
    byte bitNumberOfKey = key % 8;
    return bitRead( _keysWhichArePressed[byteNumberOfKey], bitNumberOfKey);
}

bool TFTPianoDisplay::isAnyKeyPressed(byte key) {
    byte index = key % 24;
    for (int i = 0; i < 3; i++) {
      byte transformedKey = index + (i * 24);
      byte byteNumberOfKey = transformedKey / 8;
      byte bitNumberOfKey = transformedKey % 8;
      bool keydown = bitRead( _keysWhichArePressed[byteNumberOfKey], bitNumberOfKey);
      if (keydown) return true;
    }
    return false;
}

void TFTPianoDisplay::drawPiano() {
  /*
    for (int i=0; i< 14; i++) {
      char c[] = "         ";
      itoa(keysWhichArePressed[i],c,2);
      Serial.printf("%d: %s\n", i, c);
    }
    Serial.println();
    */
    const byte b[] = {/* C */ 0, /* D */ 2, /* E */ 4, /* F */ 5, /* G */ 7, /* A */ 9, /* B */ 11 };
    //Draw the white keys on the keyboard
    for (unsigned int octave=0; octave < _octaves; octave++) { 
      for (int i=0; i<7; i++) {
        byte key = b[i] + (octave * 12);
        bool isDown = isKeyPressed(key + _offsetKeyZero);
  
        /*if (isDown)
          Serial.printf("[i=%d, i%%7 = %d, b[i%%7]=%d, DOWN]\n", i, mod, key);
        else
          Serial.printf("[i=%d, i%%7 = %d, b[i%%7]=%d, UP]\n", i, mod, key);
  */
        
        if (isDown) 
          _tft->fillRect(_x + i*5 + (octave*5*7), _y, 4, 32, ST7735_BLUE);
        else 
          _tft->fillRect(_x + i*5 + (octave*5*7), _y, 4, 32, ST7735_WHITE);     
      }
  
      const byte blackKeys[] = {/* C# */ 1, /* D# */ 3, /*Skip*/ 0, /* F# */ 6, /* G# */ 8, /* A# */ 10, /*Skip*/ 0};
      
      //Draw the black keys on the keyboard
      for (int i=0; i<6; i++){
        if ( i==2 ) continue;
        byte key = blackKeys[i] + (octave * 12);
        _tft->fillRect( _x+3 + (5*i) + (octave*5*7), _y, 3, 16, isKeyPressed(blackKeys[key] + _offsetKeyZero)? ST7735_BLUE : ST7735_BLACK);
      }
    }
    _shouldUpdatePiano = false;
}

