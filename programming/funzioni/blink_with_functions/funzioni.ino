// Funzioni personalizzate
// Un scheda e' un documento che viene concatenato allo sketch originale

void lunga() {
  // Blink con pausa lunga
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);     // wait for a second
}

void breve() {
    // Blink con pausa breve
    
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);     // wait for a second
}

void varia(int a = 300) { // Varia has a default value, the user can override it with an argument
  // Lampeggia per un tempo impostato dall'utente,
  // il default e' 300ms
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(a);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(a);     // wait for a second

}

void lampeggia(int ripetizioni) {
  // Accende un LED per un numero stabilito di volte

  // Questa funziona accetta un parametro: ripetizioni
  int i = 0;
  while (i < ripetizioni) {
    rapido();   // accende e spegne rapidamente il LED
    i = i + 1 ; // incrementa l'iteratore
 // i++ ;       // equivalente
  }
}

int area(int latoA, int latoB) { 
  // Calcola l'area di un rettangolo
  // e ritorna il valore calcolato: questa funzione ha un valore di ritorno
  // dichiarato come int
  
  return(latoA * latoB);
}
