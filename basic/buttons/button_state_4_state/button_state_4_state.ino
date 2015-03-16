/*
   Stato di un bottone
 
 Legge lo stato di un input
 
 */
int led = 13;              // Definizione delle variabili
int buttonPin = 2;              
                           // Dichiarazione di variabili
int statoAttuale;          // Variabile per leggere lo stato del bottone
int ultimoStato;           // Variabile per registrare l'ultimo stato del bottone
int ledStatus;             // varabile per mantenere lo stato del led

void setup() {
  pinMode(buttonPin, INPUT);    
  pinMode(led, OUTPUT);    
  Serial.begin(9600);                 // Attiva la comunicazione seriale a 9600bps
  ultimoStato = digitalRead(buttonPin);   // Prima lettura del bottone
  ledStatus = 0;                          // Il LED viene inpostato come spento                        
}

void loop(){
  statoAttuale = digitalRead(buttonPin);      // Legge lo stato del bottone e lo resistra in val
  delay(20);                                  // riduce l'effetto bounce
  if (statoAttuale != ultimoStato) {          // lo stato del bottone e' cambiato
    if (statoAttuale == HIGH) {               // il bottone e' stato premuto
      Serial.println("Button premuto");
     
      ledStatus = !ledStatus ;          // Inverte lo stato del LED 
      // ledStatus = 1 - ledStatus ;    // Forma analoga
      
      Serial.print("Stato del LED: ");  // DEBUG
      Serial.println(ledStatus) ;
    } 
  }

  ultimoStato = statoAttuale;        // Aggiorna lo stato finale al valore attuale
  digitalWrite(led, ledStatus);      // setta il led allo stato richiesto

}



