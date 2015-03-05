/*
  EEPROM 
 
 Storaggio di un stringa di caratteri in EEPROM e sucessiva lettura
 usando le libreire AVR: /usr/lib/avr/include/avr/eeprom.h
 */

#include <avr/eeprom.h> // 

// the current address in the EEPROM (i.e. which byte
// we're going to write to next)
int addr = 100;
char testo[23] ;
void setup()
{ 
  char message[] = "Testo messaggio";
  Serial.begin(9600);
  Serial.println("Storaggio valore");

  //eeprom_write_block(message, (void *)addr, strlen(message) + 1);
  // Pointer all'array di carattere, punto in cui scrivere (su 1023), lunghezza
  // Eseguire una volta sola, caricare lo sketch
  // e immediatamente commetare e ripetere l'upload.
}

void loop()
{
  Serial.print("Lettura Valore: ");
  eeprom_read_block(&testo, (void *)addr,23);
  Serial.println(testo); 
  Serial.flush();
  exit(0) ;
}


