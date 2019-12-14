#include <RotaryEncoder.h>

int led1r = 6;           // the PWM pin the LED is attached to
int led1g = 7;           // the PWM pin the LED is attached to
int led1b = 8;           // the PWM pin the LED is attached to

int led2r =3;           // the PWM pin the LED is attached to
int led2g = 4;           // the PWM pin the LED is attached to
int led2b = 5;           // the PWM pin the LED is attached to

int led3r = 0;           // the PWM pin the LED is attached to
int led3g = 1;           // the PWM pin the LED is attached to
int led3b = 2;           // the PWM pin the LED is attached to

int enc3a = 11;
int enc3b = 12;

int enc2a = 9;
int enc2b = 10;

int enc1a = A5;
int enc1b = A6;

int ledPin = 32;  

int sensorPin1 = A4;    // select the input pin for the potentiometer
int sensorValue1 = 0;  // variable to store the value coming from the sensor

int sensorPin2 = A3;    // select the input pin for the potentiometer
int sensorValue2 = 0;  // variable to store the value coming from the sensor

int sensorPin3 = A2;    // select the input pin for the potentiometer
int sensorValue3 = 0;  // variable to store the value coming from the sensor

int sensorPin4 = A1;    // select the input pin for the potentiometer
int sensorValue4 = 0;  // variable to store the value coming from the sensor


int count = 0;
RotaryEncoder encoder1(enc1b, enc1a);
RotaryEncoder encoder3(enc3a, enc3b);
RotaryEncoder encoder2(enc2b, enc2a);

int brightness1r = 0,
    brightness1g = 0,
    brightness1b = 0,
    brightness2r = 0,
    brightness2g = 0,
    brightness2b = 0,
    brightness3r = 0,
    brightness3g = 0,
    brightness3b = 0;    // how bright the LED is
    
int fadeAmount1r = 1,
    fadeAmount1g = 1,
    fadeAmount1b = 1,
    fadeAmount2r = 1,
    fadeAmount2g = 1,
    fadeAmount2b = 1,
    fadeAmount3r = 1,
    fadeAmount3g = 1,
    fadeAmount3b = 1;    

void setup() {
  Serial.begin(9600);
  Serial.println("TwoKnobs Encoder Test:");

  Serial1.begin(9600);
  Serial1.println("kc");
  
  pinMode(32, OUTPUT);
  digitalWrite(32, HIGH);
     
  // declare pin 9 to be an output:
  pinMode(led1r, OUTPUT);
  pinMode(led1g, OUTPUT);
  pinMode(led1b, OUTPUT);

  pinMode(led2r, OUTPUT);
  pinMode(led2g, OUTPUT);
  pinMode(led2b, OUTPUT);

  pinMode(led3r, OUTPUT);
  pinMode(led3g, OUTPUT);
  pinMode(led3b, OUTPUT);

  analogWriteResolution(8);
}


// the loop routine runs over and over again forever:
void loop() {
  Serial1.print("-");

  if (count % 100 == 0) {
  int sensorValue = analogRead(sensorPin1); 
  if (abs(sensorValue - sensorValue1) > 3) {
    Serial.print("A1:");
    Serial.print(sensorValue);
    Serial.println();
    
    Serial1.print("A1:");
    Serial1.print(sensorValue);
    Serial1.println();
    sensorValue1 = sensorValue;
  }
  
  sensorValue = analogRead(sensorPin2);
  if (abs(sensorValue - sensorValue2) > 3) {
    Serial.print("A2:");
    Serial.print(sensorValue);
    Serial.println();
    
    Serial1.print("A2:");
    Serial1.print(sensorValue);
    Serial1.println();
    sensorValue2 = sensorValue;
  }
    
  sensorValue = analogRead(sensorPin3); 
  if (abs(sensorValue - sensorValue3) > 3) {
    Serial.print("A3:");
    Serial.print(sensorValue);
    Serial.println();
    
    Serial1.print("A3:");
    Serial1.print(sensorValue);
    Serial1.println();
    sensorValue3 = sensorValue;
  }   

  sensorValue = analogRead(sensorPin4); 
  if (abs(sensorValue - sensorValue4) > 3) {
    Serial.print("A4:");
    Serial.print(sensorValue);
    Serial.println();
    
    Serial1.print("A4:");
    Serial1.print(sensorValue);
    Serial1.println();
    sensorValue4 = sensorValue;
  }   
  }

  static int pos1 = 0, pos2 = 0, pos3 = 0;
  encoder1.tick();
  encoder2.tick();
  encoder3.tick();

  int newPos = encoder1.getPosition();
  if (pos1 != newPos) {
    Serial.print("R1:");
    Serial.print(newPos);
    Serial.println();
    
    Serial1.print("R1:");
    Serial1.print(newPos);
    Serial1.println();
    
    pos1 = newPos;
  } 

  newPos = encoder2.getPosition();
  if (pos2 != newPos) {
    Serial.print("R2:");
    Serial.print(newPos);
    Serial.println();
    
    Serial1.print("R2:");
    Serial1.print(newPos);
    Serial1.println();    
    pos2 = newPos;
  } 
  
  newPos = encoder3.getPosition();
  if (pos3 != newPos) {
    Serial.print("R3:");
    Serial.print(newPos);
    Serial.println();

    Serial1.print("R3:");
    Serial1.print(newPos);
    Serial1.println();
    pos3 = newPos;
  } 
  
  count++;
  if (count % 5000 == 0) {
  // set the brightness of pin 9:
    analogWrite(led1r, brightness1r);
    analogWrite(led1g, brightness1g);
    analogWrite(led1b, brightness1b);
  
    analogWrite(led2r, brightness2r);
    analogWrite(led2g, brightness2g);
    analogWrite(led2b, brightness2b);
  
    analogWrite(led3r, brightness3r);
    analogWrite(led3g, brightness3g);
    analogWrite(led3b, brightness3b);
  
  
    // change the brightness for next time through the loop:
    brightness1r = brightness1r + fadeAmount1r;
    brightness1g = brightness1g + fadeAmount1g*2;
    brightness1b = brightness1b + fadeAmount1b*3;
    brightness2r = brightness2r + fadeAmount2r*4;
    brightness2g = brightness2g + fadeAmount2g*5;
    brightness2b = brightness2b + fadeAmount2b*6;
    brightness3r = brightness3r + fadeAmount3r*7;
    brightness3g = brightness3g + fadeAmount3g*8;
    brightness3b = brightness3b + fadeAmount3b*9;
  }
  
  // reverse the direction of the fading at the ends of the fade:
  if (brightness1r <= 0 || brightness1r >= 255) {
    fadeAmount1r = -fadeAmount1r;
  }

  if (brightness1g <= 0 || brightness1g >= 255) {
    fadeAmount1g = -fadeAmount1g;
  }

  if (brightness1b <= 0 || brightness1b >= 255) {
    fadeAmount1b = -fadeAmount1b;
  }

  if (brightness2r <= 0 || brightness2r >= 255) {
    fadeAmount2r = -fadeAmount2r;
  }

  if (brightness2g <= 0 || brightness2g >= 255) {
    fadeAmount2g = -fadeAmount2g;
  }

  if (brightness2b <= 0 || brightness2b >= 255) {
    fadeAmount2b = -fadeAmount2b;
  }

  if (brightness3r <= 0 || brightness3r >= 255) {
    fadeAmount3r = -fadeAmount3r;
  }

  if (brightness3g <= 0 || brightness3g >= 255) {
    fadeAmount3g = -fadeAmount3g;
  }

  if (brightness3b <= 0 || brightness3b >= 255) {
    fadeAmount3b = -fadeAmount3b;
  }


  // wait for 30 milliseconds to see the dimming effect
  //delay(20);
}
