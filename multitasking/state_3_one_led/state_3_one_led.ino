/* Blink con state machine

  Accendere e spegnere un led utilizzando una state machine
*/

// These variables store the flash pattern
// and the current state of the LED

int ledPin = 13; // the number of the LED pin
int ledState = LOW; // ledState used to set the LED
unsigned long previousMillis = 0; // will store last time LED was updated
long interval = 1000; // 

void setup()
{
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // check to see if it's time to change the state of the LED
  unsigned long currentMillis = millis();
  if((ledState == HIGH) && (currentMillis - previousMillis >= interval))
  {
    ledState = !ledState ; // Inverti il LED
    previousMillis = currentMillis; // Remember the time
    digitalWrite(ledPin, ledState); // Update the actual LED

  } 
  else  if((ledState == LOW) && (currentMillis - previousMillis >= interval))
  {
    ledState = !ledState ; // Inverti il LED
    previousMillis = currentMillis; // Remember the time
    digitalWrite(ledPin, ledState); // Update the actual LED
  }


}

/* 
1. Modificare il codice in modo che si possa precisare il tempo di HIGH
   e il tempo di LOW
2. Aggiungere un LED che brilli ogni 500ms   
   */
   
