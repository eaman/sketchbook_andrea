/*
  Input Condizionale
 
 Accensione e spegnimanto di un LED utilizzando un pin come input.

 Utilizzare un jumper per collegare il PIN Input
 alternativamente a +5 o GND .

Schema:
- http://lab.piffa.net/schemi/led_condizionale.png

 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led     = 12;
int input   = 2;

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

/* Domande:
 1. invertire il programma facendo in modo che il led si spenga
    quando il bottone e' premuto. Consoderare come ottenere lo stesso risultato
    modificando il circuito.
 2. Modificare il programma per far brillare il led cinque volte al secondo
    quando il bottone e' premuto.
 3. Si potrebbe usare un ciclo iterativo while invece che 
    un ciclo condizonale if? Che differenza c'e' tra il ciclo while e  for?
 4. Domanda: cosa succede se il jumper input non e' collegato ne al +5 ne al ground?
 */
