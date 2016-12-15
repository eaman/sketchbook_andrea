/*
  Blink v1

  Accensione e spegnimanto di un LED utilizzando variabili
  per impostare la velocita' del lampeggio.
  
 */

// Pin 13 ha un LED collegato di default 
int led = 13;

void setup() {                
  // Inizializziamo il PIN 13 come OUTPUT
  pinMode(led, OUTPUT);     
}

void loop() {
  digitalWrite(led, HIGH);   
  delay(1000);              
  digitalWrite(led, LOW);  
  delay(1000);            
}

/* Domande
 1. Aggiungere un secondo LED e farlo brillare ogni 500ms
 mentre il primo brilla ogni 1000ms
 2. Cosa succederebbe se dovessi anche leggere un input da un sensore / bottone?
 */

