/*
 Melody keyboard with Input Pullup Serial
 Plays a pitch that changes based on 3 digital inputs
 
 This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a 
 digital input on pin 2 and prints the results to the serial monitor.
  
 Thecircuit:
 * 3 buttons in pin 2,3,4 with no resistors
 * Piezo on digital pin 9
 * Serial debug is available
 
 This example code is in the public domain
 
 */

// Please take care of the include path
#include "/home/utente/sketchbook-andrea/piezo/piezo_mario_tune/pitches.h";
int input[]= {1,2,3};
  int notes[] = {
  NOTE_A4, NOTE_C4,NOTE_E3 };

void setup(){
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(9, OUTPUT); 


}

void loop(){
 for (int thisSensor = 2; thisSensor < 5; thisSensor++) {
   int sensorReading = digitalRead(thisSensor);
   if (sensorReading == LOW) {
     Serial.println(thisSensor);
     tone(9, notes[thisSensor -2], 50); // Notes array is translated
   }
   //delay(2);
 }
}



