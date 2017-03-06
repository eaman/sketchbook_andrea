/* Blink without Delay - only led
 
 Turns on and off a light emitting diode(LED) connected to a digital  
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.
 
 
Schema: https://lab.piffa.net/schemi/circuito_led_bb.png
 
 
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to 
// set pin numbers:
const int led = 13;      // Primo LED

              
unsigned long previousMillis = 0;        // will store last time LED was updated
unsigned long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(led, OUTPUT);      
}

void loop()
{
  if (millis() - previousMillis >= interval) {
    // Timestamp + timestamp = delta temporale
    previousMillis += interval ;

    digitalWrite(led, !digitalRead(led));
  }
}
