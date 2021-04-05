//
// Created by Moolet on 09/03/2021.
//
#ifndef TEENSY_EURORACK_TEENSY_EURORACK_H
#define TEENSY_EURORACK_TEENSY_EURORACK_H

#include "teensy_eurorack_pins.h"

#define TFT_SCLK 13     // SCLK can also use pin 14
#define TFT_MOSI 11     // MOSI can also use pin 7
#define TFT_CS   6      // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC    2     //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST   -1    // RST can use any pin

#define DA_CLK 27
#define DA_MOSI 26
#define DA_MISO 39
#define DA_SYNC 38
#define AD7607_BUSY 3
#define AD7607_START_CONVERSION 5
#define AD7607_CHIP_SELECT 36
#define AD7607_RESET 35
#define AD7607_RANGE_SELECT 37
#define LRCLK_CPY 40

unsigned memfree(void) {
    extern unsigned long _ebss;
    extern unsigned long _sdata;
    extern unsigned long _estack;
    const unsigned DTCM_START = 0x20000000UL;
    unsigned dtcm = (unsigned)&_estack - DTCM_START;
    unsigned stackinuse = (unsigned) &_estack -  (unsigned) __builtin_frame_address(0);
    unsigned varsinuse = (unsigned)&_ebss - (unsigned)&_sdata;
    unsigned freemem = dtcm - (stackinuse + varsinuse);
    return freemem;
}

#endif //TEENSY_EURORACK_TEENSY_EURORACK_H