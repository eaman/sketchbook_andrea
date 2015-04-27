/* Blink con state machine: due led
 
 Accendere e spegnere due led utilizzando una state machine
 specificando sia il tempo accensione che di spegnimento.
 
 */

// These variables store the flash pattern
// and the current state of the LED

int ledPinA = 13; // the number of the LED pin
int ledStateA = LOW; // ledState used to set the LED
unsigned long previousMillisA = 0; // will store last time LED was updated
long intervalHighA = 1000; // 
long intervalLowA = 200; // 

int ledPinB = 12; // the number of the LED pin
int ledStateB = LOW; // ledState used to set the LED
unsigned long previousMillisB = 0; // will store last time LED was updated
long intervalHighB = 500; // 
long intervalLowB = 100; // 

void setup()
{
  // set the digital pin as output:
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);
}

void loop()
{
  // Primo LED
  // check to see if it's time to change the state of the LED
  unsigned long currentMillis = millis();
  if((ledStateA == HIGH) && (currentMillis - previousMillisA >= intervalHighA))
  {
    ledStateA = 1 - ledStateA ; // Inverti il LED
    previousMillisA = currentMillis; // Remember the time
    digitalWrite(ledPinA, ledStateA); // Update the actual LED

  } 
  else  if((ledStateA == LOW) && (currentMillis - previousMillisA >= intervalLowA))
  {
    ledStateA = 1 - ledStateA ; // Inverti il LED
    previousMillisA = currentMillis; // Remember the time
    digitalWrite(ledPinA, ledStateA); // Update the actual LED
  }

// Secondo LED

  // check to see if it's time to change the state of the LED
  unsigned long currentMillis = millis();
  if((ledStateB == HIGH) && (currentMillis - previousMillisB >= intervalHighB))
  {
    ledStateB = 1 - ledStateB ; // Inverti il LED
    previousMillisB = currentMillis; // Remember the time
    digitalWrite(ledPinB, ledStateB); // Update the actual LED

  } 
  else  if((ledStateB == LOW) && (currentMillis - previousMillisB >= intervalLowB))
  {
    ledStateB = 1 - ledStateB ; // Inverti il LED
    previousMillisB = currentMillis; // Remember the time
    digitalWrite(ledPinA, ledStateB); // Update the actual LED
  }
}

/* Domande
 1. E' possibile razzinalizzare il codice utilizzando una funzione?
 
 
 Link: 
 - Utilizzare codice a oggetti per ottimizzare il codice: 
   https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all#a-classy-solution
 */


