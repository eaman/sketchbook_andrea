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
int statoAttuale;                        // variable for reading the pin status
int ultimoStato;                // variable to hold the last button state
long ultimoCambio = 0;  // Momento in cui e' stato attivato il PIN input
long debounceDelay = 100;    // Tempo di debounce

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);       // Il PIN e' attivato come output
  pinMode(input, INPUT_PULLUP);        // Il PIN e' attivato come output
  
  Serial.begin(9600); // Attiviamo la seriale
}

// the loop routine runs over and over again forever:
void loop() {
  statoAttuale = digitalRead(input);      // read input value and store it in var

  if (statoAttuale == LOW && statoAttuale != ultimoStato && millis() - ultimoCambio > debounceDelay ) {
    // 
    Serial.write(1); // Invia il dato via seriale
    //Serial.write(49); // Invia il dato via seriale: 49 e' ASCII per 1
    //Serial.print(1); // Invia il dato via seriale in ASCII 
    
     ultimoCambio = millis() ;    // Registra il tempo attuale
  }
  ultimoStato = statoAttuale;                 // save the new state in our variable
  Serial.flush();
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
- Dove dovremo implementare il DEBOUNCE?
- Dove implementare la gestione dello STATO?

HINT: Vedere lo script basc/buttons/debounce-2_and_contratto
*/

