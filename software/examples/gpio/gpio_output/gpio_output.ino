#include "PCA9536.h"

PCA9536 pca9536;                              // construct a new PCA9536 instance

void setup() {
  // put your setup code here, to run once:
  Wire.begin();                             // initiallize the I2C Communications Bus
  while(!Serial);                           // wait for Serial Port to open
  pca9536.reset(); 
  pca9536.setMode(IO_OUTPUT);
}

void loop() {
  pca9536.setState(IO0, IO_HIGH);
  pca9536.setState(IO1, IO_HIGH);
  pca9536.setState(IO2, IO_HIGH);
  pca9536.setState(IO3, IO_HIGH);
  delay(50);
  pca9536.setState(IO0, IO_LOW);
  pca9536.setState(IO1, IO_LOW);
  pca9536.setState(IO2, IO_LOW);
  pca9536.setState(IO3, IO_LOW);
  delay(50);
}
