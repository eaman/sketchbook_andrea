/*
 *   Hello World!
 *
 * This is the Hello World! for Arduino. 
 * It shows how to send data to the computer trough the serial connection
 */

void setup()                   
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  // If the Arduino transfers data at 9600 bits per second 
  // and you're sending 12 bytes of data, how long does it take to send over this information? 

  // Try to change bond rate in the monitor

  Serial.println("Hello World!");  // prints hello with ending line break 
  
  
  Serial.print("Il mio nome e': ") // Scrive senza ritorno a capo
  Serial.println("Andrea");        // Scrive con ritorno a capo
  Serial.flush                     // Assicura che tutto il testo venga scritto

}

void loop()                       // run over and over again
{
  // Try to put the Serial.printl() statenent in here, with a delay maybe
}




