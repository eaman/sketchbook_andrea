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

void RGBLed::Red () {
// Accende il LED di rosso
      analogWrite(redPin,   0);
      analogWrite(greenPin, 255);
      analogWrite(bluePin,  255);
    };

void RGBLed::Green () {
// Accende il LED di verde
      analogWrite(redPin,   255);
      analogWrite(greenPin, 0);
      analogWrite(bluePin,  255);
    };

void RGBLed::Blue () {
// Accende il LED di blu
      analogWrite(redPin,   255);
      analogWrite(greenPin, 255);
      analogWrite(bluePin,  0);
    };

void RGBLed::Magenta () {
// Accende il LED di magenta
      analogWrite(redPin,   0);
      analogWrite(greenPin, 255);
      analogWrite(bluePin,  0);
    };

void RGBLed::Cyano () {
// Accende il LED di Cyano
      analogWrite(redPin,   255);
      analogWrite(greenPin, 0);
      analogWrite(bluePin,  0);
    };

void RGBLed::Yellow () {
// Accende il LED di giallo
      analogWrite(redPin,   0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin,  255);
    };

void RGBLed::White () {
// Accende il LED 
      analogWrite(redPin,   0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin,  0);
    };

void RGBLed::Off () {
// Spegne il LED 
      analogWrite(redPin,   255);
      analogWrite(greenPin, 255);
      analogWrite(bluePin,  255);
    };

void RGBLed::SetColor (byte r, byte g, byte b) {
      // Imposta il colore di un LED RGB

      analogWrite(redPin,   r);
      analogWrite(greenPin, g);
      analogWrite(bluePin,  b);
    };


//////////////////
// Funzioni

void brilla(byte pin) {
  // Accende e spegne il LED senza un argomento 
  // per impostare la velocita'.
  const int velocita = 500;

pinMode(pin, OUTPUT); 
  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(velocita);               // wait for a second
  digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
  delay(velocita);               // wait for a second
};

void brilla(byte pin, int velocita) {
  // Accende e spegne il LED accetando un argomento 
  // per impostare la velocita'.

pinMode(pin, OUTPUT); 
  // sequenze di istruzione: accendere e spegnere il LED
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(velocita);               // wait for a second
  digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
  delay(velocita);               // wait for a second
};
