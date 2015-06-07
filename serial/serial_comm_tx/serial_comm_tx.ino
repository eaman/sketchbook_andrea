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
  pinMode(input, INPUT_PULLUP);        // Il PIN e' attivato come output
  
  Serial.begin(9600); // Attiviamo la seriale
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(input) == LOW) { // Verifica se il bottone e' premuto
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

/* Domande
Una connessione analogica permette di passare un solo tipo di segnale
con eventuale modulazione (8bit in output da PWM e 10bit di scansione 
come analog input).

- Quanti tipi di dati permette di trasmettere la seriale?
- Comandare un LED RGB via PWM via seriale (da una Arduino o da un PC).
- Che caratteristiche di latenza si hanno rispetto 
  a una connessione analogica?
- Rifare lo sketch utilizzando una STATE MACHINE: quando il
  il LED viene ACCESO / SPENTO alternativamente alla pressione
  del bottone.
*/

