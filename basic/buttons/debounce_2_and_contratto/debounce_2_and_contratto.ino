/*
   Stato di un bottone
 
 Legge lo stato di un input
 
 */
int led = 13;
int buttonPin = 2;              
int statoAttuale;                        // variable for reading the pin status
int ultimoStato;                // variable to hold the last button state
int ledStatus = 0;             // varabile per mantenere lo stato del led

long ultimoCambio = 0;  // Momento in cui e' stato attivato il PIN input
long debounceDelay = 100;    // Tempo di debounce

void setup() {
  pinMode(buttonPin, INPUT);    // Set the switch pin as input
  pinMode(led, OUTPUT);    
  Serial.begin(9600);           // Set up serial communication at 9600bps
  ultimoStato = digitalRead(buttonPin);   // read the initial state
}

void loop(){
  statoAttuale = digitalRead(buttonPin);      // read input value and store it in var

  if (statoAttuale == HIGH && statoAttuale != ultimoStato && millis() - ultimoCambio > debounceDelay ) {
    // 
    Serial.println("Button premuto");

    ledStatus = !ledStatus ;    // Inverte lo stato del LED 
    Serial.print("Stato del LED: ");  // DEBUG
    Serial.println(ledStatus) ;
    ultimoCambio = millis() ;    // Registra il tempo attuale
  } 

  //  Serial.print("statoAttuale ");
  //  Serial.println(statoAttuale);
  //  Serial.println(ultimoStato);
  //delay(400);
  ultimoStato = statoAttuale;                 // save the new state in our variable
  digitalWrite(led, ledStatus);      // setta il led allo stato richiesto


}








