/*
  For Loop with millis()
  
Blink di un array di led in sucessione,
utilizzando millis() per non blocking.
L'array puo' contenere un numero arbitrario di led
(l'ordine in cui compaiono e' l'ordine in cui brillano).

 Schemi:
 - http://lab.piffa.net/schemi/8_led_single_res_bb.png
 - http://lab.piffa.net/schemi/8_led_single_res_schem.png

 http://www.arduino.cc/en/Tutorial/ForLoop
 */

byte ledPins[] = {  // Domanda: cosa succede se uso int?
  9, 10, 11, 12
}
; //Array

long previousMillis ;
long interval = 1000;
byte i = 0;


void setup() {
  for (int thisPin = 0; thisPin < sizeof(ledPins); thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
  previousMillis = millis();
}

void loop() {
  if (millis() - previousMillis > interval) {
    previousMillis = millis();

    if ( i < sizeof(ledPins) - 1 ) {
      // Spegni precedente led
      digitalWrite(ledPins[i], LOW);

      // Accendi successivo led
      digitalWrite(ledPins[++i], HIGH);
    }

    else if  (i == sizeof(ledPins) - 1 )   {
      // Ultimo caso
      i = 0;
      previousMillis = millis();
      digitalWrite(ledPins[i], HIGH);
      digitalWrite(ledPins[ sizeof(ledPins) - 1 ], LOW);
    }
  }
}



