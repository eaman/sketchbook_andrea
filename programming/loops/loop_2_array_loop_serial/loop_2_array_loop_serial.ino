/*
  For Loop Iteration

 Demonstrates the use of a for() loop.
 Lights multiple LEDs in sequence, then in reverse.

 The circuit:
 * LEDs from pins 2 through 9 to ground

 Schemi:
 - http://lab.piffa.net/schemi/8_led_single_res_bb.png
 - http://lab.piffa.net/schemi/8_led_single_res_schem.png

 http://www.arduino.cc/en/Tutorial/ForLoop
 */

byte ledPins[8] = {  // Domanda: cosa succede se uso int?
  2, 3, 4, 5, 6, 7, 8, 9
  } ; //Array
int timer = 100;           // Pausa per far brillare i LED

void setup() {
  Serial.begin(9600);
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 0; thisPin < sizeof(ledPins); thisPin++)  {
    pinMode(ledPins[thisPin], OUTPUT);
    Serial.print("Inizializzato pin n. ");
    Serial.println(thisPin);
  }

  Serial.print("Dimesione array: ");
  Serial.println(sizeof(ledPins));
}

void loop() {
  // loop from the lowest pin to the highest:
  for (int thisPin = 0; thisPin < sizeof(ledPins); thisPin++) {
    Serial.print("Accensione pin n. ");
    Serial.println(thisPin);
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);
    // Debug

  }

  // loop from the highest pin to the lowest:
  for (int thisPin = sizeof(ledPins) - 1 ; thisPin > 0; thisPin--) {
    Serial.print("Accensione pin n. "); // Gli array sono indicizzati da 0
    Serial.println(thisPin);
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer);
    digitalWrite(ledPins[thisPin], LOW);

  }
}
