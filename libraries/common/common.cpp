/*  Common
 *
 *  Oggetti di uso comune
 */

#include "Arduino.h"
#include "common.h"


//////////////////////
// RGB LED
// Common anode

RGBLed::RGBLed(byte pinR, byte pinG, byte pinB) {
      redPin    = pinR ;
      greenPin  = pinG ;
      bluePin   = pinB ;

      // Equvalente del Setup() per inizializzare i PIN
      pinMode(redPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
};

void RGBLed::SetColor (byte r, byte g, byte b) {
// Imposta il colore di un LED RGB
      analogWrite(redPin,   r);
      analogWrite(greenPin, g);
      analogWrite(bluePin,  b);
    };

void RGBLed::Red () {
// Accende il LED di rosso
      SetColor(0,255,255);
    };

void RGBLed::Green () {
// Accende il LED di verde
      SetColor(255,0,255);
    };

void RGBLed::Blue () {
// Accende il LED di blu
      SetColor(255,255,0);
    };

void RGBLed::Magenta () {
// Accende il LED di magenta
      SetColor(0,255,0);
    };

void RGBLed::Cyano () {
// Accende il LED di Cyano
      SetColor(255,0,0);
    };

void RGBLed::Yellow () {
// Accende il LED di giallo
      SetColor(0,0,255);
    };

void RGBLed::White () {
// Accende il LED 
      SetColor(0,0,0);
    };

void RGBLed::Off () {
// Spegne il LED 
      SetColor(255,255,255);
    };



/////////////////////////////////////
// Lampeggiatore
// Constructor
Lampeggiatore::Lampeggiatore(int pin)
{
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    ledState = LOW;
    previousMillis = 0;
    interval = 500;
};




// Una funzione facente parte di una classe prende il nome di "metodo" della stessa:
void Lampeggiatore::Blink() {
    // Illumina il led a 500ms

    if(millis() - previousMillis > interval) {
        // save the last time you blinked the LED
        previousMillis = millis();

        // if the LED is off turn it on and vice-versa:
        ledState = !ledState ; // Inverti il LED
    }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
};

void Lampeggiatore::Blink(long time) {
    // Illumina il led secondo un intervallo passato come argomento

    if(millis() - previousMillis > time) {
        // save the last time you blinked the LED
        previousMillis = millis();

        // if the LED is off turn it on and vice-versa:
        ledState = !ledState ; // Inverti il LED
    }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
};

void Lampeggiatore::Blink(long up, long down) {
    // Illumina il ledB precisando ontime e downtime

    if((ledState == HIGH)&& (millis() - previousMillis > up)) {
    // save the last time you blinked the LED
    	previousMillis = millis();
        ledState = LOW  ;
    }
    else if((ledState == LOW)&& (millis() - previousMillis > down)) {
    	previousMillis = millis();
        ledState = HIGH  ;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
};

/////////////////////////////////////
// Pwm
// Constructor
Pwm::Pwm(int pin)
{
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    previousMillis = 0;
    byte brightness = 0 ;
    increment = 1;
};

void Pwm::Up(long speed) {
    // Aumenta progressivamente la luminosita' usanndo millis()
    // quindi senza bloccare il processore

    analogWrite(ledPin, brightness);  // La funziona analogWrite utilizza il PWM
    // a 8 bit integrato nel MCU: simula un serie di valori intermedi
    // nell'intervallo discreto con minimo 0 (spento) e  massimo 255 (acceso).

    if ((millis() - previousMillis) > speed / 256) {
        brightness++; // Incrementiamo la luminosita'
        previousMillis = millis();
    };
}

void Pwm::Down(long speed ) {
    // Riduce progressivamente la luminosita' usanndo millis()
    // quindi senza bloccare il processore

    analogWrite(ledPin, brightness);  // La funziona analogWrite utilizza il PWM
    // a 8 bit integrato nel MCU: simula un serie di valori intermedi
    // nell'intervallo discreto con minimo 0 (spento) e  massimo 255 (acceso).

    if ((millis() - previousMillis) > speed / 256) {
        brightness--; // Incrementiamo la luminosita'
        previousMillis = millis();
    };
}

void Pwm::UD(long speed ) {
    // Aumenta e riduce in sequenza la luminosita' usanndo millis()
    if ((millis() - previousMillis) > speed / 512) {
        brightness = brightness + increment; // Incrementiamo la luminosita'
        previousMillis = millis();
        if (brightness == 0 || brightness == 255) { // Reverse direction
            increment = -increment ;
        };
    };
    analogWrite(ledPin, brightness);
}



//////////////////
// Funzioni


void brilla(byte pin, int velocita ) { // Defalt value di velocita' solo nell'Header
  // Accende e spegne il LED accetando un argomento 
  // per impostare la velocita'.

pinMode(pin, OUTPUT); 
  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(velocita);               // wait for a second
  digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
  delay(velocita);               // wait for a second
};

