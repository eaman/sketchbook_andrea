/*
   Stato di un bottone
 
 Modifica lo stato di un led in base all'input di un bottone.
 Viene usato un ciclo condizionale ramificato
 e due variabili per confrontare il periodo di pressione del bottone.
 
 */
int led = 13;
int buttonPin = 2;              
int statoAttuale;                        // variable for reading the pin status
int ultimoStato;                // variable to hold the last button state
int ledStatus = 0;             // varabile per mantenere lo stato del led

long ultimoCambio = 0;  // Momento in cui e' stato attivato il PIN input
long debounceDelay = 30;    // Tempo di debounce

void setup() {
  pinMode(buttonPin, INPUT);    // Set the switch pin as input
  pinMode(led, OUTPUT);    
  Serial.begin(9600);           // Set up serial communication at 9600bps
  ultimoStato = digitalRead(buttonPin);   // read the initial state
}

void loop(){
  int lettura = digitalRead(buttonPin);      // read input value and store it in var
  if (lettura != ultimoStato) { // controlla se il bottone ha cambiato stato
    ultimoCambio = millis() ;    // Registra il tempo attuale
  }

  if ((millis() - ultimoCambio) > debounceDelay) { // controllo che il periodo di tempo sia sufficente
    if (lettura != statoAttuale) {        // Il bottone ha cambiato stato
      statoAttuale = lettura;             // Evitiamo che la precedente condizione si ripeta ad oltranza
      if (statoAttuale == HIGH) {                // check if the button is pressed
        Serial.println("Button premuto");

        ledStatus = !ledStatus ;    // Inverte lo stato del LED 
        Serial.print("Stato del LED: ");  // DEBUG
        Serial.println(ledStatus) ;
      } 
    }
  }
  ultimoStato = lettura;                 // save the new state in our variable
  digitalWrite(led, ledStatus);      // setta il led allo stato richiesto

}






