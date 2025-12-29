// Include Helper Libraries
#include <MD_MAX72xx.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

// Include Display Libraries
#include <Eyes.h>
#include <Mouth.h>
// #include <Animation.h>
#include <Head.h>

// Define all the pins:
#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  
const int potPin = A3;

// Device Definitions
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW 
#define MAX_DEVICES 4
// #define DELAYTIME 1000 // time between display updates

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// Create Head Object
Head headInst;

// Define Sensor Input Variables:
int potReadAnalog = 0;
// Define Tasks and Semaphores
// SemaphoreHandle_t LEDSemaphore;

void TaskUpdateLED(void * taskParameters);
void TaskReadPot(void * taskParameters);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  mx.begin();
  // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  // while (!Serial) {;}

  // Define RTOS Tasks
  xTaskCreate(TaskUpdateLED, "UpdateLED", 128, NULL, 2, NULL);
  xTaskCreate(TaskReadPot, "ReadPot", 128, NULL, 3, NULL);

  // Test Code (w/o RTOS):
  // headInst.setHeadEmotion(Head::Emotions::Idle);
  // Serial.println("Set head emotion to Idle");
  // delay(3000);

  // uint16_t maxCols = mx.getColumnCount();
  // Serial.println(maxCols);
  // headInst.updateHeadDisplay(mx);
  // Serial.println("Update Head Emotion");

  // delay(1000);
  // headInst.setHeadEmotion(Head::Emotions::Happy);
  // Serial.println("Set head emotion to Happy");
  // headInst.updateHeadDisplay(mx);
  // delay(1000);
  // headInst.setHeadEmotion(Head::Emotions::Sad);
  // Serial.println("Set head emotion to Sad");
  // headInst.updateHeadDisplay(mx);
  // delay(1000);
  // headInst.setHeadEmotion(Head::Emotions::Angry);
  // Serial.println("Set head emotion to Angry");
  // headInst.updateHeadDisplay(mx);
}

void loop() {
  // Don't run code in here, since we're using an RTOS
  // delay(3000);
  // // headInst.updateHeadDisplay();
  // Serial.println("Update Head Emotion\n");
}

// Start the scheduler
// vTaskStartScheduler();
void TaskUpdateLED(void *taskParameters)
{
  (void) taskParameters;
  // Setup Task Delay and Freq
  TickType_t xLastWakeTime;
  const TickType_t xFreq = pdMS_TO_TICKS(33); 
  // Initialize task with the current time
  xLastWakeTime = xTaskGetTickCount();
  for(;;){
    vTaskDelayUntil(&xLastWakeTime, xFreq);
    // // Read Potentiometer Value and set Head instance emotion based on value
    if(potReadAnalog < 300){
      headInst.setHeadEmotion(Head::Emotions::Idle);
      // Serial.println("Updated emotion to Idle");
    }
    else if (potReadAnalog > 300 && potReadAnalog < 600){
      headInst.setHeadEmotion(Head::Emotions::Happy);
      // Serial.println("Updated emotion to Happy");
    }
    else if (potReadAnalog > 600 && potReadAnalog < 800){
      // Serial.println("Updated emotion to Sad");
      headInst.setHeadEmotion(Head::Emotions::Sad);
    }
    else
      headInst.setHeadEmotion(Head::Emotions::Angry);
    // Call head instance's method
    headInst.updateHeadDisplay(mx);
    // Serial.println("In 'Update Emotion' Task");

  }
}

void TaskReadPot(void *taskParameters){
  (void) taskParameters;
  // For this task, depending on the value of the pot,
  // Simply just print it out to the serial console

  for(;;){
    potReadAnalog = analogRead(A3);
    // Serial.print("Potentiometer Value: ");
    // Serial.println(potReadAnalog);
    vTaskDelay(1);
  }
}
