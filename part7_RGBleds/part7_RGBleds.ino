#include <IRremote.h> //
#define col1 3
#define col2 4
#define col3 5

const byte IR_RECEIVE_PIN = 2;



void setup()
{
   Serial.begin(9600);
   Serial.println("IR Receive test");
   pinMode(col1, OUTPUT);
   pinMode(col2, OUTPUT);
   pinMode(col3, OUTPUT);

   IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop()
{
   if (IrReceiver.decode())
   {
      String ir_code = String(IrReceiver.decodedIRData.command, HEX);
      Serial.println(ir_code);// which button on the remote has a specific ir_code 
      if(ir_code == "c"){
        analogWrite(col1,255);
        analogWrite(col2,0);
        analogWrite(col3,0);
      }
      if(ir_code == "18"){
        analogWrite(col1,255);
        analogWrite(col2,255);
        analogWrite(col3,0);
      }
      if(ir_code == "5e"){
        analogWrite(col1,0);
        analogWrite(col2,0);
        analogWrite(col3,255);
      }
      if(ir_code == "8"){
        analogWrite(col1,75);
        analogWrite(col2,0);
        analogWrite(col3,130);
      }
      if(ir_code == "1c"){
        analogWrite(col1,0);
        analogWrite(col2,128);
        analogWrite(col3,0);
      }
      if(ir_code == "5a"){
        analogWrite(col1,255);
        analogWrite(col2,0);
        analogWrite(col3,255);
      }
      if(ir_code == "42"){
        analogWrite(col1,255);
        analogWrite(col2,20);
        analogWrite(col3,147);
      }
      if(ir_code == "52"){
        analogWrite(col1,0);
        analogWrite(col2,255);
        analogWrite(col3,0);
      }
      if(ir_code == "4a"){
        analogWrite(col1,0);
        analogWrite(col2,255);
        analogWrite(col3,255);
      }
      if(ir_code == "16"){
        analogWrite(col1,0);
        analogWrite(col2,0);
        analogWrite(col3,0);
      }

      IrReceiver.resume();
   }
}