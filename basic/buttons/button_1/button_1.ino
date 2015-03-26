/*
  Input
 
 Accensione e spegnimanto di un LED utilizzando un pin come input.
 

 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int input = 2;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);       // Il PIN e' attivato come output
  pinMode(input, INPUT);        // Il PIN e' attivato come output
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(input) == HIGH) { // Verifica se il PIN input e' +5V
    digitalWrite(led, HIGH);
  } 
  if (digitalRead(input) == LOW) { // Verifica se il PIN input e' 0V
    digitalWrite(led, LOW);
  }
}

// Modifiche: 
// 1. invertire il programma facendo in modo che il led si spenga
// quando il bottone e' premuto. Consoderare come ottenere lo stesso risultato
// modificando il circuito.
// 2. Modificare il programma per far brillare il led cinque volte al secondo
// quando il bottone e' premuto.

// Domanda: cosa succede se il jumper input non e' collegato ne al +5 ne al gound?


