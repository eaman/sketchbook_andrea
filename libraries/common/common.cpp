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
