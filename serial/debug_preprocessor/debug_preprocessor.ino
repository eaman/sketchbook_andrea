/*
  Debug con macro per il preprocessore
 
 Blink v1
 
 Accensione e spegnimanto di un LED utilizzando variabili
 per impostare la velocita' del lampeggio.
 
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int breve = 200;  // Variabile richiambile nel corso dell'esecuzione

#define DEBUG
// Debug
#ifdef DEBUG
  #define DEBUG_PRINT(x)       Serial.print (x)
  #define DEBUG_PRINTDEC(x)    Serial.print (x, DEC)
  #define DEBUG_PRINTLN(x)     Serial.println (x)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTDEC(x)
  #define DEBUG_PRINTLN(x) 
#endif 

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  DEBUG_PRINTLN("Stato HIGHT");
  delay(breve);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  DEBUG_PRINTLN("Stato LOW");
  delay(breve);               // wait for a second
}


