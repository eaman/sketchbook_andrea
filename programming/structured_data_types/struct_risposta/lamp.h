/* Lamp Header
 *  
 *  Senza un file Header Arduino IDE non ne vuole sapere
 *  di riconosce un data type custom da utilizzare con una funzione.
 */
 
#include <Arduino.h> // Senza non si possono usare i byte, digitaWrite...

struct lampeggino {
  byte pin ;
  long pausa;
  char feedback[20]; // Messaggio via seriale
} ;

void lampeggia (lampeggino oggetto) {
    // Lampeggia e manda un feedback via seriale

    digitalWrite(oggetto.pin, !digitalRead(oggetto.pin));
    Serial.println(oggetto.feedback);
    delay(oggetto.pausa);
}
