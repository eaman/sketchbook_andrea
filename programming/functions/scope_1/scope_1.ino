
boolean sposato = 1 ;
void setup(){
  Serial.begin(9600);
}

void loop() {
Serial.print("In standard mode sposato = ");
Serial.println(sposato);

Serial.print("In vacanza mode sposato = ");
Serial.println(inVacanza(sposato));

Serial.print("Tornato a casa sposato = ");
Serial.println(sposato);
Serial.flush();
exit(0);
}

// Funzioni

boolean inVacanza(boolean sposato){
  sposato = 0 ;
  return sposato;
}

