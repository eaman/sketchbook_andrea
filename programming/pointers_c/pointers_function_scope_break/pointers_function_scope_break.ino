int *ptr;  // no rvalue

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  int num =5;
 ptr = &num ;
 
  transforma(num);  // Leggete i risultati con [CTR]+[SHIFT]+M
  Serial.println(num);

  Serial.flush() ;
  exit(0); // Termina l'esecuzione
}

// Ignorate pure il resto del listato!

/* Transforma
 
 Scrive su seriale il valore della variabile a
 trasformandolo in binario e esadecimale
 */

void transforma(int var) {
  Serial.print("Valore della variabile = ");
  Serial.print(var);
  *ptr = 12 ; // Num is outside the scope of this function
              // but a pointer can get there


  Serial.println();
}





