/* Blink without Delay: RTOS

   Implementazione di due processi indipendenti:
   TaskFirstBlink e  TaskSecondBlink
   per far lampeggiare due LED tramite il framework FreeRTOS

 * E' necessario installare la libreria: Arduino_FreeRTOS
- https://github.com/feilipu/Arduino_FreeRTOS_Library
- https://www.hackster.io/feilipu/using-freertos-multi-tasking-in-arduino-ebc3cc
 */
#include <Arduino_FreeRTOS.h>

// define two tasks for Blink & AnalogRead
void TaskFirstBlink( void *pvParameters );
void TaskSecondBlink( void *pvParameters );

// the setup function runs once when you press reset or power the board
void setup() {

  // Now set up two tasks to run independently.
  xTaskCreate(
    TaskFirstBlink
    ,  (const portCHAR *)"First Blink"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );

  xTaskCreate(
    TaskSecondBlink
    ,  (const portCHAR *) "Sec Blink"
    ,  128  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL );

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi

  modified 9 Gen 2017 
  by Andrea Manni
*/

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

// First Task
void TaskFirstBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

// initialize digital LED_BUILTIN on pin 13 as an output.
byte led = 13;
const int pausa = 500;
pinMode(led, OUTPUT);

  for (;;) // Equivalent to the classic loop() function
  {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelay( pausa / portTICK_PERIOD_MS ); // wait for one second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay( pausa / portTICK_PERIOD_MS ); // wait for one second
  }
}

// Second Task
void TaskSecondBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  
byte led = 3;
const int pausa = 1000;
pinMode(led, OUTPUT);

  for (;;) 
  {
    digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelay( pausa / portTICK_PERIOD_MS ); // wait for one second
    digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay( pausa / portTICK_PERIOD_MS ); // wait for one second
  }
}
