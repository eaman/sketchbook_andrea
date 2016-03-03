/*
   Fade sali e scendi
 
   PWM per un LED: aumentare progressivamente la luminosita'.
   Aumenta e diminuisce la luminostia' usando un ciclo while
 */

byte led  = 9   ;     // Il pin ~9 e' abilitato al PWM
byte brightness = 0;  // Valore iniziale per il PWM del LED

// the setup routine runs once when you press reset:
void setup()  { 
  pinMode(led, OUTPUT); // Il PIN nove va dichiarato come un OUTPUT
} 

void loop()  { 
    while (brightness < 255) {
  analogWrite(led, brightness);  // La funziona analogWrite utilizza il PWM
  // a 8 bit integrato nel MCU: simula un serie di valori intermedi
  // nell'intervallo discreto con minimo 0 (spento) e  massimo 255 (acceso).         
  delay(10);       
  brightness = brightness + 1; // Incrementiamo la luminosita'
    }

    while (brightness > 0) {
  analogWrite(led, brightness);  // La funziona analogWrite utilizza il PWM
  delay(10);       
  brightness = brightness - 1; // Decrementiamo la luminosita'
    }


}
/*
- basic/pwm/pwm_3_fade_reverser/pwm_3_fade_reverser.ino
E molto piu' snello utilizzando il solo ciclo loop come iteratore
e una condizione per cambiare l'incremento
*/
