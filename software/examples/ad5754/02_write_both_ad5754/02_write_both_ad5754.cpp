#include <SPI.h> //MUST include the SPI library or this won't work.
#include "ad5754.h"
#include "teensy_eurorack.h"

void SendData2(unsigned char *p){
    digitalWrite(DA_SYNC,LOW);
    for (int i=5; i>= 0; i--){ //MSB first
        SPI1.transfer (p[i]);
    }
    digitalWrite(DA_SYNC,HIGH);
}

void AD5754R_SetRegisterValue2(unsigned char regBits,
                               unsigned char adrBits,
                               unsigned short registerValue,
                               unsigned char regBits2,
                               unsigned char adrBits2,
                               unsigned short registerValue2)
{

    unsigned char registerWord[6] = {0};
    registerWord[2] = (regBits << 3) + adrBits;
    registerWord[1] = (registerValue & 0xFF00) >> 8;
    registerWord[0] = (registerValue & 0x00FF) >> 0;

    registerWord[5] = (regBits2 << 3) + adrBits2;
    registerWord[4] = (registerValue2 & 0xFF00) >> 8;
    registerWord[3] = (registerValue2 & 0x00FF) >> 0;
    SendData2(registerWord);
}


void AD5754R_LoadDac2(unsigned char dacChannel, unsigned short dacValue, unsigned char dac2Channel, unsigned short dac2Value)
{
    //Serial.printf("AD5754R_LoadDac(%x, %x)...", dacChannel, dacValue );
    AD5754R_SetRegisterValue2(AD5754R_REG_DAC, dacChannel, dacValue, AD5754R_REG_DAC, dac2Channel, dac2Value);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(DA_SYNC, OUTPUT);
  digitalWrite(DA_SYNC, HIGH); 

  Serial.begin(9600);

  SPI1.setSCK  (DA_CLK);
  SPI1.setMOSI (DA_MOSI);
  SPI1.setMISO (DA_MISO);
  SPI1.begin();
  
  delay(10);

  AD5754R_SetRegisterValue(AD5754R_REG_POWER_CONTROL,0x00,0x0f);

  //AD5754R_SetPower(AD5754R_DAC_ALL, 1);
  
  AD5754R_ControlFunction(AD5754R_SDO_DISABLE, 1);
   
  AD5754R_RangeSelect(AD5754R_DAC_ALL, AD5754R_UNIPOLAR_5_RANGE);
 
  AD5754R_LoadDac2(AD5754R_DAC_ALL, 0xffff, AD5754R_DAC_ALL, 0xffff);

//  AD5754R_GetRegisterValue(AD5754R_REG_POWER_CONTROL);
}


uint16_t control_voltage1 = 0x0000;
uint16_t control_voltage2 = 0x0000;

void loop() {
  control_voltage1++;
  control_voltage2--;
  AD5754R_LoadDac2(AD5754R_DAC_A, control_voltage1, AD5754R_DAC_A, control_voltage2);
  AD5754R_LoadDac2(AD5754R_DAC_B, control_voltage1, AD5754R_DAC_B, control_voltage2);
  AD5754R_LoadDac2(AD5754R_DAC_C, control_voltage1, AD5754R_DAC_C, control_voltage2);
  AD5754R_LoadDac2(AD5754R_DAC_D, control_voltage1, AD5754R_DAC_D, control_voltage2);
  delayMicroseconds(1);
}

