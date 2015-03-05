/*
  Serial comm: TX
 
 Comunicazione seriale tra due schede arduino.
 La prima scheda ha un bottone come input e 
 comunica con un altra scheda che monta un LED come output.
 Il led della seconda si accende quando rileva
 la pressione del bottone della prima.
 */

// Prima scheda: input
// PIN 1 = TX
int led = 13;
int input = 2;  // Questa e' la scheda con un input

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);       // Il PIN e' attivato come output
  pinMode(input, INPUT);        // Il PIN e' attivato come output
  
  Serial.begin(9600); // Attiviamo la seriale
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(input) == HIGH) { // Verifica se il PIN input e' +5v
    digitalWrite(led, HIGH);
    Serial.write(1);
    delay(50);
  } 
  else { // Alterativa: se non e' +5v
    digitalWrite(led, LOW);
    Serial.write(0);
    delay(50);
  }
}



