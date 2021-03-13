#include <SPI.h> //MUST include the SPI library or this won't work.
#include "ad5754.h"
#include "teensy_eurorack.h"

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

void SendData2(unsigned char *p){ //CHECKED OK
  //Serial.print("(send: ");

  digitalWrite(DA_SYNC,LOW);
  for (int i=5; i>= 0; i--){ //MSB first

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

void AD5754R_LoadDac2(unsigned char dacChannel, unsigned short dacValue, unsigned char dac2Channel, unsigned short dac2Value)
{
    //Serial.printf("AD5754R_LoadDac(%x, %x)...", dacChannel, dacValue );
    AD5754R_SetRegisterValue2(AD5754R_REG_DAC, dacChannel, dacValue, AD5754R_REG_DAC, dac2Channel, dac2Value);
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
