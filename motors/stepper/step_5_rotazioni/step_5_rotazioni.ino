/* 
  Step
  
  Utilizzo della libreria Step
  
*/
#include <Stepper.h>
 int passi = 32 ;    // Passi del motore
 int rapporto = 64 ; // Rapporto di riduzione
// numeri di steps * rapporto di riduzione 
    // (usiamo 4 step in full step drive)

//Stepper motore(2048, 8, 10, 9, 11);
Stepper motore(passi,  8, 10, 9, 11); 


void setup() {
  
  
}

void loop()  
{
// Rotazione completa CW
  motore.setSpeed(300);   // Impostiamo la velocita'
  motore.step(passi * rapporto);
  delay(1000);
  
// Rotazione completa Anti-CW
  motore.setSpeed(700);  // Re impostiamo la velocita'
  motore.step(-passi * rapporto);
  delay(2000);
}
