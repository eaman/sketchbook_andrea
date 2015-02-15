// Chapter 7: Arduino Alarm Clock 
// An alarm clock that uses the Adafruit Industries DS1307 RTC Breakout board 
// and a 16 x 2 Parallel LCD Display 
#include <Wire.h> // I2C Wire Library for communicating with the DS1307 RTC 
#include "RTClib.h" // Date and time functions for the DS1307 RTC connected 
#include <LiquidCrystal.h> // Display functions for the LCD Display 
RTC_DS1307 rtc; // Create a realtime clock called rtc 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Create an LCD called lcd 


void setup () { 
  Wire.begin(); // Enables the communication for the LCD 
  rtc.begin(); // Enables the RTC 
  lcd.begin(16, 2); // Enables the LCD 
  
  lcd.print(" It's Alive!"); // Print a message, centered, to the LCD to confirm it's working 
  delay(500); // Wait a moment so we can read it 
  lcd.clear(); // Clear the LCD 
} 
void loop(){ 
  
} 

