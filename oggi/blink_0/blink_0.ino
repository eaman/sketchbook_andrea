// 1. ////////////
// Commento iniziale multi linea
/*
  Blink 

  Accensione e spegnimanto di un LED utilizzando variabili
  per impostare la velocita' del lampeggio.
  
 */
 
// 2. //////////////
// Dichiarazione variabili
// 
int led = 13; // Il LED onboard corrisponde al PIN 13
              // Ha una resistenza premontata

// 3. /////////////////
// Setup: eseguita una volta sola all'accensione della scheda
void setup() {                
  pinMode(led, OUTPUT); // Abilita il PIN del LED come OUTPUT in modo che
                        // possa essere acceso    
}

// 4. ///////////////
// loop: Le istruzioni vengono eseguite all'infinito
void loop() {
  digitalWrite(led, HIGH);  // Mette il PIN del LED in stato acceso
  delay(1000);              // Aspetta un secondo (mille millisecondi)
  digitalWrite(led, LOW);   // Mette il PIN del LED in stato spento
  delay(500);               // Aspetta mezzo secondo
}
