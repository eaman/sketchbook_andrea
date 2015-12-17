/* Knight Rider 2
 * --------------
 *
 * Reducing the amount of code using for(;;).
 *
 *
 * (cleft) 2005 K3, Malmo University
 * @author: David Cuartielles
 * @hardware: David Cuartielles, Aaron Hallborg


   Schema semplificato: 
   - http://lab.piffa.net/schemi/8_led_single_res_bb.png
   - http://lab.piffa.net/schemi/8_led_single_res_schem.png
 */

int pinArray[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int count = 0;
int timer = 100;

void setup(){
  // we make all the declarations at once
  for (count=0;count<9;count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}

void loop() {
  for (count=0;count<8;count++) { // 8 e' un numero magico
   digitalWrite(pinArray[count], HIGH);
   delay(timer);
   digitalWrite(pinArray[count], LOW);
   delay(timer);
  }
  for (count=8;count>=0;count--) {
   digitalWrite(pinArray[count], HIGH);
   delay(timer);
   digitalWrite(pinArray[count], LOW);
   delay(timer);
  }
}

/* Domande:
 
 1. Come posso fare per saltare un elemento del loop? 
 2. Come posso fare per uscire completamente dal loop? 
 3. 8 e' un numero magico: come posso evitarlo?

.
.
.
.
.
.
.
.
.
.
.
Soluzioni: 
 1. utilizzare continue
 2. utilizzare break
 3. Utilizzare un variabile sarebbe gia' un inizio, ancora meglio estrarre il
    valore tramite la funzione sizeof().
Links: 
- http://www.tutorialspoint.com/cprogramming/c_continue_statement.htm
- https://www.arduino.cc/en/Reference/Sizeof
*/


