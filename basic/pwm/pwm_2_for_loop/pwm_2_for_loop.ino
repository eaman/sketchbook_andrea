/*
    LED for PWM
 
 PWM per un LED: aumentare progressivamente la luminosita'.
 Utilizzo di un ciclo iterativo: for loop
 
 */

int led     = 9; // Pin per il PWM
int pausa   = 5; 

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 255 ; i++) { // Operatore ternario, 3 argomenti:
  /* 1. definizione iteratore
     2. limite iteratore
     3. incremento operatore
     */
    analogWrite(led, i) ;
    delay(pausa);
  }
  // Ora l'inverso
  for (int c = 255; c > 0 ; c--) {  // Domanda: 1. avrei potuto usare come 
                                    // variabile di nuovo i ?
    analogWrite(led, c) ;
    delay(pausa);
  }
}

/* Domande:
 2. I due loop sembrano molto simili: e' possibile accorparli?

 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 .
 - Risposte:
 1. Si, le variabili i e c esistono solo nello scopo degli iteratori
    in cui sono dichiarate.
 2. Vedi es. suciessivo.
 */




