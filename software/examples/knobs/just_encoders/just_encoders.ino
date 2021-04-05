#include "teensy_eurorack.h"

#include <Encoder.h>
#include <Bounce.h>
Bounce button0 = Bounce(TEENSY_EURORACK_PIN_ENC1_SW, 15);
Bounce button1 = Bounce(TEENSY_EURORACK_PIN_ENC2_SW, 15);
Bounce button2 = Bounce(TEENSY_EURORACK_PIN_ENC3_SW, 15);

Encoder Knob1(TEENSY_EURORACK_PIN_ENC1_A, TEENSY_EURORACK_PIN_ENC1_B);
Encoder Knob2(TEENSY_EURORACK_PIN_ENC2_A, TEENSY_EURORACK_PIN_ENC2_B);
Encoder Knob3(TEENSY_EURORACK_PIN_ENC3_A, TEENSY_EURORACK_PIN_ENC3_B);

void setup() {

   
  Serial.begin(9600);
  pinMode(TEENSY_EURORACK_PIN_ENC1_SW, INPUT_PULLUP);
  pinMode(TEENSY_EURORACK_PIN_ENC2_SW, INPUT_PULLUP);
  pinMode(TEENSY_EURORACK_PIN_ENC3_SW, INPUT_PULLUP);

  Serial.println("Encoders test");
}


long knob1 = 0, knob2 = 0, knob3 = 0; 
long lastMillis = 0;

void loop() { 
  long current_millis = millis();
  
  long newKnob1, newKnob2, newKnob3;
  newKnob1 = Knob1.read();
  newKnob2 = Knob2.read();
  newKnob3 = Knob3.read();
  
  if (newKnob1 != knob1 || newKnob2 != knob2 || newKnob3 != knob3) {

    Serial.print("1 = ");
    Serial.print(newKnob1);

    
    Serial.print(", 2 = ");
    Serial.print(newKnob2);
    
    Serial.print(", 3 = ");
    Serial.print(newKnob3);
    
    Serial.println();
    
    knob1 = newKnob1;
    knob2 = newKnob2;
    knob3 = newKnob3;
  }
  
  // Read the buttons and knobs, scale knobs to 0-1.0
  button0.update();
  button1.update();
  button2.update();
  
  if (button0.fallingEdge()) {
     Serial.println("Button 0");
  }
  
  if (button1.fallingEdge()) {
     Serial.println("Button 1");
  }
  
  if (button2.fallingEdge()) {
     Serial.println("Button 2");
  }

}
