/*
   Stato di un bottone
 
 Legge lo stato di un input
 
 */

int switchPin = 2;              // switch is connected to pin 2
int statoAttuale;                        // variable for reading the pin status
int ultimoStato;                // variable to hold the last button state

void setup() {
  pinMode(switchPin, INPUT);    // Set the switch pin as input

  Serial.begin(9600);           // Set up serial communication at 9600bps
  ultimoStato = digitalRead(switchPin);   // read the initial state
}


void loop(){
  statoAttuale = digitalRead(switchPin);      // read input value and store it in val
  // delay(20)                      // riduce leffetto bounce
  if (statoAttuale != ultimoStato) {          // the button state has changed!
    if (statoAttuale == HIGH) {                // check if the button is pressed
      Serial.println("Bottone premuto");
    } 
    else {                         // the button is -not- pressed...
      Serial.println("Bottone rilasciato");
    }
  }

  ultimoStato = statoAttuale;                 // save the new state in our variable
}

