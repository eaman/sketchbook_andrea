#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 *
 * Schema: http://i.stack.imgur.com/FMI00.png
 */




CapacitiveSensor   cs_2_3 = CapacitiveSensor(2, 3);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2, 4);
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2, 5);




const int led = 13;        // pin that the Led is attached to
int sensorMin = 50;        // minimum sensor value
int sensorMax = 3200;           // maximum sensor value
void setup()
{
  cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  long start = millis();
  long total1 =  cs_2_3.capacitiveSensor(30);
  long total2 =  cs_2_4.capacitiveSensor(30);
  long total3 =  cs_2_5.capacitiveSensor(30);

  if (total1 > (sensorMax / 2 - sensorMin)) {
    digitalWrite(led, HIGH);
    Serial.println("Primo");
  }


  if (total2 > (sensorMax / 2 - sensorMin)) {
    digitalWrite(led, HIGH);
    Serial.println("Secondo");
  }

  if (total3 > (sensorMax / 2 - sensorMin)) {
    digitalWrite(led, HIGH);
    Serial.println("terzo");
  }

  Serial.print(millis() - start);        // check on performance in milliseconds
  Serial.print("\t Capacitance 1: ");                    // tab character for debug windown spacing

  Serial.print(total1);                  // print sensor output 1
  Serial.print("\t 2: ");                    // tab character for debug windown spacing

  Serial.print(total2);                  // print sensor output 1
  Serial.print("\t 3: ");                    // tab character for debug windown spacing
  Serial.println(total3);                  // print sensor output 1

  delay(1);                             // arbitrary delay to limit data to serial port
}

