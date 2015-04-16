/*
Pitch following

The input from a photo resistor dictates the pitch of a piezo.

 
 */

// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to
const int ledPin = 9;        // pin that the LED is attached to
int thisPitch ;

// calibration variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value


void setup() {
  // turn on LED to signal the start of the calibration period:
  pinMode(13, OUTPUT);
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
  sensorValue = analogRead(sensorPin);

  // apply the calibration to the sensor reading
  thisPitch = map(sensorValue, sensorMin, sensorMax, 120, 1500);
  // map the analog input range (in this case, min - max from the photoresistor)
  // to the output pitch range (120 - 1500Hz)
  // change the minimum and maximum input numbers below
  // depending on the range your sensor's giving:
  
  // in case the sensor value is outside the range seen during calibration
  thisPitch = constrain(sensorValue, 120, 1500);


  
  // play the pitch:
  tone(ledPin, thisPitch, 10); // Tone is built in function
  delay(1);        // delay in between reads for stability
}

