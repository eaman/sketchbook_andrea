/*
   Stato di un bottone
 
 Legge lo stato di un input
 
 */
int led = 13;
int buttonPin = 2;              
int statoAttuale;                        // variable for reading the pin status
int ultimoStato;                // variable to hold the last button state
int ledStatus;             // varabile per mantenere lo stato del led

void setup() {
  pinMode(buttonPin, INPUT);    // Set the switch pin as input
  pinMode(led, OUTPUT);    
  Serial.begin(9600);           // Set up serial communication at 9600bps
  ultimoStato = digitalRead(buttonPin);   // read the initial state
  ledStatus = 0;
}

void loop(){
  statoAttuale = digitalRead(buttonPin);      // read input value and store it in var
  delay(20);                      // riduce l'effetto bounce
  if (statoAttuale != ultimoStato && statoAttuale == HIGH) {         
    // the button state has changed AND the button is pressed
      Serial.println("Button premuto");
    
      ledStatus = !ledStatus ;    // Inverte lo stato del LED 
      // ledStatus = 1 - ledStatus ;    // Forma analoga
      
      Serial.print("Stato del LED: ");  // DEBUG
      Serial.println(ledStatus) ;
  }

  ultimoStato = statoAttuale;                 // save the new state in our variable
  digitalWrite(led, ledStatus);      // setta il led allo stato richiesto

}



