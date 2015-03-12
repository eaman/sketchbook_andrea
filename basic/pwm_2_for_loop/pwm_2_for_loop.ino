/*
    LED for PWM
 
 PWM per un LED: aumentare progressivamente la luminosita'.
 Utilizzo di un ciclo iterativo: for loop
 
 */

int led = 9; // Pin per il PWM

void setup()
{
  pinMode(led, OUTPUT);

}

void loop()
{
  for ( i = 0; i < 255 ; i++) { // Operatore ternario, 3 argomenti:
  /* 1. definizione iteratore
     2. limite iteratore
     3. incremento operatore
     */
    analogWrite(led, i) ;
    delay(5 );
  }
  // Ora l'inverso
  for ( c = 255; c > 0 ; c--) {
    analogWrite(led, c) ;
    delay(5 );
  }
}




