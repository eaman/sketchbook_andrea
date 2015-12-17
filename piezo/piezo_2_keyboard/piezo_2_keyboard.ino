
/*
 Melody keyboard with Input Pullup
 Plays a pitch that changes based on 3 digital inputs

 This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a
 digital input on pin 2 and prints the results to the serial monitor.
 There's also an extensive use of arrays.

 Thecircuit:
 * 3 buttons in pin 2,3,4 with no resistors
 * Piezo on digital pin 9
 * Serial debug is available

 This example code is in the public domain

 Circuit: http://lab.piffa.net/schemi/piezo_2_keyboard_bb.png

 */

const int tasti[]= {4,3,2}; // La nota piu' a sx e' quella piu' bassa
const int notes[] = {262, 392, 880}; // suona una prima, quinta, ottava in C4
const int piezo_pin = 9;

// Carica un file di esempio con tutte le note
// #include "pitches.h";
// int notes[] = {NOTE_C4, NOTE_G4,NOTE_C5 }; // suona una prima, quinta, ottava

void setup() {
    //start serial connection
    Serial.begin(9600);
    Serial.println("Welcome");
    //configure pin2/3/4 as an input and enable the internal pull-up resistor
    pinMode(tasti[0], INPUT_PULLUP);
    pinMode(tasti[1], INPUT_PULLUP);
    pinMode(tasti[2], INPUT_PULLUP);    // Provare ad impostare i PIN con un
                                        // ciclo for
    pinMode(9, OUTPUT);
}

void loop() {
    for (int thisSensor = 0; thisSensor < 3; thisSensor++) {
        int sensorReading = digitalRead(tasti[thisSensor]);
        if (sensorReading == LOW) {
            Serial.print("Sensore: ");
            Serial.print(thisSensor);
            tone(piezo_pin, notes[thisSensor ], 50); // Notes array is translated
            Serial.print("\t Nota: ");
            Serial.println(notes[thisSensor]);
        }
        //delay(2); // eventuale delay
    }
}
/* Domande
 1. Modificare le note suonate utilizzando come riferimento il file pitches.h:
    suonare una prima, terza, quinta (C-E-G)
 2. Includere il file pitches.h . Come si potrebbe scrivere una melodia da far s    uonare autnomamente ad Arduino?
 */








