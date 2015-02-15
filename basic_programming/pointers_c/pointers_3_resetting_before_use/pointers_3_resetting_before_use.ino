/*
Purpose: Illustrate pointer arithmetic
 Dr. Purdum, August 20, 2012
 */
#include <string.h>
void setup() {
  Serial.begin(9600);
}
void loop() {
  char buffer[50];
  char *ptr;
  int i;
  int length;

  strcpy(buffer, "When in the course of human events");
  ptr = buffer;
  length = strlen(buffer);
  Serial.print("The lvalue for ptr is: ");
  Serial.print((unsigned int)&ptr);
  Serial.print(" and the rvalue is ");
  Serial.println((unsigned int)ptr);
  while (*ptr) {
    Serial.print(*ptr++); // This actually incrementa ptr* + 34
  }
  Serial.println("");

  Serial.println("Lenght of the string is: ");
  Serial.println(length);  
  Serial.println("");


  // ptr = ptr - length ; // Whis would roll back ptr
  for (i = 0; i < length; i++) {
    Serial.print(*(ptr + i));  
    // Serial.print(*(ptr + i- lenght)); // ptr is one lenght up ahead
  }
  // ptr = buffer  ;    // Right thing to do: reset the pointer before use
  //   for (i = 0; i < length; i++) {
  // Serial.print(*(ptr + i))


  Serial.flush();
  // Make sure all the data is sent...
  exit(0);
}




