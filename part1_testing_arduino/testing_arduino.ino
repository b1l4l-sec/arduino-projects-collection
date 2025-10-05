
#include <Servo.h>

// constants won't change
const int BUTTON_PIN = 7; 
const int SERVO_PIN  = 9; 
const int buzzer = 13;
const int led0 = 3;
const int led90 = 2;

Servo servo;

// variables will change:
int angle = 0;        
int lastButtonState;    
int currentButtonState;
int buzzerval;
int ledval; 

void setup() {
  Serial.begin(9600);              
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  servo.attach(SERVO_PIN); 
  pinMode(buzzer,OUTPUT) ;  
  pinMode(led0,OUTPUT) ;
  pinMode(led90,OUTPUT) ;    

  servo.write(angle);
  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  lastButtonState    = currentButtonState;      
  currentButtonState = digitalRead(BUTTON_PIN); 

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    // change angle of servo motor
    if(angle == 0){
      angle = 90;
      buzzerval = 200;
      ledval = 2;
    }else
    if(angle == 90){
      angle = 0;
      buzzerval = 400;
      ledval = 3;
    }
    // control servo motor arccoding to the angle
    servo.write(angle);
    digitalWrite(ledval,HIGH);
    tone(buzzer,buzzerval);
    delay(200);
    digitalWrite(ledval,LOW);
    noTone(buzzer);
  }
}
