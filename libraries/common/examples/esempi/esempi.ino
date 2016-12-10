/* Esempi Vari

Vari esempi di utilizzo della libreria.
*/

#include <common.h>

// Lampeggio con valore automatico
Lampeggiatore lamp = 4 ;

// Due LED con lampeggio alternato:
Lampeggiatore right = 3;
Lampeggiatore left = 5;

void setup() {
  left.Invert(); // Parte da stato invertito rispetto al default
}

void loop() {
// Lampeggio con valore automatico
    lamp.Blink()
    lamp.Blink(300); // Lampeggia ogni 300ms
    lamp.Blink(300,100); // Lampeggia per 300ms HIGH, 100ms LOW

  // Due LED con lampeggio alternato:
  right.Blink();
  left.Blink();
}
