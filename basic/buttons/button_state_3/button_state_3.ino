/*
   Stato di un bottone
 
 Legge lo stato di un input
 
 */

int switchPin = 2;              // switch connesso al pin 2
int statoAttuale;               // Variabile per leggere lo stato del bottone
int ultimoStato;                // Variabile per registrare l'ultimo stato del bottone

void setup() {
  pinMode(switchPin, INPUT);    // Set the switch pin as input

  Serial.begin(9600);           // Set up serial communication at 9600bps
  ultimoStato = digitalRead(switchPin);   // read the initial state
}


void loop(){
  statoAttuale = digitalRead(switchPin);      // Legge lo stato del bottone e lo resistra in val
   delay(20)                                // riduce l'effetto bounce
  if (statoAttuale != ultimoStato) {          // lo stato del bottone e' cambiato
    if (statoAttuale == HIGH) {               // il bottone e' stato premuto
      Serial.println("Bottone premuto");
    } 
    else {                         // the button is -not- pressed...
      Serial.println("Bottone rilasciato");
    }
  }

  ultimoStato = statoAttuale;                 // Aggiorna lo stato finale al valore attuale
}

