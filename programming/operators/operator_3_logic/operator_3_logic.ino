/*
  Operatori boleani binari, operatori logici
 Comparison operators, binary
 
 */

int a = 5;
int b = 10;
int c = 20;


void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps

  Serial.println("Here is some math: ");

  Serial.print("a = ");
  Serial.println(a);
  Serial.print("b = ");
  Serial.println(b);
  Serial.print("c = ");
  Serial.println(c);

  Serial.print("a < b AND a < c : ");       // And logico
  Serial.println(a < b && a < c);

  Serial.print("b < a OR  c < a : ");       // Or logico
  Serial.println(b < a ||  c < a);

  Serial.print("a == b : ");       // stesso valore
  Serial.println(a == b);

  Serial.print("a != b : ");       // valore diverso
  Serial.println(a != b);

// Testiamo direttamente le singole entita':

  Serial.print("true AND true: ");       // And logico
  Serial.println(true && true);

  Serial.print("true AND false: ");       // And logico
  Serial.println(true && false);

  Serial.print("true OR false: ");       // Or logico
  Serial.println(true || false);

  Serial.print("false OR false: ");       // Or logico
  Serial.println(false || false);
}

void loop()                     // we need this to be here even though its empty
{
}



