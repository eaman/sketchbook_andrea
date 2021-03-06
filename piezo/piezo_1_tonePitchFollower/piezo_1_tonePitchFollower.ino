/*
  Pitch follower
 
 Plays a pitch that changes based on a changing analog input
 
 circuit:
 * 8-ohm speaker on digital pin 8
 * photoresistor on analog 0 to 5V
 * 4.7K resistor on analog 0 to ground
 
 created 21 Jan 2010
 modified 31 May 2012
 by Tom Igoe, with suggestion from Michael Flynn

This example code is in the public domain.

- http://www.dummies.com/how-to/content/how-to-make-an-instrument-with-the-arduino.html
- https://www.arduino.cc/en/Tutorial/tonePitchFollower
 
 */


// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to
const int ledPin = 9;        // pin that the LED is attached to


void setup() {
  // initialize serial communications (for debugging only):
  Serial.begin(9600);
}

void loop() {
  // read the sensor:
  int sensorReading = analogRead(sensorPin);
  // print the sensor reading so you know its range
  Serial.println(sensorReading);
  // map the analog input range (in this case, 400 - 1000 from the photoresistor)
  // to the output pitch range (120 - 1500Hz)
  // change the minimum and maximum input numbers below
  // depending on the range your sensor's giving:
  int thisPitch = map(sensorReading, 300, 900, 220, 3500);

  // play the pitch:
  tone(ledPin, thisPitch, 10);
  delay(1);        // delay in between reads for stability
}

/* Domande:
1. Modificare l'estensione del range di frequenza del piezo
tra i valori 20hz e 20.000hz.
2. Inserire l'auto calibrazione
3. Modificare lo script in modo che vengano emessi suoni solo quando
una mano offusca leggermente la luce (il piezo non deve suonare
se non c'e' un operatore a interagire con la fotoresistenza).
*/
