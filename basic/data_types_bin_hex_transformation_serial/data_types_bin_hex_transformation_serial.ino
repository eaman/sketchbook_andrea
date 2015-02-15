void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {

  transforma(5);  // Leggete i risultati con [CTR]+[SHIFT]+M
  transforma(255);

  Serial.flush() ;
  exit(0); // Termina l'esecuzione
}

// Ignorate pure il resto del listato!

/* Transforma
 
 Scrive su seriale il valore della variabile a
 trasformandolo in binario e esadecimale
 */

void transforma(int var) {
  Serial.print("Valore in decimanle = ");
  Serial.println(var); // Serial.println(a, DEC);

  Serial.print("Valore in binario = ");
  Serial.println(var,BIN);

  Serial.print("Valore in esadecimanle = ");
  Serial.println(var,HEX);

  Serial.println();
}





