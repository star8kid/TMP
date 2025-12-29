#include <Arduino_FreeRTOS.h>
#include <semphr.h>
// define two tasks for Blink & AnalogRead
void TaskBlink( void *pvParameters );
void TaskOneGeneric(void *pvParameters);
void TaskTwoGeneric(void *pvParameters);
// void TaskAnalogRead( void *pvParameters );

// Lab 3B Code
const int pinD8 = 8;
const int pinD9 = 9;
const int pinD2 = 2;

SemaphoreHandle_t xSemaphore;


// the setup function runs once when you press reset or power the board
void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(pinD8, OUTPUT); // Set Lab3B Pin to OUTPUT
  pinMode(pinD2, INPUT_PULLUP); // Set Lab3B Pin to OUTPUT
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }

  // Interrupt Setup
  attachInterrupt(digitalPinToInterrupt(pinD2), interrupt, RISING);


  // Now set up two tasks to run independently.
  // xTaskCreate(
  //   TaskBlink
  //   ,  "Blink"   // A name just for humans
  //   ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
  //   ,  NULL
  //   ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
  //   ,  NULL );
  xTaskCreate(
    TaskOne
    ,  "Part E Task 1"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  4  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );
  
  xTaskCreate(
  TaskTwo
  ,  "Interrupt Task"   // A name just for humans
  ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
  ,  NULL
  ,  3  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
  ,  NULL );
  xSemaphore = xSemaphoreCreateBinary();
  // xTaskCreate()
  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}



void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void CPU_work(int time, int pin){
  // volatile int i = 0;
  // volatile int x = 0;
  // for (x=0; x<time; x++){
  //   for (i=0; i<836; i++);
  // }
  volatile int i,j,k;
  int mode = 0;
  for(i = 0; i < time; i++){
    for(j = 0; j < 8; j++){
      mode = !mode;
      digitalWrite(pin, mode);
      for(k = 0; k < 100; k++);
    }
  }
}

void interrupt(){
  // CPU_work(100, pinD8);
  BaseType_t xHigherPriorityTaskWoken = pdFALSE;
  // What the below function will do is change xHigherPriorityTaskWoken to
  // pdTRUE if giving the semaphore caused a task to unblock
  xSemaphoreGiveFromISR(xSemaphore, &xHigherPriorityTaskWoken);
}

void TaskOne(void *pvParameters){
  (void) pvParameters;
    // Grab "current time"
  TickType_t xLastWakeTime;
  const TickType_t xFreq = pdMS_TO_TICKS(33);
  // Init with the current time
  xLastWakeTime = xTaskGetTickCount();
  pinMode(pinD9, OUTPUT);
  for(;;) // Doesn't allow task to return/exit
  {
    vTaskDelayUntil(&xLastWakeTime, xFreq);
    // digitalWrite(pinD9, HIGH);
    CPU_work(20, pinD9);
    // digitalWrite(pinD9, LOW);
  }
} // TaskOne

void TaskTwo(void *pvParameters){
  (void) pvParameters;
  // pinMode()
  for(;;){
    if( xSemaphoreTake(xSemaphore, (TickType_t) 10000) == pdTRUE){
      CPU_work(100, pinD8);
    }
  }
} // TaskTwo

