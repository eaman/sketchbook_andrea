/*
  Photoresistor
 
 Utilizzare una fotoresistenza come analog input.
 Il comportamento della foto resistenza e' simile
 a un potenziometro: varia la resistenza in base alla 
 quantita' di luce.
 
 Per ottenere valori significativi utilizzare unaresistenza
 da ~5k ohms in serie con il sensore.
 
 Questo sketch modifica l'intervallo di intermittenza di un led
 in base alla luminosita' rilevata.
 */

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

int min = 240;        // valore minimo rilevato dal sensore
int max = 380;        // valore massimo rilevato dal sensore

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);  
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);   
  int calValue = map(sensorValue,min,max,0,1024) ; 
  // Max pausa = 1024 
      // turn the ledPin on
    digitalWrite(ledPin, HIGH);  
  // stop the program for <sensorValue> milliseconds:
  delay(calValue);          
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);   
  // stop the program for for <sensorValue> milliseconds:
  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t delay = ");      
  Serial.println(calValue);
  delay(sensorValue);                  
}

/* domande:
 1. qual'e' il valore minimo rilevato?
 2. quale il massimo?
 3. Come adattare la risoluzione dell'attuatore alla sensibilita' del sensore?
 */

