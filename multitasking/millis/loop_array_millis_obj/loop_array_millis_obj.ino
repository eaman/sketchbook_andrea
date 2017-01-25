/*
  For Loop with millis()

Blink di un array di led in sucessione,
utilizzando millis() per non blocking.
L'array puo' contenere un numero arbitrario di led
(l'ordine in cui compaiono e' l'ordine in cui brillano).

OOP version.

 Schemi:
 - http://lab.piffa.net/schemi/8_led_single_res_bb.png
 - http://lab.piffa.net/schemi/8_led_single_res_schem.png

 http://www.arduino.cc/en/Tutorial/ForLoop
 */


class Sequenza {
    // Lampeggia LED in sequenza utilizzando millis()
    unsigned long previousMillis ;
    byte i = 0;
    byte *ledPins;
    byte size;
    long interval;
    
  public:
    Sequenza (byte passed[], byte dim) {
       ledPins = passed ;
       size = dim ;
      for (int thisPin = 0; thisPin < size; thisPin++) {
        pinMode(ledPins[thisPin], OUTPUT);
      }
      previousMillis = millis();
      digitalWrite(ledPins[0], HIGH);
    }

    void Update(long value) {
      interval = value;
      if (millis() - previousMillis >= interval) {
        previousMillis = millis();

        if ( i < size - 1 ) {
          // Spegni precedente led
          digitalWrite(ledPins[i], LOW);

          // Accendi successivo led
          digitalWrite(ledPins[++i], HIGH);
        }

        else if  (i == size - 1 )   {
          // Ultimo caso
          i = 0;
          previousMillis = millis();
          digitalWrite(ledPins[i], HIGH);
          digitalWrite(ledPins[ size - 1 ], LOW);
        }
      }
    }
};



void setup() {
  Serial.begin(9600);
  //Serial.print(seq.ledPins);
};

byte pins[] = {  
  2, 3, 4, 5, 6, 7
}; 

Sequenza seq = Sequenza(pins,sizeof(pins));


void loop() {
  seq.Update(200);
};



