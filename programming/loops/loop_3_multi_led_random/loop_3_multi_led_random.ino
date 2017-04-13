/*
  Random Rainbow
  
  Generazione di un numero casuale per modificare il flusso del programma.
  
 

 
 The circuit:
 * LEDs from pins 2 through 9 to ground
 
 Schemi:
 - http://lab.piffa.net/schemi/8_led_single_res_bb.png
 - http://lab.piffa.net/schemi/8_led_single_res_schem.png
 
 http://www.arduino.cc/en/Tutorial/ForLoop
 */

byte ledPins[8] = {  // Domanda: cosa succede se uso int?
  2,3,4,5,6,7,8,9
  }; //Array
int timer = 100;           // Pausa per far brillare i LED
int randNumber ;

void setup() {
  Serial.begin(9600);
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 0; thisPin < sizeof(ledPins); thisPin++)  {
    pinMode(ledPins[thisPin], OUTPUT);
    Serial.print("Inizializzato pin n. ");
    Serial.println(  thisPin);
  }

  Serial.print("Dimesione array: ");
  Serial.println(sizeof(ledPins));
  
  randomSeed(analogRead(0));  // Rilevazione di un valore esterno
 // per scegliere il primo elemento del pseudorandom generators
}

void loop() {
  // print a random number from 0 to 7
  randNumber = random(8);
  // turn the pin on:
  Serial.print("Accensione pin  n. ");
  Serial.println(randNumber);
  digitalWrite(ledPins[randNumber], HIGH);  
  delay(timer);                  
  // turn the pin off:
  digitalWrite(ledPins[randNumber], LOW);    

  if (randNumber == 0) {
    rainbow() ;
  }
}

////////////////
// Funzioni

void rainbow() {
  // Esegue un pattern con i led
  
  Serial.println(">>> Rainbow! <<<");
    // loop from the lowest pin to the highest:
  for (int thisPin = 0; thisPin < sizeof(ledPins); thisPin++) {
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);  
    delay(timer / 2);                  
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);    
  }

  // loop from the highest pin to the lowest:
  for (int thisPin = sizeof(ledPins) -1 ; thisPin > 0; thisPin--) {
    // ><<turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer / 3);
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);
  }
}





