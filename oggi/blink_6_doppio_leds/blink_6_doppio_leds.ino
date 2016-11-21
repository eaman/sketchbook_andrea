/*
  Blink v5
 
 Accensione e spegnimanto di 2 LED.
 Nel circuito oltre al LED montato direttamente sul pin 13
 viene aggiunto un altro LED pilotato dal PIN 12.
 
 Ricordarsi di usare una resistenza da ~320ohms per il secondo LED.
 Resistenza = (Voltaggio_Arduino - Forward_voltage_LED) / (ampere utilizzati)
 R = (5v-1.8v) / 0.010a 
 R =320ohms
 

 Schema: http://lab.piffa.net/schemi/led_single_bb.png
 - http://lab.piffa.net/schemi/led_single_schem.png

  This example code is in the public domain.
 */


int led = 13;     // Il LED onboard corrisponde al PIN 13
                  // Ha una resistenza premontata
int red = 12;     // Definiamo un altro led
int breve = 200;  // Variabile richiambile nel corso dell'esecuzione
int lunga = 1000;

// /////////////////
// Setup: eseguita una volta sola all'accensione della scheda
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT); // Abilitaiamo entrambi i LED     
  pinMode(red, OUTPUT);
}

// ///////////////
// loop: Le istruzioni vengono eseguite all'infinito
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(breve);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(breve);               // wait for a second

  digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(lunga);               // wait for a second
  digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
  delay(lunga); 
}

/* Domande
 *  
 *  1. Creare una funzione che sia slegata dal PIN con cui interagisce.
 *  
 *  2. Come procede il flusso delle istruzioni per far brillare i LED?
 *     E' possibile far brillare i LED indipendentemente l'uno dall'altro?
 *     
 *     
 *     Nota: la risposta alla domanda 2 arrivera' a fine corso!
 */






 
