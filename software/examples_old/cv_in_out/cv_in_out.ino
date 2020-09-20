#include <SPI.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <ST7735_t3.h> // Hardware-specific library

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

#define TFT_SCLK 13  // SCLK can also use pin 14
#define TFT_MOSI 11  // MOSI can also use pin 7
#define TFT_CS   6  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC    2  //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST   0 // RST can use any pin
#define SD_CS     4  // CS for SD card, can use any pin
ST7735_t3 TFT = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

#define SCALE_FACTOR 0.000152587890625

// 10/(2^16) = 0.000152587890625

#define BUSY 3
#define RESET 4
#define START_CONVERSION 5
#define CHIP_SELECT 10
#define MISO 12
#define MOSI 11
#define LED 13
#define TOTAL_RAW_BYTES 16

#define TFT_CS 6
#define DA_SYNC 16

int bytesToRead = TOTAL_RAW_BYTES;  
byte raw[TOTAL_RAW_BYTES];  
uint16_t parsed[8];
int x = 0;
uint16_t oldpos[8] = {0,0,0,0,0,0,0,0};
int16_t colors[8] = {ST7735_GREEN,ST7735_RED,ST7735_BLUE,ST7735_CYAN,ST7735_MAGENTA,ST7735_YELLOW,0x00AA,ST7735_WHITE};



uint16_t control_voltage1 = 0x0000;

void setup() {  
  pinMode(DA_SYNC, OUTPUT);
  digitalWrite(DA_SYNC, HIGH); 

  
  pinMode(BUSY, INPUT);
  pinMode(RESET, OUTPUT);
  pinMode(TFT_CS, OUTPUT);
  pinMode(START_CONVERSION, OUTPUT);
  pinMode(CHIP_SELECT, OUTPUT);
  //pinMode(MISO, INPUT);

  Serial.begin(115200);
/*  while (!Serial) {
    delay(100);
  }
  Serial.println("hello"); */
/*  SPI.setSCK(13);
  SPI.setMISO(MISO);
  SPI.setMOSI(MOSI); */


  //TFT.begin();
  TFT.initR(INITR_144GREENTAB);
  TFT.setRotation(3);
  TFT.fillScreen(ST7735_BLACK);

  //digitalWrite(TFT_CS, HIGH); 
  SPI.begin();
  digitalWrite(START_CONVERSION, HIGH);  
  digitalWrite(CHIP_SELECT, HIGH);
  digitalWrite(RESET, HIGH);
  delay(100);
  digitalWrite(RESET, LOW);
    delay(100);
    //digitalWrite(RESET, HIGH);


  AD5754R_SetRegisterValue(AD5754R_REG_POWER_CONTROL,0x00,0x0f);

  //AD5754R_SetPower(AD5754R_DAC_ALL, 1);
  
  AD5754R_ControlFunction(AD5754R_SDO_DISABLE, 1);
   
  AD5754R_RangeSelect(AD5754R_DAC_ALL, AD5754R_UNIPOLAR_10_RANGE);
 
  AD5754R_LoadDac(AD5754R_DAC_ALL, 0xffff);
}

int resetCount = 0;
SPISettings _spiSettings;
void loop() {  

  control_voltage1+=2;
  AD5754R_LoadDac(AD5754R_DAC_ALL, control_voltage1);
  
  int i;
  //SPI.begin();
  digitalWrite(START_CONVERSION, LOW);
  //Serial.print("L");
  delayMicroseconds(100);
  digitalWrite(START_CONVERSION, HIGH);
  //Serial.print("H");
    
  while (digitalRead(BUSY) == HIGH) {
    // wait for conversion to complete
    delayMicroseconds(1);
  }
  SPI.beginTransaction(_spiSettings);
  digitalWrite(CHIP_SELECT, LOW);
  while (bytesToRead > 0) {
    raw[TOTAL_RAW_BYTES - bytesToRead] = SPI.transfer(0x00);
    bytesToRead--;
  }
  digitalWrite(CHIP_SELECT, HIGH);
  SPI.endTransaction(); 
  bytesToRead = TOTAL_RAW_BYTES;

  parseRawBytes();

  //TFT.initR(INITR_144GREENTAB);

  for(i=0; i<8; i++) {
    //
    if (parsed[i] > 0xffe0)
      parsed[i] = 0;
    uint8_t value = parsed[i] >> 8;
    //Serial.print((float)parsed[i] * SCALE_FACTOR * 2, 5);
    TFT.drawLine(x, oldpos[i], x+1, value, colors[i]);
    //Serial.printf("%d",  parsed[i] * 10 / );
    //Serial.print(",");
    oldpos[i] = value;
  }

  x++;
  if (x > 126) {
    x = 0;
    TFT.fillScreen(ST7735_BLACK);
  }
  
  //Serial.print("\r\n");
  //delay(100);
}

void parseRawBytes() {
  parsed[0] = (raw[0] << 8) + raw[1];
  parsed[1] = (raw[2] << 8) + raw[3];
  parsed[2] = (raw[4] << 8) + raw[5];
  parsed[3] = (raw[6] << 8) + raw[7];
  parsed[4] = (raw[8] << 8) + raw[9];
  parsed[5] = (raw[10] << 8) + raw[11];
  parsed[6] = (raw[12] << 8) + raw[13];
  parsed[7] = (raw[14] << 8) + raw[15];
}


void SendData(unsigned char *p){ //CHECKED OK
  //Serial.print("(send: ");
SPI.beginTransaction(_spiSettings);
  digitalWrite(DA_SYNC,LOW);
  for (int i=2; i>= 0; i--){ //MSB first

    SPI.transfer (p[i]);
    //Serial.print(p[i], BIN);
    //Serial.print(" ");
  }
  digitalWrite(DA_SYNC,HIGH);
  SPI.endTransaction(); 
  //Serial.println(")");
} 

void SPIReadData(byte raw[]){
  digitalWrite(DA_SYNC, LOW);
  Serial.printf("SPIReadData: ");

  //Send  0001 8000 0000 0000 0000 0000 = NOP
  //Read 3 bytes

  for (int i=2; i>= 0; i--){

      raw[i] = SPI.transfer(0x180000);

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
