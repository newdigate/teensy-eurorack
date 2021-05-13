#include <SPI.h> //MUST include the SPI library or this won't work.
#include "ad5754.h"
#include "teensy_eurorack.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(DA_SYNC, OUTPUT);
  digitalWrite(DA_SYNC, HIGH); 

  Serial.begin(9600);
  while (!Serial) {
    delay(100);
  }

  Serial.println("connected...");
   
  SPI1.setSCK  (DA_CLK);
  SPI1.setMOSI (DA_MOSI);
  SPI1.setMISO (DA_MISO);
  SPI1.begin();
  
  delay(10);

  AD5754R_SetRegisterValue(AD5754R_REG_POWER_CONTROL,0x00,0x0f);

  //AD5754R_SetPower(AD5754R_DAC_ALL, 1);
  
  AD5754R_ControlFunction(AD5754R_SDO_DISABLE, 1);
   
  AD5754R_RangeSelect(AD5754R_DAC_ALL, AD5754R_UNIPOLAR_5_RANGE);
 
  AD5754R_LoadDac(AD5754R_DAC_ALL, 0xffff);

//  AD5754R_GetRegisterValue(AD5754R_REG_POWER_CONTROL);
}


uint16_t control_voltage1 = 0x0000;

void loop() {
  control_voltage1++;
  AD5754R_LoadDac(AD5754R_DAC_ALL, control_voltage1);
}