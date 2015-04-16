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
 
 Circuit: http://lab.piffa.net/schemi/piezo_2_keyboard_bb.png
 
 */


int input[]= {
  1,2,3};
int notes[] = {
  262, 392,880 }; // suona una prima, quinta, ottava in C4

// Carica un file di esempio con tutte le note
// #include "pitches.h";
// int notes[] = {NOTE_C4, NOTE_G4,NOTE_A5 }; // suona una prima, quinta, ottava

void setup(){
  //start serial connection
  Serial.begin(9600);
  //configure pin2/3/4 as an input and enable the internal pull-up resistor
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
    //delay(2); // eventuale delay
  }
}
/* Domande
 1. Modificare le note suonate utilizzando come riferimento il file pitches.h:
 suonare una prima, terza, quinta (C-E-G)
 2. Includere il file pitches.h . Come si potrebbe scrivere una melodia da far suonare
 autnomamente ad Arduino?
 */


