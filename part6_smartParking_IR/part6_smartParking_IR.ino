#include <IRremote.h> //
#include <Servo.h> 

const byte IR_RECEIVE_PIN = 2;
int greenled = 10;

Servo myservo;

void setup()
{
   Serial.begin(9600);
   myservo.attach(7);
   myservo.write(0);
   Serial.println("IR Receive test");
   pinMode(greenled, OUTPUT);
   IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop()
{
   if (IrReceiver.decode())
   {
      String ir_code = String(IrReceiver.decodedIRData.command, HEX);
      Serial.println(ir_code);// which button on the remote has a specific ir_code 
      if(ir_code == "15"){
        digitalWrite(greenled, HIGH);
        myservo.write(90);
      }
      if(ir_code == "7"){
        digitalWrite(greenled, LOW);
        myservo.write(0);
      }

      IrReceiver.resume();
   }
}