#include <MD_MAX72xx.h>
#include <Eyes.h>
#include <Mouth.h>

// Turn on debug statements to the serial output
#define  DEBUG  1

#if  DEBUG
#define PRINT(s, x) { Serial.print(F(s)); Serial.print(x); }
#define PRINTS(x) Serial.print(F(x))
#define PRINTD(x) Serial.println(x, DEC)

#else
#define PRINT(s, x)
#define PRINTS(x)
#define PRINTD(x)

#endif

// List of each Matrix component for the face

#define MATRIX_EYE_LEFT = 0;
#define MATRIX_EYE_RIGHT = 1;
#define MATRIX_MOUTH_LEFT = 2;
#define MATRIX_MOUTH_MIDDLE = 3;
#define MATRIX_MOUTH_RIGHT = 4;
#define MATRIX_NOSE_LEFT = 5;
#define MATRIX_NOSE_RIGHT = 6;


// Define all the pins:
#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  // or SS

// Device Definitions
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW 
#define MAX_DEVICES 4
#define DELAYTIME 1000 // time between display updates

//SPI Hardware Interface

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// To-Do List:
 // Organize the components such that they can be individually be addressed in matricies like the above
  // Implement a Class Composition (Inheritance) relationship between the Head and all the parts above



// Idea List:
 // Make an Emotions Enum for each of the parts of the face (or possibly do this for animations/)

// Each Head Part class needs:
// - Access to the instance of "mx" (Already done because "mx" is global)
// - Data storing the number of devices it's in control of
// - Data storing the first device index it's in control of (compared to all the devices in MAX_DEVICES)

//  Main class that holds all the composed objects

class Head {
  // Define functions to change display
  // Organization:
    // Have the Emotions be in an Enum
    // Make a function in Head to change Emotion


  // Technical:
    // Make a function to "switch displays" ✅
    // Make a function to "update displays" ✅

  public:
    // Make a constructor that takes in an instance of each of the previous parts of the class
    enum class Emotions
    {
      Idle = 0, 
      Happy = 1, 
      Sad = 2, 
      Angry = 3
    };

    void updateHeadDisplay(){
      // Check emotion type first
      Emotions currentEmote = getHeadEmotion();
      
      // Then, update emotions on each part of the head
      mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);

      // The static_cast's are neccessary here because they provide a way for the `update` functions of each body part to have an input based on Enumerated States, while still be separated in implementation      
      // Eyes
      HeadEyeLeft.updateEyeLeftDisplay(mx, static_cast<int>(currentEmote)); 
      HeadEyeRight.updateEyeRightDisplay(mx, static_cast<int>(currentEmote));
      // Mouth
      // HeadMouthLeft.updateMouthLeftDisplay(mx, static_cast<int>(currentEmote));
      // HeadMouthRight.updateMouthRightDisplay(mx, static_cast<int>(currentEmote));
      // Nose
      mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
      // Display each bitmap on each 8x8 matrix of each part of the face
    }

    Emotions getHeadEmotion(){
      return HeadEmotion;
    }
    void setHeadEmotion(Emotions inEmote){
      HeadEmotion = inEmote;
    }
  private: 

    Emotions HeadEmotion {Emotions::Idle};
    // Parts of the head
    //Eyes
    EyeLeft HeadEyeLeft;
    EyeRight HeadEyeRight;
    //Mouth
    // MouthLeft HeadMouthLeft;
    // MouthMiddle HeadMouthMiddle;
    // MouthRight HeadMouthRight;
    // Nose
    // NoseLeft HeadNoseLeft; <--- Do This Later
    // NoseRight HeadNoseRight; <--- Do This Later
};

// Create the Head Instance

Head protogenHead;


// Function pulled from Test Example

void scrollText(const char *p)
{
  uint8_t charWidth;
  uint8_t cBuf[8];  // this should be ok for all built-in fonts

  PRINTS("\nScrolling text");
  mx.clear();

  while (*p != '\0')
  {
    charWidth = mx.getChar(*p++, sizeof(cBuf) / sizeof(cBuf[0]), cBuf);

    for (uint8_t i=0; i<=charWidth; i++)	// allow space between characters
    {
      mx.transform(MD_MAX72XX::TSL);
      mx.setColumn(0, (i < charWidth) ? cBuf[i] : 0); 
      delay(DELAYTIME);
    }
  }
}

void setup() {
  // put your setup code here, to run once:

#if  DEBUG
  Serial.begin(57600);
#endif
  PRINTS("\n The Mint Project");

  if (!mx.begin())
    PRINTS("\nMD_MAX72XX initialization failed");

delay(DELAYTIME);

  mx.clear();

  protogenHead.setHeadEmotion(Head::Emotions::Idle);
  protogenHead.updateHeadDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
}

