/*
   PWM Stati
 
   PWM per un LED: impostare i valori di luminosita' di un LED.
   4 stati di luminosita' per un LED collegato a un PIN PWM

   Il PWM del 328p simula un convertitore digitale -> analogico
   con profondita' di 8 bit: 256 valori da 0 - 255 .
   
 */

const int led  = 9   ;     // Il pin ~9 e' abilitato al PWM
const int pausa = 2000; // Pausa tra uno stato e l'altro

void setup()  { 
  pinMode(led, OUTPUT); // Il PIN nove va dichiarato come un OUTPUT
} 

void loop()  { 
  // OUTPUT al 100% : 255
  analogWrite(led, 255) ; 
  delay(pausa);

  // OUTPUT al 75% : 191
  analogWrite(led, 191) ; 
  delay(pausa);
  
  // OUTPUT al 50% : 127
  analogWrite(led, 127) ; 
  delay(pausa);
  
  // OUTPUT al 25%: 63
  analogWrite(led, 63 ) ; 
  delay(pausa);

  // OUTPUT al 0%
  analogWrite(led, 0) ;
  delay(pausa);
}
