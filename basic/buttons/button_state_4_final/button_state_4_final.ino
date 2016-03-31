/*
   Stato di un bottone
 
 Legge lo stato di un input
 
 */
const int led = 13;
const int buttonPin = 2;              
boolean  statoAttuale;          // Variabile per leggere lo stato del bottone
boolean ultimoStato;           // Variabile per registrare l'ultimo stato del bottone

void setup() {
  pinMode(buttonPin, INPUT);          // Set the switch pin as input
  pinMode(led, OUTPUT);    
  ultimoStato = digitalRead(buttonPin);   // Prima lettura del bottone 
}

void loop(){
  statoAttuale = digitalRead(buttonPin);      // Legge lo stato del bottone e lo resistra in val
  delay(20);                                  // riduce l'effetto bounce
  if (statoAttuale != ultimoStato && statoAttuale == HIGH) { // due condizione contemporanee
    // lo stato del bottone e' camabiato AND lo stato attuale e' HIGH
      digitalWrite(led, !(digitalRead(led)));      // Il processore setta lo stato di un led
      // impostando il relativo PIN: possiamo leggere il relativo registro allo stesso modo di un bottone.
  }

  ultimoStato = statoAttuale;        // Aggiorna lo stato finale al valore attuale
}



/* Domande:

 1. La variabile ledstatus serve per tenere traccia dello stato del LED: 
    si potrebbe fare a meno di questa? 
    Cosa fa Arduino quando deve accendere o spegnere un LED?
    Come funziona DigiralRead() ?

 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 Soluzione:

 1. Per accendere o spegnere un LED Arduino imposta il valore del registro corrispondente
    al PIN: se questo e' 0 il circuito e' aperto mentre se e' 1 il circuito e' chiuso.
    Allo stesso modo con DigitalRead() e' possibile leggere lo stato di quel regustro
    e conoscere se il LED e' acceso o spento.    
 */
