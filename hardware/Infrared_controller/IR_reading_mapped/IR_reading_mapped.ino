// Remote infrared control
// http://www.instructables.com/id/Arduino-Infrared-Remote-tutorial/

// Requires library: https://github.com/shirriff/Arduino-IRremote
// Numbers 1->6 mapped with a switch construct
// 
// Warning: DO NOT coonect the IR sensor to the Arduino without
// the PCB module

#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))
  {
    switch (results.value) {
    case 0xFF30CF:
      Serial.println("Uno");
      break;
    case 0xFF18E7:
      Serial.println("Due");
      break;    
    case 0xFF7A85:
      Serial.println("Tre");
      break;   
    case 0xFF10EF:
      Serial.println("Quattro");
      break;   
    case 0xFF38C7:
      Serial.println("Cinque");
      break;   
    case 0xFF5AA5:
      Serial.println("Sei");
      break;   
    case 0xFFFFFFFF:
      Serial.println("Repeat");
    }  
    //Serial.println(results.value, HEX); // Debug: show value
    irrecv.resume(); // Receive the next value

  }
}





