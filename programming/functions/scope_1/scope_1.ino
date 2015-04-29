/*
  Scope
  
  Variabili globali e locali rispetto a una funzione
  Le variabili dichiarate al di fuori di funzioni 
  sono globali e accessibili a tutti,
  
  Le variabili dichiarate all'interno di una funzione 
  sono locali e accessibili solo a questa,
  */


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

// Global
Serial.print("In vacanza global mode sposato = ");
Serial.println(inVacanzaG());

Serial.print("Stato di sposato = ");
Serial.println(sposato);

// Termine programma
Serial.flush();
exit(0);
}

// Funzioni

boolean inVacanza(boolean sposato){ // variabile locale
  sposato = 0 ; 
  return sposato;
}
boolean inVacanzaG(){
  sposato = 0 ; // Variabile globale
  return sposato;
}
