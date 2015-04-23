void setup(){
  Serial.begin(9600);
}

void loop() {
int latoA = 4;
int latoB = 3 ;

Serial.print("Area rettangolo = ");
Serial.println(calcolaArea(latoA, latoB));


Serial.flush();
exit(0);
}

// Funzioni

int calcolaArea(int a, int b){
  int area = a * b ;
  return area;
}

