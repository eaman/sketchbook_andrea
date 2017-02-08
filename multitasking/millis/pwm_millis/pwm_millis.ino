/*
   Fade

   PWM per un LED: aumentare progressivamente la luminosita'.
   Utilizza la funzione millis() invece che un delay()
   in modo da non blocare il processore.

   La durata del ciclo e' pero' molto approssimativa in multipli di 256ms
   quindi con errore di +-128ms, inoltre si possono accumulare ulteriori
   ritardi se la funzione non viene eseguita regolarmente ogni ms.
   
 */


// the setup routine runs once when you press reset:
void setup()  {
  pinMode(9, OUTPUT); // Il PIN nove va dichiarato come un OUTPUT
}

void loop()  {

pwmUp(9, 3000);

}

// Funzioni:

void pwmUp(byte led, int speed) {
  // Aumenta progressivamente la luminosita' usanndo millis()
  // quindi senza bloccare il processore

  static byte brightness = 0;  // Valore iniziale per il PWM del LED
  static long previousMillis = 0;
  
  analogWrite(led, brightness);  // La funziona analogWrite utilizza il PWM
  // a 8 bit integrato nel MCU: simula un serie di valori intermedi
  // nell'intervallo discreto con minimo 0 (spento) e  massimo 255 (acceso).

  if ((millis() - previousMillis) > speed / 256) {
    brightness++ ; // Incrementiamo la luminosita'
    previousMillis = millis();
  };
}
