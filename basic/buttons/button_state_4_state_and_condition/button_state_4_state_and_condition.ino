/*
   Stato di un bottone
 
 Legge lo stato di un input
 
 */
int led = 13;
int buttonPin = 2;              
int statoAttuale;          // Variabile per leggere lo stato del bottone
int ultimoStato;           // Variabile per registrare l'ultimo stato del bottone
int ledStatus;             // varabile per mantenere lo stato del led

void setup() {
  pinMode(buttonPin, INPUT);          // Set the switch pin as input
  pinMode(led, OUTPUT);    
  Serial.begin(9600);                 // Attiva la comunicazione seriale a 9600bps
  ultimoStato = digitalRead(buttonPin);   // Prima lettura del bottone
  ledStatus = 0;                          // Il LED viene inpostato come spento  
}

void loop(){
  statoAttuale = digitalRead(buttonPin);      // Legge lo stato del bottone e lo resistra in val
  delay(20);                                  // riduce l'effetto bounce
  if (statoAttuale != ultimoStato && statoAttuale == HIGH) { // due condizione contemporanee
    // lo stato del bottone e' camabiato AND lo stato attuale e' HIGH
      Serial.println("Button premuto");
    
      ledStatus = !ledStatus ;    // Inverte lo stato del LED 
      // ledStatus = 1 - ledStatus ;    // Forma analoga
      
      Serial.print("Stato del LED: ");  // DEBUG
      Serial.println(ledStatus) ;
  }

  ultimoStato = statoAttuale;        // Aggiorna lo stato finale al valore attuale
  digitalWrite(led, ledStatus);      // setta il led allo stato richiesto

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
