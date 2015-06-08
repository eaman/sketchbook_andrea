/*
  Serial comm: RX due output
 
 Comunicazione seriale tra due schede arduino.
 La prima scheda ha due botton1 come input e 
 comunica con un altra scheda che monta due LED come output.
 Il led della seconda si accende quando rileva
 la pressione del bottone della prima.
 
 La RX deve distinguere l'input ricevuto.
 */

// Seconda scheda: output
// PIN 0 = RX
int led = 13; // Questa scheda ha spolo l'output
int red = 12; // Questa scheda ha spolo l'output
int incomingByte ;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);       // Il PIN e' attivato come output
  pinMode(red, OUTPUT);       // Il PIN e' attivato come output
  Serial.begin(9600); // Attiviamo la seriale
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    
    if (incomingByte == 2) { // Verifica se il PIN input e' +5v
      digitalWrite(led, HIGH);
      delay(50);
      digitalWrite(led, LOW);
    } 
    else if (incomingByte == 3) { // Alterativa: se non e' +5v
      digitalWrite(red, HIGH);
      delay(50);
      digitalWrite(red, LOW);
    }
  }
}



