/* Blink without Delay
 
 Struct con pointer
 
 La funzione lightLed() ora passa un pointer alla posizione di memoria
 della struttura dati ledA / ledB, non viene fatta una copia di
 tutto lo struct ledA --> temp per poi far tornare (return(temp))
 una struttura aggiornate di temp che vera' nuovamente copiata 
 sull'originale ledA.
 
 Viene fatta un pass by reference e non un pass by value,
 vengono usate meno risose di calcolo e meno memoria.
 */

struct blinkLed {
  // Lampeggia un LED utilizzando millis()
  // Variabili
  int ledPin ;           // il numero del LED pin
  int ledState ;         // stato attuale del LED
  long interval ;        // milliseconds di intervallo nel lampeggiare
  long previousMillis ;  //precedente cambio di stato  
};
// Instanziamo i due led dalla struttura
blinkLed ledA = {
  13 , LOW , 1000, 0 };
blinkLed ledB = {
  12, LOW, 500, 0};

void setup() {
  pinMode(ledA.ledPin, OUTPUT);
  pinMode(ledB.ledPin, OUTPUT);
}

void loop()
{
 lightLed(&ledA ); // Viene passato il riferimento (Left value) di ledA
 lightLed(&ledB );
}

////////////////
// Funzioni

void lightLed(struct blinkLed *temp) { // temp ora e' un pointer e non una struttura autonoma: pass by reference (not by value)
  // Illumina il ledA secondo un intervallo passato come argomento

  if(millis() - (*temp).previousMillis >= (*temp).interval) { // l'operatore punto ha priorita' maggiore rispetto al pointer asterisco
    (*temp).previousMillis += (*temp).interval ;

    // if the LED is off turn it on and vice-versa:
    temp->ledState = !temp->ledState ; // Forma contratta, deference operator: temp->ledState == (*temp).ledState
  }
  digitalWrite(temp->ledPin, temp->ledState);
  //return(temp); // copy by value
}



