//
// Created by Moolet on 09/03/2021.
//
#ifndef TEENSY_EURORACK_AD5754_H
#define TEENSY_EURORACK_AD5754_H

#include "teensy_eurorack.h"

/* AD5754R Register Map */
#define AD5754R_REG_DAC             0x00 // DAC register
#define AD5754R_REG_RANGE_SELECT    0x01 // Output range select register
#define AD5754R_REG_POWER_CONTROL   0x02 // Power control register
#define AD5754R_REG_CONTROL         0x03 // Control register

/* AD5754R Channel Address */
#define AD5754R_DAC_A               0x00 // Address of channel A
#define AD5754R_DAC_B               0x01 // Address of channel B
#define AD5754R_DAC_C               0x02 // Address of channel C
#define AD5754R_DAC_D               0x03 // Address of channel D
#define AD5754R_DAC_ALL             0x04 // All four DACs

/* AD5754R Range Bits */
#define AD5754R_UNIPOLAR_5_RANGE    0x00 // 0..+5(V)
#define AD5754R_UNIPOLAR_10_RANGE   0x01 // 0..+10(V)
#define AD5754R_UNIPOLAR_10_8_RANGE 0x02 // 0..+10.8(V)
#define AD5754R_BIPOLAR_5_RANGE     0x03 // -5..+5(V)
#define AD5754R_BIPOLAR_10_RANGE    0x04 // -10...+10(V)
#define AD5754R_BIPOLAR_10_8_RANGE  0x05 // -10.8...+10.8(V)

/* Control Functions */
#define AD5754R_NOP_OPERATION       0x00 // No operation instruction used in readback operations.
#define AD5754R_SDO_DISABLE         0x11 // Set by the user to disable the SDO output.
#define AD5754R_CLR_SELECT          0x12 // Selects the clear code: 0V, Midscale or Negative full scale.
#define AD5754R_CLAMP_ENABLE        0x14 // Set by the user to enable the current-limit clamp.
#define AD5754R_TSD_ENABLE          0x18 // Set by the user to enable the thermal shutdown feature.
#define AD5754R_CLEAR               0x40 // Sets the DAC registers to the clear code and updates the outputs.
#define AD5754R_LOAD                0x50 // Updates the DAC registers and, consequently, the DAC outputs.

void SendData(unsigned char *p){ //CHECKED OK
    //Serial.print("(send: ");

    digitalWrite(DA_SYNC,LOW);
    for (int i=2; i>= 0; i--){ //MSB first

        SPI1.transfer (p[i]);
        //Serial.print(p[i], BIN);
        //Serial.print(" ");
    }
    digitalWrite(DA_SYNC,HIGH);
    //Serial.println(")");
}

void SPIReadData(byte raw[]){
    digitalWrite(DA_SYNC, LOW);
    Serial.printf("SPIReadData: ");

    //Send  0001 8000 0000 0000 0000 0000 = NOP
    //Read 3 bytes

    for (int i=2; i>= 0; i--){

        raw[i] = SPI1.transfer(0x180000);
        Serial.printf("%x, ", raw[i]);

    }

    Serial.printf("\n");
    digitalWrite(DA_SYNC, HIGH);
}

void AD5754R_SetRegisterValue(unsigned char regBits,
                              unsigned char adrBits,
                              unsigned short registerValue)
{

    unsigned char registerWord[3] = {0};
    registerWord[2] = (regBits << 3) + adrBits;
    registerWord[1] = (registerValue & 0xFF00) >> 8;
    registerWord[0] = (registerValue & 0x00FF) >> 0;
    SendData(registerWord);
}


unsigned short AD5754R_GetRegisterValue(unsigned char regBits,
                                        unsigned char adrBits)
{
    unsigned char registerWord[3]   = {0};
    unsigned short data             = 0;
    registerWord[2] = (1 << 7) + (regBits << 3) + adrBits;
    registerWord[1] = 0;
    registerWord[0] = 0;
    SendData(registerWord);

    registerWord[2] = 0x18; // NOP instruction used in readback operations.
    registerWord[1] = 0;
    registerWord[0] = 0;
    SPIReadData(registerWord);
    data = (registerWord[1] << 8) + registerWord[2];
    Serial.printf("AD5754R_GetRegisterValue returns %x (BIN:",data);
    Serial.print(data, BIN);
    Serial.println();

    return(data);
}

/***************************************************************************//**
 * @brief Enables/disables indicated DAC channels.
 *
 * @param dacChannel - DAC channel or channels to be enabled/disabled.
 *                     Example: AD5754R_DAC_A - Channel A.
 *                              AD5754R_DAC_B - Channel B.
 *                              AD5754R_DAC_C - Channel C.
 *                              AD5754R_DAC_D - Channel D.
 *                              AD5754R_DAC_ALL - Channel ALL.
 * @param onOff - Enable or disable channel.
 *                Example: 0x0 - Off.
                                                                              *                         0x1 - On.
                                                                              *
                                                                              * @return None.
                                                                              *******************************************************************************/
void AD5754R_SetPower(unsigned char dacChannel, unsigned char onOff)
{
    Serial.printf("AD5754R_SetPower(%x, %x)...", dacChannel, onOff );
    unsigned short oldPowerCtl = 0;
    unsigned short newPowerCtl = 0;
    if(dacChannel == AD5754R_DAC_ALL)
    {
        dacChannel = 0x0F;
    }
    else
    {
        dacChannel = (1 << dacChannel);
    }
    oldPowerCtl = AD5754R_GetRegisterValue(AD5754R_REG_POWER_CONTROL,0x00);
    newPowerCtl = oldPowerCtl & ~dacChannel;
    newPowerCtl = newPowerCtl | (onOff * dacChannel);
    AD5754R_SetRegisterValue(AD5754R_REG_POWER_CONTROL,0x00,newPowerCtl);
}

/***************************************************************************//**
 * @brief Writes data into a DAC channel register.
 *
 * @param dacChannel - DAC channel or channels to be written.
 * @param dacValue - Value written in DAC register.
 *
 * @return None.
*******************************************************************************/
void AD5754R_LoadDac(unsigned char dacChannel, unsigned short dacValue)
{
    //Serial.printf("AD5754R_LoadDac(%x, %x)...", dacChannel, dacValue );
    AD5754R_SetRegisterValue(AD5754R_REG_DAC, dacChannel, dacValue);
}

/***************************************************************************//**
 * @brief Selects the output range of a DAC channel.
 *
 * @param dacChannel - DAC channel.
 * @param outputRange - Output range of a DAC channel.
 *
 * @return None.
*******************************************************************************/
void AD5754R_RangeSelect(unsigned char dacChannel, unsigned char outputRange)
{
    Serial.printf("AD5754R_RangeSelect(%x, %x)...", dacChannel, outputRange );
    unsigned short registerData = 0;

    registerData |= outputRange;
    AD5754R_SetRegisterValue(AD5754R_REG_RANGE_SELECT,dacChannel,registerData);
}

/***************************************************************************//**
 * @brief Selects an option of Control Register.
 *
 * @param option - control function selected
 * @param bitValue - indicates a set or a clear of the following
 *                   bits: SDO disable
 *                         CRL select
 *                         Clamp enable
 *                         TSD enable
 *
 * @return None.
*******************************************************************************/
void AD5754R_ControlFunction(unsigned char option, unsigned char bitValue)
{
    Serial.printf("AD5754R_ControlFunction(%x, %x)...", option, bitValue );
    unsigned char adrBits  = option & 0xF0;
    unsigned char dataBits = option & 0X0F;
    unsigned short oldControl = 0;
    unsigned short newControl = 0;
    if(adrBits == 0x01)
    {
        oldControl = AD5754R_GetRegisterValue(AD5754R_REG_CONTROL,0x01);
        newControl = oldControl & ~(dataBits);
        newControl = newControl | (bitValue * dataBits);
    }
    AD5754R_SetRegisterValue(AD5754R_REG_CONTROL,adrBits,newControl);
}

/***************************************************************************//**
 * @brief Read alert bits form Power Control Register.
 *
 * @param None.
 *
 * @return powerCtlStatus - Result of the Power Control Register read.
 *                          Contains alert bits: OCd, OCc, OCb, OCa and TSD.
 *                          Example: 0x01 - TSD is set
 *                                   0x05 - OCa and TSD are set
 *                                   0x3C - OCd, OCc, OCb, OCa are set.
 *
*******************************************************************************/
unsigned char AD5754R_ReadAlertBits(void)
{
    unsigned short powerCtlStatus = 0;

    powerCtlStatus = AD5754R_GetRegisterValue(AD5754R_REG_POWER_CONTROL,
                                              0x00);
    powerCtlStatus = (powerCtlStatus >> 5);
    powerCtlStatus &= 0x003F;               // Only bits 5 to 0 are required.
    return ((unsigned char) powerCtlStatus);
}


#endif //TEENSY_EURORACK_AD5754_H
