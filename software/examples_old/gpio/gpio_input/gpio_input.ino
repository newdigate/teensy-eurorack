#include "PCA9536.h"

PCA9536 pca9536;                              // construct a new PCA9536 instance

void setup() {
  // put your setup code here, to run once:
  Wire.begin();                             // initiallize the I2C Communications Bus
  while(!Serial);                           // wait for Serial Port to open
  pca9536.reset(); 
      Serial.print(F("\nSearching for device...Device "));
    Serial.print(pca9536.ping() ? "Not Found\n" : "Found!\n");
    
  pca9536.setMode(IO_INPUT);
  Serial.printf("hello\n");
}

bool v[] = {false, false, false, false};
pin_t pins[4] = { IO0, IO1, IO2, IO3 };
    
void loop() {
  for (int i = 0; i<4; i++) {
    bool state = pca9536.getState(pins[i]);
    if (state != v[i]) {
      Serial.printf("ch %d %i\n", i, state);
      v[i] = state;
    }
  }

 //testGetPinData();
 
  delay(1);
}

void testGetPinData() {
    for (byte i=0; i<4; i++) {
        Serial.print(F("\nPIN IO"));
        Serial.print(i);
        Serial.print(F(":     "));
        Serial.print(F("\t"));
        Serial.print(pca9536.getState(pins[i]) ? "HIGH" : "LOW");
    }
}
