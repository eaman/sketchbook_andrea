#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_4_2 = CapacitiveSensor(4, 2);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
// pin 8 is sensor pin, add a wire and or foil
const int led = 13;        // pin that the Piezo is attached to
int sensorMin = 50;        // minimum sensor value
int sensorMax = 3200;           // maximum sensor value
void setup()
{
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  long start = millis();
  long total1 =  cs_4_2.capacitiveSensor(30);

  if (total1 > (sensorMax / 2 - sensorMin)) {
    digitalWrite(led, HIGH);
    delay(100);
  }
  else {
    digitalWrite(led, LOW);
    delay(100);
  }

  Serial.print(millis() - start);        // check on performance in milliseconds
  Serial.print("\t Capacitance: ");                    // tab character for debug windown spacing

  Serial.println(total1);                  // print sensor output 1
  delay(1);                             // arbitrary delay to limit data to serial port

}
