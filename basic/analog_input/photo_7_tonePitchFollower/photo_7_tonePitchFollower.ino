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

 Modified by A.Manni

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone2
 
 */

// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to
const int piezoPin  = 9;     // pin that the piezo is attached to

// variables:
int sensorValue = 0;         // the sensor value
int sensorMin   = 1023;      // minimum sensor value
int sensorMax   = 0;         // maximum sensor value
int pitch       = 0;         // pithc value for the piezo

void setup() {
  // initialize serial communications (for debugging only):
  Serial.begin(9600);
    pinMode(13, OUTPUT);
    pinMode(piezoPin, OUTPUT);
  digitalWrite(13, HIGH);

  // calibrate during the first five seconds 
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  // signal the end of the calibration period
  digitalWrite(13, LOW);
}

void loop() {
  // read the sensor:
  int sensorValue = analogRead(sensorPin);
  // print the sensor reading so you know its range
  Serial.println(sensorValue);
  // map the analog input range 
  // to the output pitch range (120 - 1500Hz)
  // change the minimum and maximum input numbers below
  // depending on the range your sensor's giving:
  pitch = map(sensorValue, sensorMin, sensorMax, 220, 3500);

  // play the pitch:
  if (sensorValue < sensorMax -50) { // Offset to prevent the piezo to ring
                                     // all the time, check sensor polarity
  tone(piezoPin, pitch, 10);
  }
  delay(1);        // delay in between reads for stability
}



/* Esercizi:
 1. Implementare constrain e smoothing in questo sketch

 */


