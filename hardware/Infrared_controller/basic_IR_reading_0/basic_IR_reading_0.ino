// Remote infrared control
// http://www.instructables.com/id/Arduino-Infrared-Remote-tutorial/

// Requires library: https://github.com/shirriff/Arduino-IRremote
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
     Serial.println(results.value, HEX);
     if (results.value == 0xFF30CF) {
       Serial.println("Uno");
     }
     irrecv.resume(); // Receive the next value
    }
}


