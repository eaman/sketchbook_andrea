/* Knight Rider 2
 
 Array e uso dei cicli iterativi.
 Gli array sono omogeni: possono contenere solo dati dello stesso tipo.
 Per l'uso avanzato degli array puo' essere utile approfondire l'uso dei pointers
 (in particolare per passare un array a una funzione).


   Schema semplificato:
   - http://lab.piffa.net/schemi/8_led_single_res_bb.png
   - http://lab.piffa.net/schemi/8_led_single_res_schem.png
 */

int pinArray[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int timer = 100;

void setup() {
  // we make all the declarations at once
  for (int count = 0; count < 9; count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}

void loop() {
  for (int count = 0; count < 8; count++) { // 8 e' un numero magico
    digitalWrite(pinArray[count], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer);
  }

  // Ciclo inverso: dall'alto in basso
  for (int count = 8; count >= 0; count--) {
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
 1. Utilizzare continue con un ciclo if, oppure eliminare un elemento dall'Array.
 2. Utilizzare break
 3. Utilizzare un variabile sarebbe gia' un inizio, ancora meglio estrarre il
    valore tramite la funzione sizeof().
Links:
- http://www.tutorialspoint.com/cprogramming/c_continue_statement.htm
- https://www.arduino.cc/en/Reference/Sizeof
*/


