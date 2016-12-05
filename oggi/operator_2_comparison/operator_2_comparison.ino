/*
  Operatori comparativi binari
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

  Serial.print("a > b = ");       // maggiore
  Serial.println(a > b);

  Serial.print("a < b = ");       // minore
  Serial.println(a < b);

  Serial.print("a == b -> ");       // stesso valore
  Serial.println(a == b);

  Serial.print("a != b -> ");       // valore diverso
  Serial.println(a != b);

  Serial.print("a <= b ->");       // minore uguale
  Serial.println(a <= b);

  Serial.print("a >= b -> ");       // maggiore uguale
  Serial.println(a >= b);
}

void loop()                     // we need this to be here even though its empty
{
}


