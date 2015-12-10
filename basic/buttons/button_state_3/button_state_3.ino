/*
   Stato di un bottone
 
 Legge lo stato di un input
 
 */

int switchPin = 2;              // switch connesso al pin 2
                                // Nota: le prossime due variabili sono 
                                // solo "definite" e non "inizializzate"
int statoAttuale;               // Variabile per leggere lo stato del bottone
int ultimoStato;                // Variabile per registrare l'ultimo stato del bottone

void setup() {
  pinMode(switchPin, INPUT);    // Set the switch pin as input

  Serial.begin(9600);           // Set up serial communication at 9600bps
  ultimoStato = digitalRead(switchPin);   // read the initial state
}


void loop(){
  statoAttuale = digitalRead(switchPin);      // Legge lo stato del bottone e lo resistra in val
   delay(20);                                 // riduce l'effetto bounce
  if (statoAttuale != ultimoStato) { 
      // verifica due condizioni che devono realizzarsi contemporaneamente
    if (statoAttuale == HIGH) {               // il bottone e' stato premuto
      Serial.println("Bottone premuto");
    } 
    else {                                    // il bottone non e' premuto...
      Serial.println("Bottone rilasciato");
    }
  }

  ultimoStato = statoAttuale;                 // Aggiorna lo stato finale al valore attuale
}

/* Domande:

 1. Cosa succde se non uso un delay(20) alla lettura del bottone?
 2. Implementare un LED che passa dallo stato acceso a spento quando viene premuto il bottone.
 3. Quanti stati ha il LED?
 4. Sarebbe possibile passare rapidamente da uno stato all'altro?
 
 */
 
