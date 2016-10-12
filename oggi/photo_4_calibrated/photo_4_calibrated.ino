/*
  Photoresistor
 
 Utilizzare una fotoresistenza come analog input.
 Il comportamento della foto resistenza e' simile
 a un potenziometro: varia la resistenza in base alla 
 quantita' di luce.
 
 Per ottenere valori significativi utilizzare unaresistenza
 da ~5k - 10k ohms in serie con il sensore.
 
 Questo sketch modifica l'intervallo di intermittenza di un led
 in base alla luminosita' rilevata.
 
 Schema: http://lab.piffa.net/schemi/photoresistor_led.png
 */

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

int min = 60;        // valore minimo rilevato dal sensore
int max = 600;        // valore massimo rilevato dal sensore

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);  
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
    // read the value from the sensor:
  sensorValue = analogRead(sensorPin);   
  int calValue = map(sensorValue,min,max,0,1000) ; 
  // Max pausa = 1000 ms

    // Manage those blinks
  digitalWrite(ledPin, HIGH);  
  // stop the program for <sensorValue> milliseconds:
  delay(calValue);          
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);   
  // stop the program for for <sensorValue> milliseconds:
  
    // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t cal delay = ");      
  Serial.println(calValue);
  delay(sensorValue);                  
}

/*
Domande:
1. Modificare lo sketch in modo che modifichi la luminosita' di un led 
via PWM tramite il valore letto dal sensore.
2. Come fare per costringere la variabile dentro un intervallo stabilito?
3. Come si potrebbe eseguire la calibrazione automaticamente?
*/

