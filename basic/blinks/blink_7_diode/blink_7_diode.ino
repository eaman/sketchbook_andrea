/*
  Blink v7: diodi
 
 Accensione e spegnimanto di 2 LED invertendo il verso di percorrenza
 della corrente elettrica.
 
 Nel circuito metteremo un LED sul pin 2 e un altro sul pin 3,
 i due LED con una resistenza in serie saranno collegati ai due LED
 (il piede + del primo LED sul pin 2 e il piedino - sul pin 3,
 viceversa per l'altro LED.
 
 Sostanzialmente e' un circuito a corrente alternata.
 
 Schema: http://lab.piffa.net/schemi/diodi_bb.png
 
 Ricordarsi di usare una resistenza da ~320ohms per i LED.
 Resistenza = (Voltaggio_Arduino - Forward_voltage_LED) / (ampere utilizzati)
 R = (5v-1.8v) / 0.010a 
 R =320ohms
 
 This example code is in the public domain.
 */


int two = 2; // Pin per i LED
int tree = 3; // Pin per i LED
int pause = 200;  // Variabile richiambile nel corso dell'esecuzione


void setup() {                
  pinMode(two, OUTPUT); // Abilitaiamo entrambi i LED, questo comporta
    // collegarli dalla resistenza interna!  
  pinMode(tree, OUTPUT);
}


void loop() {
  digitalWrite(two, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(tree, LOW);    // turn the LED off by making the voltage LOW
  delay(pause);               // wait for a second

  digitalWrite(two, LOW);       // turn the LED off by making the voltage LOW
  digitalWrite(tree, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(pause);               // wait for a second
}



