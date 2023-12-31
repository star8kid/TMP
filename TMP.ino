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
#define DELAYTIME 1000 // time between display updates

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
  public: 
  
  void updateEyeLeftDisplay(Emotions inputEmotion){
    switch(inputEmotion){
        case Emotions::Idle:
          mx.setBuffer(((1)*COL_SIZE)-1, COL_SIZE, IdleDisplayOne);
          mx.setBuffer(((2)*COL_SIZE)-1, COL_SIZE, IdleDisplayTwo);
          break;
        case Emotions::Happy:
          mx.setBuffer(((1)*COL_SIZE)-1, COL_SIZE, HappyDisplayOne);
          mx.setBuffer(((2)*COL_SIZE)-1, COL_SIZE, HappyDisplayTwo);
          break;
        case Emotions::Sad:
          break;
        case Emotions::Angry:
          break;
    }
  }

  private:

  // Idle Displays

  uint8_t IdleDisplayOne[COL_SIZE] = 
  {
    0b00000000,
    0b00000000,
    0b00000001,
    0b00000011,
    0b00000110,
    0b00111100,
    0b01111110,
    0b01111110
  };

  uint8_t IdleDisplayTwo[COL_SIZE] = 
  {
    0b01111110,
    0b01111110,
    0b00111100,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  };

  // Happy Displays

  uint8_t HappyDisplayOne[COL_SIZE] = 
  {
    0b00110000,
    0b00011000,
    0b00011000,
    0b00001100,
    0b00001100,
    0b00001110,
    0b00001110,
    0b00001110
  };

  uint8_t HappyDisplayTwo[COL_SIZE] = 
  {
    0b00001111,
    0b00001111,
    0b00001111,
    0b00011111,
    0b00111110,
    0b00111110,
    0b00111100,
    0b00011000
  };

  constexpr static uint8_t partMaxDevices = 2; 
  constexpr static uint8_t partFirstDeviceIndex = 0; 

};
class EyeRight{
  public:
    void updateEyeRightDisplay(Emotions inputEmotion){
      switch(inputEmotion){
        case Emotions::Idle:
          mx.setBuffer(((3)*COL_SIZE)-1, COL_SIZE, IdleDisplayOne);
          mx.setBuffer(((4)*COL_SIZE)-1, COL_SIZE, IdleDisplayTwo);
          break;
        case Emotions::Happy:
          mx.setBuffer(((3)*COL_SIZE)-1, COL_SIZE, HappyDisplayOne);
          mx.setBuffer(((4)*COL_SIZE)-1, COL_SIZE, HappyDisplayTwo);
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
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00111100,
      0b01111110,
      0b01111110,
    };
    uint8_t IdleDisplayTwo[COL_SIZE] = 
    {
      0b01111110,
      0b01111110,
      0b00111100,
      0b00000110,
      0b00000011,
      0b00000001,
      0b00000000,
      0b00000000
    };
    
    uint8_t HappyDisplayOne[COL_SIZE] = 
    {
      0b00011000,
      0b00111100,
      0b00111110,
      0b00111110,
      0b00011111,
      0b00001111,
      0b00001111,
      0b00001111
    };

    uint8_t HappyDisplayTwo[COL_SIZE] = 
    {
      0b00001110,
      0b00001110,
      0b00001110,
      0b00001100,
      0b00001100,
      0b00011000,
      0b00011000,
      0b00110000
    };
  constexpr static uint8_t partMaxDevices = 2; 
  constexpr static uint8_t partFirstDeviceIndex = 2; 
};
class MouthLeft{
  public:

    void updateMouthLeftDisplay(Emotions inputEmotion){
      // First determine which switch case based no the Emotions enum
      switch(inputEmotion){
        case Emotions::Idle:

          // Future Refactoring: Figure out how to loop between each array pointer in the array of displays below

          // for(uint8_t a = partFirstDeviceIndex; a < (partFirstDeviceIndex + partMaxDevices); a++){
          //   // need something to properly set each of these cases for the different displays
          //   mx.setBuffer(((a + 1)*COL_SIZE)-1, COL_SIZE, IdleDisplayArray[a - partFirstDeviceIndex]);
          // }

          // Array Address Test
          // uint8_t *testPtr = &IdleDisplayOne[0];
          // int aArray[] = {10,20,30};
          // int *aPtr = &aArray[0];
          // Serial.print(&IdleDisplayOne[0]);
          // Serial.print(testPtr);
          // Serial.println((uint8_t)&IdleDisplayOne);
          // Serial.println((uint8_t)&IdleDisplayTwo);
          // Serial.println((uint8_t)&IdleDisplayThree);
          // Serial.println((uint8_t)&IdleDisplayFour);
          // Serial.println(IdleDisplayArray[0]);
          // Serial.println(IdleDisplayArray[0][0]);

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
    0b00000011,
    0b00000110,
    0b00000110,
    0b00001100,
    0b00001100,
    0b00011000,
    0b00011000,
    0b00011000
  };
  
  uint8_t IdleDisplayTwo[COL_SIZE] =
  {
    0b00001000,
    0b00001100,
    0b00001100,
    0b00000110,
    0b00000110,
    0b00000011,
    0b00000011,
    0b00000001
  };

  uint8_t IdleDisplayThree[COL_SIZE] =
  {
    0b00000001,
    0b00000011,
    0b00000011,
    0b00000110,
    0b00000110,
    0b00001100,
    0b00001100,
    0b00011000
  };

  uint8_t IdleDisplayFour[COL_SIZE] =
  {
    0b00011000,
    0b00111000,
    0b00111000,
    0b01101000,
    0b01101000,
    0b11001000,
    0b01111000,
    0b00111000
 
  };


  // Other Private Variables:
  constexpr static uint8_t partMaxDevices = 4; // These members are static since there will be one instance (and therefore one value for each member) instantiated anyways
  constexpr static uint8_t partFirstDeviceIndex = 0; // This value will be changed later once I figure out where each part's first device index is
  // Display Arrays
  // uint8_t IdleDisplayArray[partMaxDevices] = {IdleDisplayOne, IdleDisplayTwo, IdleDisplayThree, IdleDisplayFour};
  // uint8_t IdleDisplayArray[partMaxDevices]= {(uint8_t)&IdleDisplayOne, (uint8_t)&IdleDisplayTwo, (uint8_t)&IdleDisplayThree, (uint8_t)&IdleDisplayFour};
};
class MouthMiddle{
  void updateMouthMiddleDisplay(){

  }
};
class MouthRight{
  public:

  void updateMouthRightDisplay(Emotions inputEmotion){
    switch(inputEmotion){
      case Emotions::Idle:

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
    0b11000000,
    0b01100000,
    0b01100000,
    0b00110000,
    0b00110000,
    0b00011000,
    0b00011000,
    0b00011000
  };
  uint8_t IdleDisplayTwo[COL_SIZE] = 
  {
    0b00010000,
    0b00110000,
    0b00110000,
    0b01100000,
    0b01100000,
    0b11000000,
    0b11000000,
    0b10000000
  };
  uint8_t IdleDisplayThree[COL_SIZE] = 
  {
    0b10000000,
    0b11000000,
    0b11000000,
    0b01100000,
    0b01100000,
    0b00110000,
    0b00110000,
    0b00011000,
  };
  uint8_t IdleDisplayFour[COL_SIZE] = 
  {
    0b00011000,
    0b00011100,
    0b00011100,
    0b00010110,
    0b00010110,
    0b00010011,
    0b00011110,
    0b00011100,
  };
  // Other Private Variables:
  constexpr static uint8_t partMaxDevices = 4;
  constexpr static uint8_t partFirstDeviceIndex = 0;

};
class NoseLeft{
  void updateNoseLeftDisplay(){

  }
};
class NoseRight{
  void updateNoseRightDisplay(){
    
  }
};

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
      HeadEyeLeft.updateEyeLeftDisplay(currentEmote);
      HeadEyeRight.updateEyeRightDisplay(currentEmote);
      // Mouth
      // HeadMouthLeft.updateMouthLeftDisplay(currentEmote);
      // HeadMouthRight.updateMouthRightDisplay(currentEmote);
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
    EyeLeft HeadEyeLeft;
    EyeRight HeadEyeRight;
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

  protogenHead.setHeadEmotion(Emotions::Happy);
  protogenHead.updateHeadDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  // scrollText("The Mint Project"); 
  // a good exercise would be to figure out how to make this not run backwards
  delay(DELAYTIME);
}

