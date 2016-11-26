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
const int piezo = 9;        // pin that the Piezo is attached to
int sensorMin = 50;        // minimum sensor value
int sensorMax = 3200;           // maximum sensor value
void setup()
{
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
  pinMode(piezo, OUTPUT);
}

void loop()
{
  long start = millis();
  long total1 =  smoothRead(cs_4_2.capacitiveSensor(30));

  int value = map(total1, sensorMin, sensorMax, 220, 3500);

  value = constrain(value, 220, 3500);
  tone(piezo, value, 10);

  Serial.print(millis() - start);        // check on performance in milliseconds
  Serial.print("\t Capacitance: ");                    // tab character for debug windown spacing

  Serial.print(total1);                  // print sensor output 1
  Serial.print("  \t   Pitch: ");
  Serial.println(value);
  delay(1);                             // arbitrary delay to limit data to serial port

}

// Funzioni

int smoothRead(int value) {
//  Legge 10 valori dal sensore e ritorna il valore medio tra questi.
  int total = 0;
  for (int i = 0; i < 10; i++) { 
    total = total + value;
  }
  return(total / 10);
}

