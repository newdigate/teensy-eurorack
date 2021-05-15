//
// Created by Moolet on 18/03/2021.
//

#include "input_output_spi.h"

#include <Arduino.h>
#include "SPI.h"
#if !defined(KINETISL)

#include "memcpy_audio.h"
#include "utility/imxrt_hw.h"
#define AD7607_BUSY 3
#define AD7607_START_CONVERSION 5
#define AD7607_CHIP_SELECT 36
#define AD7607_RESET 35
#define AD7607_RANGE_SELECT 37
#define DA_SYNC 38
#define MOSI_PIN 26
#define MISO_PIN 39
#define SCK_PIN 27
#define LRCLK_CPY 40

/* AD5754R Register Map */
#define AD5754R_REG_RANGE_SELECT    0x01 // Output range select register
/* AD5754R Channel Address */
#define AD5754R_DAC_ALL             0x04 // All four DACs
/* AD5754R Range Bits */
#define AD5754R_BIPOLAR_10_RANGE    0x04 // -10...+10(V)

audio_block_t * AudioInputOutputSPI::block_input[8] = {
        nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
};
bool AudioInputOutputSPI::update_responsibility = false;
DMAChannel AudioInputOutputSPI::dmatx(false);
DMAChannel AudioInputOutputSPI::dmarx(false);
//DMAMEM
__attribute__((aligned(32)))
uint32_t zeros[AUDIO_BLOCK_SAMPLES/2];
//DMAMEM
__attribute__((aligned(32)))
uint8_t tdm_tx_buffer[32 * 4];

volatile uint16_t AudioInputOutputSPI::_readIndex = 0;
volatile uint16_t AudioInputOutputSPI::_writeIndex = 0;

volatile bool AudioInputOutputSPI::_resetReceived = false;
audio_block_t *AudioInputOutputSPI::prev[8] = {
        nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
};
//DMAMEM
__attribute__((aligned(32)))
volatile uint8_t AudioInputOutputSPI::rxbuf[32] = {0};
audio_block_t * AudioInputOutputSPI::block_incoming[8] = {
        nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
};
audio_block_t * AudioInputOutputSPI::block_write[8] = {
        nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
};
static const uint32_t zero_level = (0xFFFF / 2)+1;
void setClockDivider_noInline(uint32_t clk)
{
    static const uint32_t clk_sel[4] = {
            664615384,  // PLL3 PFD1
            720000000,  // PLL3 PFD0
            528000000,  // PLL2
            396000000}; // PLL2 PFD2

    uint32_t cbcmr = CCM_CBCMR;
    uint32_t clkhz = clk_sel[(cbcmr >> 4) & 0x03] / (((cbcmr >> 26 ) & 0x07 ) + 1);  // LPSPI peripheral clock

    uint32_t d, div;
    d = clk ? clkhz/clk : clkhz;

    if (d && clkhz/d > clk) d++;
    if (d > 257) d= 257;  // max div
    if (d > 2) {
        div = d-2;
    } else {
        div =0;
    }

    uint32_t ccr = LPSPI_CCR_SCKDIV(div) | LPSPI_CCR_DBT(div/2) | LPSPI_CCR_PCSSCK(div/2);

    //Serial.printf("SPI.setClockDivider_noInline CCR:%x TCR:%x\n", _ccr, port().TCR);
    IMXRT_LPSPI3_S.CR = 0;
    IMXRT_LPSPI3_S.CFGR1 = LPSPI_CFGR1_MASTER | LPSPI_CFGR1_SAMPLE;
    IMXRT_LPSPI3_S.CCR = ccr;
    IMXRT_LPSPI3_S.CR = LPSPI_CR_MEN;
}

void AudioInputOutputSPI::begin(void)
{

    Serial.begin(9600);

    pinMode(            DA_SYNC,                 OUTPUT);
    digitalWrite(       DA_SYNC,                 HIGH);

    pinMode(            AD7607_CHIP_SELECT,      OUTPUT);
    digitalWriteFast(   AD7607_CHIP_SELECT,      HIGH);

    pinMode(            AD7607_START_CONVERSION, OUTPUT);
    digitalWriteFast(   AD7607_START_CONVERSION, HIGH);

    pinMode(            AD7607_RESET,            OUTPUT);
    digitalWrite(       AD7607_RESET,            LOW);

    pinMode(            AD7607_RANGE_SELECT,     OUTPUT);
    digitalWrite(       AD7607_RANGE_SELECT,     HIGH);

    pinMode(            LRCLK_CPY,               INPUT);
    delayMicroseconds(10);

    SPI1.begin();
    digitalWrite(DA_SYNC, LOW);
    SPI1.beginTransaction(SPISettings());
    uint8_t configureDac[] = {
            0,
            0,
            0x10,
            0x00,
            0x0f,
            0x10,
            0x00,
            0x0f
    };
    SPI1.transfer(configureDac, 8);
    SPI1.endTransaction();
    digitalWrite(DA_SYNC, HIGH);
    delayMicroseconds(10);


    // Set voltage range for DAC0, DAC1;
    digitalWrite(DA_SYNC, LOW);
    uint8_t configureDacVoltageRange[] = {
            0,
            0,
            (AD5754R_REG_RANGE_SELECT << 3) + AD5754R_DAC_ALL,
            0x00,
            AD5754R_BIPOLAR_10_RANGE,
            (AD5754R_REG_RANGE_SELECT << 3) + AD5754R_DAC_ALL,
            0x00,
            AD5754R_BIPOLAR_10_RANGE
    };
    SPI1.beginTransaction(SPISettings());
    SPI1.transfer(configureDacVoltageRange, 8);
    SPI1.endTransaction();
    digitalWrite(DA_SYNC, HIGH);
    delayMicroseconds(10);

    for (int i=0; i < 8; i++) {
        block_input[i] = nullptr;
    }
    memset(zeros, 0, sizeof(zeros));
    memset(tdm_tx_buffer, 0, sizeof(tdm_tx_buffer));

    dmatx.begin(true); // Allocate the DMA channel first
    dmatx.disable();
    dmatx.sourceBuffer(tdm_tx_buffer, 32);
    dmatx.transferSize(4);
    dmatx.transferCount(8);
    dmatx.destination((volatile uint32_t &)IMXRT_LPSPI3_S.TDR);
    dmatx.triggerAtHardwareEvent(DMAMUX_SOURCE_LPSPI3_TX);
    dmatx.disableOnCompletion();
    dmatx.interruptAtCompletion();
    dmatx.attachInterrupt(tx_complete_isr);


    dmarx.begin(true); // allocate the DMA channel first
    dmarx.disable();
    dmarx.destinationBuffer(rxbuf, 32);
    dmarx.source((volatile uint32_t &)IMXRT_LPSPI3_S.RDR);
    dmarx.transferSize(4);
    dmarx.transferCount(8);
    dmarx.triggerAtHardwareEvent(DMAMUX_SOURCE_LPSPI3_RX);
    dmarx.disableOnCompletion();
    dmarx.attachInterrupt(rx_complete_isr);
    dmarx.interruptAtCompletion();

    for (uint8_t count=0; count<4; count++) {
        tdm_tx_buffer[(count*8)+3] = 0;
        tdm_tx_buffer[(count*8)+2] = 0;

        tdm_tx_buffer[(count*8)+1] = count;                     //DAC0, channel=count
        tdm_tx_buffer[(count*8)+0] = 0xFF;//(block_input[count*2] != NULL) ? block_input[count*2]->data[_readIndex] >> 8 : zero_level;
        tdm_tx_buffer[(count*8)+7] = 0xFF;//(block_input[count*2] != NULL) ? block_input[count*2]->data[_readIndex] & 0xff : zero_level;

        tdm_tx_buffer[(count*8)+6] = count;                     //DAC1, channel=count
        tdm_tx_buffer[(count*8)+5] = 0xFF;//(block_input[count*2+1] != NULL) ? block_input[count*2+1]->data[_readIndex] >> 8 : zero_level;
        tdm_tx_buffer[(count*8)+4] = 0xFF;//(block_input[count*2+1] != NULL) ? block_input[count*2+1]->data[_readIndex] & 0xff : zero_level;
        //DAC1, channel=count
    }

    SPI1.setSCK(SCK_PIN);
    SPI1.setMOSI(MOSI_PIN);
    SPI1.setMISO(MISO_PIN);
    SPI1.setCS(DA_SYNC);
    SPI1.begin();

    IMXRT_LPSPI3_S.TCR = (IMXRT_LPSPI3_S.TCR & ~(LPSPI_TCR_FRAMESZ(7))) | LPSPI_TCR_FRAMESZ(63) ;  // Change framesize to 64 bits
    setClockDivider_noInline(30000000);

    digitalWriteFast(AD7607_START_CONVERSION, LOW);
    digitalWriteFast(AD7607_START_CONVERSION, HIGH);

    attachInterrupt(digitalPinToInterrupt(LRCLK_CPY),timer,RISING);

    // https://forum.pjrc.com/threads/65229-Setting-up-custom-I2S-communication
    //attachInterruptVector(IRQ_SAI1, timer);
    //NVIC_ENABLE_IRQ(IRQ_SAI1);
    //I2S1_TCSR |= 1<<12;  // start generating TX FIFO interrupts

    NVIC_SET_PRIORITY(IRQ_LPSPI3, 5);
    NVIC_SET_PRIORITY(IRQ_DMA_CH0 + dmatx.channel, 10);
    NVIC_SET_PRIORITY(IRQ_DMA_CH0 + dmarx.channel, 2);
    NVIC_SET_PRIORITY(IRQ_GPIO6789, 1);

    for (int i = 0; i < 8; i++) {
        block_write[i] = allocate();
        if (block_write[i] == nullptr) {
            for (int j = 0; j < i; j++) {
                release(block_write[j]);
            }
            //memset(new_block, 0, sizeof(new_block));
            break;
        }
    }
}

void AudioInputOutputSPI::rx_complete_isr(void) {

    dmarx.clearInterrupt();

    for (int i = 0; i < 8; i++) {
        if (block_write[i] != NULL) {
            block_write[i]->data[_writeIndex] = ((rxbuf[i*2+1] << 8) + rxbuf[i*2]);
        }
    }
    _writeIndex++;
    if (_writeIndex == 128) {
        memcpy(block_incoming, block_write, sizeof(block_incoming));
        //for (int i=0; 0 < 8; i++)
        //  block_incoming[i] = block_write[i];

        audio_block_t *new_block[8];
        // allocate 8 new blocks.  If any fails, allocate none
        for (int i = 0; i < 8; i++) {
            new_block[i] = allocate();
            if (new_block[i] == nullptr) {
                for (int j = 0; j < i; j++) {
                    release(new_block[j]);
                }
                memset(new_block, 0, sizeof(new_block));
                break;
            }
        }
//        __disable_irq();
        memcpy(block_write, new_block, sizeof(block_write));
        _writeIndex = 0;
//        __enable_irq();
    }
    digitalWrite(AD7607_START_CONVERSION, LOW);
    digitalWrite(AD7607_START_CONVERSION, HIGH);
    dmarx.TCD->SOFF = 0;
}

void AudioInputOutputSPI::tx_complete_isr(void)
{
    digitalWriteFast(AD7607_CHIP_SELECT, HIGH);
    dmatx.clearInterrupt();
    //while (IMXRT_LPSPI3_S.FSR & 0x1f);//FIFO Status register: wait until fifo is complete
    while (IMXRT_LPSPI3_S.SR & LPSPI_SR_MBF); //Status Register: wait until Module Busy flag is cleared
    //delayNanoseconds(20);
    _readIndex++;
    if (_readIndex >= 128 && _resetReceived) {
        _readIndex = 0;
        for (unsigned int i=0; i < 8; i++) {
            if (prev[i]) {
                release(prev[i]);
                prev[i] = nullptr;
            }
        }

        _resetReceived = false;

    }
}


void AudioInputOutputSPI::update(void)
{

    unsigned int i;

    audio_block_t *out_block[8];

    __disable_irq();
    memcpy(out_block, block_incoming, sizeof(out_block));
    for (i=0; i < 8; i++) {
        prev[i] = block_input[i];
        block_input[i] = receiveReadOnly(i);
    }
    _resetReceived = true;
    __enable_irq();

    if (out_block[0] != nullptr) {
        // if we got 1 block, all 16 are filled
        for (i = 0; i < 8; i++) {
            transmit(out_block[i], i);
            release(out_block[i]);
        }
    }

/*
    for (i=0; i < 8; i++) {
        if (prev[i]) release(prev[i]);
    }
*/

}

void AudioInputOutputSPI::timer(void) {

    const uint16_t readIndex = _readIndex;
    if (readIndex < 128) {

        for (uint8_t count = 0; count < 4; count++) {
            //DAC0, channel=count
            uint8_t doubleCount = count * 2;
            audio_block_t *block = (_resetReceived) ? prev[doubleCount] : block_input[doubleCount];
            uint16_t value = (block != NULL) ? block->data[readIndex] + zero_level : zero_level;
            tdm_tx_buffer[(count * 8) + 0] = value >> 8;
            tdm_tx_buffer[(count * 8) + 7] = value & 0xff;
            //tdm_tx_buffer[(count * 8) + 0] = readIndex >> 8;
            //tdm_tx_buffer[(count * 8) + 7] = readIndex & 0xff;

            //DAC1, channel=count
            uint8_t doubleCountPlusOne = count * 2 + 1;
            audio_block_t *block2 = (_resetReceived) ? prev[doubleCountPlusOne] : block_input[doubleCountPlusOne];
            uint16_t value2 = (block2 != NULL) ? block2->data[readIndex] + zero_level : zero_level;
            tdm_tx_buffer[(count * 8) + 5] = value2 >> 8;
            tdm_tx_buffer[(count * 8) + 4] = value2 & 0xff;
            //tdm_tx_buffer[(count * 8) + 5] = readIndex >> 8;
            //tdm_tx_buffer[(count * 8) + 4] = readIndex & 0xff;
            //DAC1, channel=count
        }

        //IMXRT_LPSPI3_S.TCR = (IMXRT_LPSPI3_S.TCR & ~(LPSPI_TCR_FRAMESZ(7))) | LPSPI_TCR_FRAMESZ(63);  // Change framesize to 48 bits
        //IMXRT_LPSPI3_S.FCR = 0;
        IMXRT_LPSPI3_S.DER = LPSPI_DER_TDDE | LPSPI_DER_RDDE;        //DMA Enable register: enable DMA on TX
        IMXRT_LPSPI3_S.SR = 0x3f00;                 // status register: clear out all of the other status...

        dmarx.enable();
        dmatx.enable();
        digitalWriteFast(AD7607_CHIP_SELECT, LOW);
    }


}

#endif