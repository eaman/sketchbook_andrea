// Chapter 7: Arduino Alarm Clock 
// An alarm clock that uses the Adafruit Industries DS1307 RTC Breakout board 
// and a 16 x 2 Parallel LCD Display 
#include <Wire.h> // I2C Wire Library for communicating with the DS1307 RTC 
#include "RTClib.h" // Date and time functions for the DS1307 RTC connected 
#include <LiquidCrystal.h> // Display functions for the LCD Display 
RTC_DS1307 rtc; // Create a realtime clock called rtc 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Create an LCD called lcd 

DateTime now; // Time object

void setup () { 
  Wire.begin(); // Enables the communication for the LCD 
  rtc.begin(); // Enables the RTC 
  lcd.begin(16, 2); // Enables the LCD 

  lcd.print(" It's Alive!"); // Print a message, centered, to the LCD to confirm it's working 
  delay(500); // Wait a moment so we can read it 
  lcd.clear(); // Clear the LCD 
} 
void loop(){ 
  now = rtc.now(); // Get the current time 
  // Refresh the display 
  updateDisplay();
} 

void updateDisplay(){ 
  int h = now.hour(); // Get the hours right now and store them in an integer called  h 
    int m = now.minute(); // Get the minutes right now and store them in an integer  called m 
    int s = now.second(); // Get the seconds right now and store them in an integer  called s 
    lcd.setCursor(0, 0); // Set the cursor at the column zero, upper row... 
  lcd.print(" The time is: "); // ...with spaces to clear characters from setting  alarm. 
    lcd.setCursor(4, 1); // Move the cursor to column four, lower row 
  if (h<10){ // Add a zero, if necessary, as above 
    lcd.print(0); 
  } 
  lcd.print(h); // Display the current hour 
  lcd.setCursor(6, 1); // Move to the next column 
  lcd.print(":"); // And print the colon 
  lcd.setCursor(7, 1); // Move to the next column 
  if (m<10){ // Add a zero, if necessary, as above 
    lcd.print(0); 
  } 
  lcd.print(m); // Display the current minute 
  lcd.setCursor(9, 1); // Move to the next column 
  lcd.print(":"); // And print the colon 
  lcd.setCursor(10, 1); // Move to the next column 
  if (s<10){ // Add a zero, if necessary, as above 
    lcd.print(0); 
  } 
  lcd.print(s); // Display the current second 
}

