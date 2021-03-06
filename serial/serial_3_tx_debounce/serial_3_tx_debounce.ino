/*
  Serial comm: TX
 
 Comunicazione seriale tra due schede arduino.
 La prima scheda ha un bottone come input e 
 comunica con un altra scheda che monta un LED come output.
 Il led della seconda si accende quando rileva
 la pressione del bottone della prima.
 
 Questo script implementa il debounce con Millis(),
 
 Scema: http://lab.piffa.net/schemi/serial_common_bb.png
        http://lab.piffa.net/schemi/serial_common_schem.png
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

1. Che differenza c'e' tra Serial.write() e Serial.print()?
2. Qual'e' il codice ASCII per indicare il numero decimale 1?
3. Servono entrambi i cavi per la connessione?
4. Potrei attaccare una terza arduino?

Links:
- http://www.arduino.cc/en/Serial/Print
- http://www.arduino.cc/en/Tutorial/ASCIITable










Risposte in fondo:
1. Vedere i links proposti: .write scrive un byte mentre
   .print manda un codice ASCII
2. 49
3. No, dato solo il cavo dalla TX alla RX .
   Provare a fare un script con comunicazione bilaterale
4. No perche' non ci sarebbe sincronia tra i segnali,
   vedere gli esercizi su I2C
*/

