/*
  Blink con funzioni.
  
  Le funzioni sono una sequenza di istruzione raggruppate appunto in un a funzione.
  Le funzioni possono accettare argomenti e avere questi pre-impostati a valori di default se omessi.
  Le funzioni possono limitarsi a svolgere istruzionioppure elaborare valori restituendo un risultato.
  
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
void lunga() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);     // wait for a second
}

void breve() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);     // wait for a second

}

void varia(int a = 1000) { // Varia has a default value, the user can override it with an argument
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(a);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);     // wait for a second

}

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  lunga() ;
  lunga() ;
  breve();
  breve();
  varia(3000);


}

