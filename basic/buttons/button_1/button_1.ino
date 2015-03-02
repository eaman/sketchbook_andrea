/*
  Input
 
 Accensione e spegnimanto di un LED utilizzando un pin come input.
 

 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int input = 8;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);       // Il PIN e' attivato come output
  pinMode(input, INPUT);        // Il PIN e' attivato come output
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(input) == HIGH) { // Verifica se il PIN input e' +5v
    digitalWrite(led, HIGH);
  } 
  else { // Alterativa: se non e' +5v
    digitalWrite(led, LOW);
  }
}


// Funzioni create dall'utente:


