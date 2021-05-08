//
// Created by Moolet on 18/03/2021.
//

#ifndef TEENSYAUDIOSPISHAREDLIBRARY_OUTPUT_SPI_H
#define TEENSYAUDIOSPISHAREDLIBRARY_OUTPUT_SPI_H


#include "Arduino.h"
#include "AudioStream.h"
#include "DMAChannel.h"

class AudioInputOutputSPI : public AudioStream
{
public:
    AudioInputOutputSPI(void) : AudioStream(8, inputQueueArray) { begin(); }
    virtual void update(void);
    void begin(void);
protected:
    static audio_block_t *block_input[8];
    static audio_block_t *block_incoming[8];
    static audio_block_t *block_write[8];
    static bool update_responsibility;
    static DMAChannel dmatx;
    static DMAChannel dmarx;
    static void tx_complete_isr(void);
    static void rx_complete_isr(void);
    static void timer(void);
    static volatile uint16_t _readIndex;
    static volatile uint16_t _writeIndex;
    static volatile bool _resetReceived;
private:
    audio_block_t *inputQueueArray[8];
    static audio_block_t *prev[8];
    static volatile uint8_t rxbuf[32];
};


#endif //TEENSYAUDIOSPISHAREDLIBRARY_OUTPUT_SPI_H
