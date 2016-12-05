/*
   Fade
 
   PWM per un LED: aumentare progressivamente la luminosita'
   utilizzando un ciclo while e l'overflow di un byte.

    Schema: http://lab.piffa.net/schemi/led_single_bb.png
    (Cambiare PIN)
 */

const byte led  = 9   ; // Il pin ~9 e' abilitato al PWM
byte brightness = 0;    // Valore iniziale per il PWM del LED
                        // Perche' brightness non e' una costante?

// the setup routine runs once when you press reset:
void setup()  { 
  pinMode(led, OUTPUT); // Il PIN nove va dichiarato come un OUTPUT
} 

void loop()  { 
  analogWrite(led, brightness);  // La funziona analogWrite utilizza il PWM
  // a 8 bit integrato nel MCU: simula un serie di valori intermedi
  // nell'intervallo discreto con minimo 0 (spento) e  massimo 255 (acceso).         
  delay(10);       
  brightness = brightness + 1; // Incrementiamo la luminosita'
}

/* Domande:

1. Come fare a invertire la dissolvenza diminuendo la luminosita'?
2. Provare a far salire e poi scendere la luminosita'

*/
