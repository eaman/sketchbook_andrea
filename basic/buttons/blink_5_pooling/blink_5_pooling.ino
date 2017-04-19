/*
  Blink v1

  Accensione e spegnimanto di due LED utilizzando la tecnica del pooling:
  un ciclo if nel loop verifica periodicamente tramite digitalRead
  se un bottone e' premuto.

  Il codice e' blocking a causa dell'uso della funziona delay
  di conseguenza il pool del del bottone puo' avvenire solo quando
  il microcontroller non e' in delay.

  Nell'esercizio successivo (blink_interrupt) viene usato un interrupt
  per intercettare la pressione del bottone.

 */

// Pin 13 ha un LED collegato di default
const int ledA = 13;
const int ledB = 12; //Secondo LED, con resistenza
const int pausa = 2000; 

void setup() {
  // Inizializziamo il PIN 13 come OUTPUT
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);

  pinMode(2, INPUT_PULLUP);
}

void loop() {
  digitalWrite(ledA, HIGH);
  delay(pausa);
  digitalWrite(ledA, LOW);
  delay(pausa);

  if (!digitalRead(2)) {
     digitalWrite(ledB, !digitalRead(ledB));
  }

}

