#ifndef Mouth_h
#define Mouth_h


#include "Arduino.h"
#include <MD_MAX72xx.h>

class MouthLeft{

public:
    void updateMouthLeftDisplay(MD_MAX72XX mxSPI, int inputInt);

private:
      
  // Idle Displays

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
public:
  void updateMouthMiddleDisplay();
};

class MouthRight{
public:

    void updateMouthRightDisplay(int inputInt);

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

#endif
