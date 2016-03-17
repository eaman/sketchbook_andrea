/*
   PWM Stati
 
   PWM per un LED: impostare i valori di luminosita' di un LED.
   4 stati di luminosita' per un LED collegato a un PIN PWM
   
 */

const int led  = 9   ;     // Il pin ~9 e' abilitato al PWM
byte brightness = 255;  // Valore iniziale per il PWM del LED
const int pausa = 2000; // Pausa tra uno stato e l'altro

void setup()  { 
  pinMode(led, OUTPUT); // Il PIN nove va dichiarato come un OUTPUT
} 

void loop()  { 
  // Ledd al 100% : 255
  analogWrite(led, brightness) ; 
  delay(pausa);

  // Ledd al 75% : 191
  analogWrite(led, brightness * 0.75) ; 
  delay(pausa);
  
  // Ledd al 50% : 127
  analogWrite(led, brightness * 0.5) ; 
  delay(pausa);
  
  // Ledd al 25%: 63
  analogWrite(led, brightness * 0.25 ) ; 
  delay(pausa);

  // Ledd al 0%
  analogWrite(led, brightness * 0) ;
}
