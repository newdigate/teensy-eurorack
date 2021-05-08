#include <ST7735_t3.h> // Hardware-specific library
#include "teensy_eurorack.h"

#include <Encoder.h>
#include <Bounce.h>
// Option 1: use any pins but a little slower
ST7735_t3 tft = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

Bounce button0 = Bounce(TEENSY_EURORACK_PIN_ENC1_SW, 15);
Bounce button1 = Bounce(TEENSY_EURORACK_PIN_ENC2_SW, 15);
Bounce button2 = Bounce(TEENSY_EURORACK_PIN_ENC3_SW, 15);

Encoder Knob1(TEENSY_EURORACK_PIN_ENC1_A, TEENSY_EURORACK_PIN_ENC1_B);
Encoder Knob2(TEENSY_EURORACK_PIN_ENC2_A, TEENSY_EURORACK_PIN_ENC2_B);
Encoder Knob3(TEENSY_EURORACK_PIN_ENC3_A, TEENSY_EURORACK_PIN_ENC3_B);

const int analogInPin = TEENSY_EURORACK_PIN_POT1;  // Analog input pin that the potentiometer is attached to
const int analogInPin2 = TEENSY_EURORACK_PIN_POT2;  // Analog input pin that the potentiometer is attached toconst int analogOutPin = A21;
const int analogInCvPin = TEENSY_EURORACK_PIN_POT3;  // Analog input pin that the potentiometer is attached to
const int analogInCvPin2 = TEENSY_EURORACK_PIN_POT4;
// Analog output pin that the LED is attached to
void setup() {

  analogReference(0);
  //analogReadRes(16);              
  analogReadAveraging(32);
     
  Serial.begin(9600);
  pinMode(TEENSY_EURORACK_PIN_ENC1_SW, INPUT_PULLUP);
  pinMode(TEENSY_EURORACK_PIN_ENC2_SW, INPUT_PULLUP);
  pinMode(TEENSY_EURORACK_PIN_ENC3_SW, INPUT_PULLUP);
/*  
  pinMode(TEENSY_EURORACK_PIN_ENC1_A, INPUT_PULLUP);
  pinMode(TEENSY_EURORACK_PIN_ENC2_A, INPUT_PULLUP);
  pinMode(TEENSY_EURORACK_PIN_ENC3_A, INPUT_PULLUP);

  pinMode(TEENSY_EURORACK_PIN_ENC1_B, INPUT_PULLUP);
  pinMode(TEENSY_EURORACK_PIN_ENC2_B, INPUT_PULLUP);
  pinMode(TEENSY_EURORACK_PIN_ENC3_B, INPUT_PULLUP);
  pinMode(analogInPin, INPUT);  
  pinMode(analogInPin2, INPUT); 
  pinMode(analogInCvPin, INPUT);  
  pinMode(analogInCvPin2, INPUT); 
*/

  Serial.println("Ubuntu Test fixture");

  tft.initR(INITR_144GREENTAB);

  pinMode(TEENSY_EURORACK_PIN_ENC1_A, INPUT_PULLUP);
  
  tft.setRotation(3);
  tft.fillScreen(ST7735_BLACK);
  tft.useFrameBuffer(true);
  tft.updateScreenAsync(true);
    // If the codec was already powered up (due to reboot) power itd own first
  //codecControl.disable();
  delay(100);

  pinMode(analogInPin, INPUT_DISABLE);
  pinMode(analogInPin2, INPUT_DISABLE);
  pinMode(analogInCvPin, INPUT_DISABLE);
  pinMode(analogInCvPin2, INPUT_DISABLE);
}


long  knob1 = 0, 
      knob2 = 0, 
      knob3 = 0;
       
bool  knob1pressed = false, 
      knob2pressed = false,
      knob3pressed = false; 

int sensorValue, sensorValue2, sensorValue3, sensorValue4 = 0;        // value read from the pot
long lastMillis = 0;

bool needsUpdate = true;

uint32_t oscilliscope_x = 0;

void loop() { 
  long current_millis = millis();
  
  long newKnob1, newKnob2, newKnob3;
  newKnob1 = Knob1.read();
  newKnob2 = Knob2.read();
  newKnob3 = Knob3.read();
  
  if (newKnob1 != knob1 || newKnob2 != knob2 || newKnob3 != knob3) {
    needsUpdate = true;
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
    knob1pressed = false;
     Serial.println("Button 0");
     needsUpdate = true;
  } else if (button0.risingEdge()) {
    knob1pressed = true;
  }
  
  if (button1.fallingEdge()) {
     knob2pressed = false;
     Serial.println("Button 1");
     needsUpdate = true;
  } else if (button1.risingEdge()) {
    knob2pressed = true;
  }
  
  if (button2.fallingEdge()) {
     knob3pressed = false;
     Serial.println("Button 2");
     needsUpdate = true;
  } else if (button2.risingEdge()) {
    knob3pressed = true;
  }
  
  //if (current_millis > lastMillis + 1) 
  {
    uint16_t oldValue = sensorValue*128/1024;
    uint16_t oldValue2 = sensorValue2*128/1024;
    uint16_t oldValue3 = sensorValue3*128/1024;
    uint16_t oldValue4 = sensorValue4*128/1024;
    //tft.drawPixel(oscilliscope_x-1, sensorValue*128/1024, ST7735_GREEN );
  
    int newsensorValue = analogRead(A0);
    if (sensorValue != newsensorValue) {
      sensorValue = newsensorValue;
      //Serial.print("a0 in: ");
      //Serial.println(sensorValue, DEC);
      //analogWrite(analogOutPin, sensorValue);
    }
    
    int newsensorValue2 = analogRead(A1);
    if (sensorValue2 != newsensorValue2) {
      sensorValue2 = newsensorValue2;
      //Serial.print("a1 in: ");
      //Serial.println(sensorValue2, DEC);
      //analogWrite(analogOutPin2, sensorValue2);
    }

    int newsensorValue3 = analogRead(A17);
    if (sensorValue3 != newsensorValue3) {
      sensorValue3 = newsensorValue3;
      //Serial.print("a2 in: ");
      //Serial.println(sensorValue2, DEC);
    }
    int newsensorValue4 = analogRead(A8);
    if (sensorValue4 != newsensorValue4) {
      sensorValue4 = newsensorValue4;
      //Serial.print("a3 in: ");
      //Serial.println(sensorValue2, DEC);
    }

    tft.drawLine(oscilliscope_x-1, oldValue+1, oscilliscope_x, sensorValue*128/1024+1, ST7735_RED ); 
    
    
    tft.drawLine(oscilliscope_x-1, oldValue2+1, oscilliscope_x, sensorValue2*128/1024 + 1, ST7735_BLUE );    
    tft.drawLine(oscilliscope_x-1, oldValue3+1, oscilliscope_x, sensorValue3*128/1024 + 1 , ST7735_YELLOW ); 
    tft.drawLine(oscilliscope_x-1, oldValue4+1, oscilliscope_x, sensorValue4*128/1024 + 1, ST7735_GREEN ); 
    oscilliscope_x++;
    if (oscilliscope_x >= 128)
      needsUpdate = true;
    oscilliscope_x%=128;
    lastMillis = current_millis;
  }


  
  if (needsUpdate) {
    updateDisplay();
    needsUpdate = false;
  }

}

void updateDisplay() {
  tft.fillScreen(ST7735_BLACK);

  tft.setTextColor(knob1pressed? ST7735_GREEN : ST7735_YELLOW);
  tft.setCursor(1,1);
  tft.print("knob1:");
  tft.print(knob1, HEX);

  tft.setTextColor(knob2pressed? ST7735_GREEN : ST7735_YELLOW);
  tft.setCursor(1,9);
  tft.print("knob2:");
    tft.print(knob2, HEX);
   
  tft.setTextColor(knob3pressed? ST7735_GREEN : ST7735_YELLOW);
  tft.setCursor(1,17);
  tft.print("knob3:");
  tft.print(knob3, HEX);

  tft.setTextColor(ST7735_YELLOW);

}
