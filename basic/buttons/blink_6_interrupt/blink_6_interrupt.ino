/*
  Blink v1

  Accensione e spegnimanto di due LED utilizzando un interrupt:
  un interrupt associato al PIN del bottone sollecita una ISR routine
  che puo' essere richiamata in ogni momento a prescindere
  da cosa il microprocessore sta facendo nel loop.

  Nota: per togliere l'effetto bouncing del bottone:
  - https://www.arduino.cc/en/tutorial/debounce
  vedi esercizio: sketchbook_andrea/advanced_projects/interrupts/debounce/debounce.ino
- https://lab.piffa.net/sketchbook_andrea/advanced_projects/interrupts/debounce/debounce.ino
 
 */

// Pin 13 ha un LED collegato di default
const int ledA = 13;
const int ledB = 12; //Secondo LED, con resistenza
const int pausa = 5000; 

void setup() {
  // Inizializziamo il PIN 13 come OUTPUT
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);

  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, reazioneISR, FALLING); // 0 e' l'interrupt numero 0
  // connesso al PIN D2, l'interrupt 1 e' connesso al PIN D3
  // eventoAttivo : nome della funzione da richiamare
  // per un ISRs e' sempre VOID
  // LOW | RISING | FALLIN | CHANGE | HIGH
}

void loop() {
  digitalWrite(ledA, HIGH);
  delay(pausa);
  digitalWrite(ledA, LOW);
  delay(pausa);
}

void reazioneISR() // Sempre VOID
{
  digitalWrite(ledB, !digitalRead(ledB));
}

