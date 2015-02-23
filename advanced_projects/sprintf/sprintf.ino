/* 
  sprintf()
  
  Uso di sprintf per formattare stringhe di testo
  Nota: sprintf() non accetta floats
   
   */
int h = 12;
int m = 3;
int s = 2;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  char buffer[17]; // We need a buffer to hold the formatted ouput
  
  sprintf(buffer, "Time: %2d:%02d:%02d", h, m, s);  // C sintax
  
  Serial.print(buffer);
  Serial.flush();
  exit(0);
}


