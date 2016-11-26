#include <CapacitiveSensor.h>
#include "pitches.h"
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
CapacitiveSensor   cs_2_6 = CapacitiveSensor(2, 6);
CapacitiveSensor   cs_2_7 = CapacitiveSensor(2, 7);
CapacitiveSensor   cs_2_8 = CapacitiveSensor(2, 8);
CapacitiveSensor   cs_2_9 = CapacitiveSensor(2, 9);
CapacitiveSensor   cs_2_10 = CapacitiveSensor(2, 10);
const int led = 13;        // pin that the Led is attached to
int sensorMin = 50;        // minimum sensor value
int sensorMax = 3200;           // maximum sensor value

// Carica un file di esempio con tutte le note

int notes[] = {NOTE_C4, NOTE_E4, NOTE_G5 }; // suona una prima, quinta, ottava



const int piezo_pin = 11;


void setup()
{
  cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);         // Disable Serial to make it fastw
  pinMode(led, OUTPUT);
  pinMode(piezo_pin, OUTPUT);
}

void loop()
{
  long total[] =  {
  cs_2_3.capacitiveSensor(30),
  cs_2_4.capacitiveSensor(30),
  cs_2_5.capacitiveSensor(30),
  cs_2_6.capacitiveSensor(30),
  cs_2_7.capacitiveSensor(30),
  cs_2_8.capacitiveSensor(30),
  cs_2_9.capacitiveSensor(30),
  cs_2_10.capacitiveSensor(30)
  };

  
//  long total[1] =  cs_2_4.capacitiveSensor(30);
//  long total[2] =  cs_2_5.capacitiveSensor(30);
//  long total[3] =  cs_2_6.capacitiveSensor(30);
//  long total[4] =  cs_2_7.capacitiveSensor(30);
//  long total[5] =  cs_2_8.capacitiveSensor(30);
//  long total[6] =  cs_2_9.capacitiveSensor(30);
//  long total[7] =  cs_2_10.capacitiveSensor(30);

for (int thisSensor =0; thisSensor < 8; thisSensor++) {
  if (total[thisSensor]  > (sensorMax / 2 - sensorMin)) {
    tone(piezo_pin, notes[thisSensor], 50); // Notes array is translated
    Serial.println(thisSensor);
  }
}

}

