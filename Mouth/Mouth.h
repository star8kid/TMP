#ifndef Mouth_h
#define Mouth_h


#include "Arduino.h"
#include <MD_MAX72xx.h>

class MouthLeft{

public:
    void updateMouthLeftDisplay(MD_MAX72XX &mxSPI, int inputInt);

private:
  // Idle Displays

  uint8_t IdleDisplayOne[COL_SIZE] =
  {
    0b00011000,
    0b00011100,
    0b00001100,
    0b00000110,
    0b00000110,
    0b00000110,
    0b00001110,
    0b00001100
  };
  uint8_t IdleDisplayTwo[COL_SIZE] = // Watch tutorial video again to figure out how to flip all of these
  {
    0b10000000,
    0b11000000,
    0b11000000,
    0b01100000,
    0b01100000,
    0b00110000,
    0b00110000,
    0b00011000
  };
  uint8_t IdleDisplayThree[COL_SIZE] = // Watch tutorial video again to figure out how to flip all of these
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
  uint8_t IdleDisplayFour[COL_SIZE] = // Watch tutorial video again to figure out how to flip all of these
  {
    0b11000000,
    0b01100000,
    0b01100000,
    0b00110000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000
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
  void updateMouthMiddleDisplay(MD_MAX72XX &mxSPI, int inputInt);
};

class MouthRight{
public:

    void updateMouthRightDisplay(MD_MAX72XX &mxSPI, int inputInt);

private:

  uint8_t IdleDisplayOne[COL_SIZE] = 
  {
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00110000,
    0b01100000,
    0b01100000,
    0b11000000
  };
  uint8_t IdleDisplayTwo[COL_SIZE] = 
  {
    0b10000000,
    0b11000000,
    0b11000000,
    0b01100000,
    0b01100000,
    0b00110000,
    0b00110000,
    0b00010000
  };
  uint8_t IdleDisplayThree[COL_SIZE] = 
  {
    0b00011000,
    0b00110000,
    0b00110000,
    0b01100000,
    0b01100000,
    0b11000000,
    0b11000000,
    0b10000000
  };
  uint8_t IdleDisplayFour[COL_SIZE] = 
  {
    0b00001100,
    0b00001110,
    0b00000110,
    0b00000110,
    0b00000110,
    0b00001100,
    0b00011100,
    0b00011000
  };
  // Other Private Variables:
  constexpr static uint8_t partMaxDevices = 4;
  constexpr static uint8_t partFirstDeviceIndex = 0;

};

#endif
