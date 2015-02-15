
int *ptrNumber ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  int number = 5;


  Serial.print("number is ");
  Serial.println(number);
  Serial.print("The lvalue for number is: ");
  Serial.println((long) &number, DEC);

  Serial.print("---- Pointer was ");
  Serial.println(*ptrNumber);
  Serial.print("The lvalue for ptrNumber is: ");
  Serial.println((long) &ptrNumber, DEC);
  Serial.print(" and the rvalue is ");
  Serial.println((long) ptrNumber, DEC);

  ptrNumber = &number ;
  Serial.println("Assigned!");

  Serial.print("===== Pointer was ");
  Serial.println(*ptrNumber);
  Serial.print("The lvalue for ptrNumber is: ");
  Serial.println((long) &ptrNumber, DEC);
  Serial.print(" and the rvalue is ");
  Serial.println((long) ptrNumber, DEC);

  *ptrNumber = 6 ;
  Serial.print("**** Pointer value is: ");
  Serial.println(*ptrNumber);
  Serial.println(number);

  Serial.flush();
  exit(0);

}


