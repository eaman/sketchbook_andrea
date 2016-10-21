/*
  Blink v7: diodi
 
 Accensione e spegnimanto di 2 LED invertendo il verso di percorrenza
 della corrente elettrica con un solo PIN di OUTPUT.
 
 
Schema: http://www.pighixxx.com/test/portfolio-items/light-two-leds/?portfolioID=610
 
 Ricordarsi di usare una resistenza da ~320ohms per i LED.
 Resistenza = (Voltaggio_Arduino - Forward_voltage_LED) / (ampere utilizzati)
 R = (5v-1.8v) / 0.010a 
 R =320ohms
 
 This example code is in the public domain.
 */


int led = 2; // Pin per i LED
int pause = 200;  // Variabile richiambile nel corso dell'esecuzione


void setup() {                
  pinMode(led, OUTPUT); // Abilitaiamo entrambi i LED, questo comporta
    // collegarli dalla resistenza interna!  
}


void loop() {
  digitalWrite(led, HIGH);   // turn the 1st LED on (HIGH is the voltage level)
  delay(pause);               // wait for a second

  digitalWrite(led, LOW);       // turn the 2nd LED on by making the voltage LOW
  delay(pause);               // wait for a second
}


/* Domande
 * 
 1. Quanti stati sono disponibili per i LED ?
 2. Sarebbe possibile spegnere conemporaneamente entrambi i LED?







































	Risposte:
	1. Be' un digital out puo' essere a 0 oppure 5v.
	
















	2. Si: trasformando il PIN da OUTPUT a INPUT questo diventerebbe
	ad alta impendenza impedendo anche il DRAIN di corrente.
	Da un punto di vista fisico si potrebbe lavorare sul tempo di attivazione
	del LED: facendo oscillare il pin a una frequenza superiore al periodo
    necessario di attivazione del LED si potrebbe impedire l'accensione
	anche come UOTPUT.

*/
