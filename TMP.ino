#include <MD_MAX72xx.h>

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
#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 4
#define DELAYTIME 100 // time between display updates

//SPI Hardware Interface

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// To-Do List:
 // Organize the components such that they can be individually be addressed in matricies like the above
  // Implement a Class Composition (Inheritance) relationship between the Head and all the parts above



// Idea List:
 // Make an Emotions Enum for each of the parts of the face (or possibly do this for animations/)







// Some Important Public Variables for all classes

enum class Emotions
{
  Idle = 0, 
  Happy = 1, 
  Sad = 2, 
  Angry = 3
};






// Each Head Part class needs:
// - Access to the instance of "mx" (Already done because "mx" is global)
// - Data storing the number of devices it's in control of
// - Data storing the first device index it's in control of (compared to all the devices in MAX_DEVICES)
// 



class EyeLeft{
  void updateEyeLeftDisplay(){

  }
};
class EyeRight{
    void updateEyeRightDisplay(){

    }
};
class MouthLeft{
  public:

    void updateMouthLeftDisplay(Emotions inputEmotion){
      // First determine which switch case based no the Emotions enum
      switch(inputEmotion){
        case Emotions::Idle:
          // for(uint8_t a = partFirstDeviceIndex; a < (partFirstDeviceIndex + partMaxDevices); a++){
          //   // need something to properly set each of these cases for the different displays
          //   mx.setBuffer(((a + 1)*COL_SIZE)-1, COL_SIZE, IdleDisplayArray[a - partFirstDeviceIndex]);
          // }
          mx.setBuffer(((1)*COL_SIZE)-1, COL_SIZE, IdleDisplayOne);
          mx.setBuffer(((2)*COL_SIZE)-1, COL_SIZE, IdleDisplayTwo);
          mx.setBuffer(((3)*COL_SIZE)-1, COL_SIZE, IdleDisplayThree);
          mx.setBuffer(((4)*COL_SIZE)-1, COL_SIZE, IdleDisplayFour);
          break;
        case Emotions::Happy:
          break;
        case Emotions::Sad:
          break;
        case Emotions::Angry:
          break;
      }
    }

  private:
  
  uint8_t IdleDisplayOne[COL_SIZE] = 
  {
    0b10000000,
    0b11100000,
    0b01111000,
    0b00011111,
    0b00000111,
    0b00000000,
    0b00000000,
    0b00000000
  };

  uint8_t IdleDisplayTwo[COL_SIZE] =
  {
    0b00000111,
    0b00011110,
    0b01111000,
    0b11100000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  };

  uint8_t IdleDisplayThree[COL_SIZE] =
  {
    0b11100000,
    0b01111000,
    0b00011110,
    0b00000111,
    0b00000001,
    0b00000000,
    0b00000000,
    0b00000000
  };

  uint8_t IdleDisplayFour[COL_SIZE] =
  {
    0b00011000,
    0b00100100,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000001,
    0b00000010,
    0b00000100
 
  };


  // Other Private Variables:
  constexpr static uint8_t partMaxDevices = 4; // These members are static since there will be one instance (and therefore one value for each member) instantiated anyways
  constexpr static uint8_t partFirstDeviceIndex = 0; // This value will be changed later once I figure out where each part's first device index is
  // Display Arrays
  // uint8_t IdleDisplayArray[COL_SIZE][partMaxDevices]{IdleDisplayOne, IdleDisplayTwo, IdleDisplayThree, IdleDisplayFour}; <--- Figure issue with referencing this array
};
class MouthMiddle{
  void updateMouthMiddleDisplay(){

  }
};
class MouthRight{
  void updateMouthRightDisplay(){

  }
};
class NoseLeft{
  void updateNoseLeftDisplay(){

  }
};
class NoseRight{
  void updateNoseRightDisplay(){
    
  }
};

// Define part object instances:

  // EyeLeft protoEyeLeft;
  // EyeRight protoEyeRight;
  // MouthLeft protoMouthLeft;
  // MouthMiddle protoMouthMiddle;
  // MouthRight protoMouthRight;
  // NoseLeft protoNoseLeft;
  // NoseRight protoNoseRight;

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

    void updateHeadDisplay(){
      // Check emotion type first
      Emotions currentEmote = getHeadEmotion();

      // Then, update emotions on each part of the head
      mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);
      // Eyes
      // Mouth
      HeadMouthLeft.updateMouthLeftDisplay(currentEmote);
      // Nose
      mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
      delay(DELAYTIME);
      // Display each bitmap on each 8x8 matrix of each part of the face
    }

    Emotions getHeadEmotion(){
      return HeadEmotion;
    }
    void setHeadEmotion(Emotions inEmote){
      HeadEmotion = inEmote;
    }

  private: 
    Emotions HeadEmotion = Emotions::Idle;
    // Parts of the head
    // EyeLeft HeadEyeLeft; <--- Do This Later
    // EyeRight HeadEyeRight; <--- Do This Later
    MouthLeft HeadMouthLeft;
    MouthMiddle HeadMouthMiddle;
    MouthRight HeadMouthRight;
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

  protogenHead.setHeadEmotion(Emotions::Idle);
  protogenHead.updateHeadDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  // scrollText("The Mint Project"); 
  // a good exercise would be to figure out how to make this not run backwards
  delay(DELAYTIME);
}

