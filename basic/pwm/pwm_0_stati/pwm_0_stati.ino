/*
   PWM demo
 
   PWM per un LED: impostare i valori di luminosita' di un LED.
 */

int led  = 9   ;     // Il pin ~9 e' abilitato al PWM
byte brightness = 0;  // Valore iniziale per il PWM del LED
int pausa = 2000; // Pausa tra uno stato e l'altro

void setup()  { 
  pinMode(led, OUTPUT); // Il PIN nove va dichiarato come un OUTPUT
} 

void loop()  { 
  analogWrite(led, 0) ; // spento
  delay(pausa);
  analogWrite(led, 63) ;   // 1/4
  delay(pausa);
  analogWrite(led, 127) ;  // 1/2
  delay(pausa);
  analogWrite(led, 191) ;  // 3/4
  delay(pausa);
  analogWrite(led, 254) ;  // Full light
  delay(pausa);
}
