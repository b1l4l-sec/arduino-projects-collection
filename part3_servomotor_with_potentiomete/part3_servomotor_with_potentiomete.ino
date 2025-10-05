#include <Servo.h>  // add servo library
 
Servo myservo;  // create servo object to control a servo
 
int potpin = 0;  // analog pin used to connect the potentiometer pin A0 of the arduino
int val;    // variable to read the value from the analog pin
 
void setup() {
  myservo.attach(7);
  Serial.begin(9600);
}
 
void loop() {
  val = analogRead(potpin);
  val = map(val,0,1024,0,180);    
  myservo.write(val);
  delay(15);                        
}