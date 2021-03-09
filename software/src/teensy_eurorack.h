//
// Created by Moolet on 09/03/2021.
//
#ifndef TEENSY_EURORACK_TEENSY_EURORACK_H
#define TEENSY_EURORACK_TEENSY_EURORACK_H

#define TFT_SCLK 13  // SCLK can also use pin 14
#define TFT_MOSI 11  // MOSI can also use pin 7
#define TFT_CS   6  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC    2  //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST   -1 // RST can use any pin

#endif //TEENSY_EURORACK_TEENSY_EURORACK_H