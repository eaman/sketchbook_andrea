/* Lamp Header
 *  
 *  Senza un file Header Arduino IDE non ne vuole sapere
 *  di riconosce un data type custom da utilizzare con una funzione.
 */
 
#include <Arduino.h> // Senza non si possono usare i byte, digitaWrite...

struct lampeggino {
  byte pin ;
  long pausa;
   boolean stato;
  char feedback[20]; // Messaggio via seriale
} ;

void lampeggia (lampeggino *oggetto) {
    // Lampeggia e manda un feedback via seriale

    digitalWrite(oggetto->pin, (*oggetto).stato); // foo->bar eqivale a (*foo).bar, l'operatore punto ha precedenza rispetto al pointer
    Serial.println((*oggetto).feedback);
    (*oggetto).stato = !(*oggetto).stato ;
    delay((*oggetto).pausa);
}
