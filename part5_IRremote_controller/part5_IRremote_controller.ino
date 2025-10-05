#include <IRremote.h> //

const byte IR_RECEIVE_PIN = 2;
int greenled = 10;
int redled = A0;

void setup()
{
   Serial.begin(9600);
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
      if(ir_code == "44"){
        digitalWrite(greenled, HIGH);
        analogWrite(redled, 0);
      }
      if(ir_code == "40"){
        analogWrite(redled, 255);
        digitalWrite(greenled, LOW);
      }
      if(ir_code == "30"){
        digitalWrite(greenled, LOW);
        analogWrite(redled, 0);
      }
      if(ir_code == "10"){
        digitalWrite(greenled, HIGH);
        analogWrite(redled, 255);
      }

      IrReceiver.resume();
   }
}