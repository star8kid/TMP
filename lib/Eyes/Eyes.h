#ifndef Eyes_h
#define Eyes_h

#include <MD_MAX72xx.h>
// #include "Arduino.h"

class EyeLeft{
  public: 
    // Update Function
    void updateEyeLeftDisplay(MD_MAX72XX &mxSPI, int inputInt);
    // Animation Functions (WIP)
    // void blinkEyeLeft(MD_MAX72XX &mxSPI);

  private:

  // Idle Displays

  uint8_t IdleDisplayOne [COL_SIZE] = 
  {
    0b01111110,
    0b01111110,
    0b00111100,
    0b01100000,
    0b11000000,
    0b10000000,
    0b00000000,
    0b00000000
  };

  uint8_t IdleDisplayTwo[COL_SIZE] = 
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00111100,
    0b01111110,
    0b01111110
  };

  // Happy Displays

  uint8_t HappyDisplayOne[COL_SIZE] = 
  {
      0b01110000,
      0b01110000,
      0b01110000,
      0b00110000,
      0b00110000,
      0b00011000,
      0b00011000,
      0b00001100
  };
  uint8_t HappyDisplayTwo[COL_SIZE] = 
    {
      0b00011000,
      0b00111100,
      0b01111100,
      0b01111100,
      0b11111000,
      0b11110000,
      0b11110000,
      0b11110000
    };
  // Sad Display

  uint8_t SadDisplayOne[COL_SIZE] = 
  {
    0b00111110,
    0b00111110,
    0b01111100,
    0b11100000,
    0b11000000,
    0b00000000,
    0b00000000,
    0b00000000
  };

  uint8_t SadDisplayTwo[COL_SIZE] = 
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b01100000,
    0b01111100,
    0b00111110,
    0b00111110
  };

  uint8_t AngryDisplayOne[COL_SIZE] =
  {
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  };

  uint8_t AngryDisplayTwo[COL_SIZE] =
  {
    0b00000000,
    0b00000000,
    0b00011110,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000
  };

  constexpr static uint8_t partMaxDevices = 2; 
  constexpr static uint8_t partFirstDeviceIndex = 1; 
};

class EyeRight{
  public:
    // Update Function
    void updateEyeRightDisplay(MD_MAX72XX &mxSPI, int inputInt);
    // Animation Functions (WIP)
    // void blinkEyeRight(MD_MAX72XX &mxSPI);
  private:
    uint8_t IdleDisplayOne[COL_SIZE] = 
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
    uint8_t IdleDisplayTwo[COL_SIZE] = 
    {
      0b00000000,
      0b00000000,
      0b10000000,
      0b11000000,
      0b01100000,
      0b00111100,
      0b01111110,
      0b01111110
    };
    
    uint8_t HappyDisplayOne[COL_SIZE] = 
    {
      0b11110000,
      0b11110000,
      0b11111000,
      0b11111000,
      0b01111100,
      0b01111100,
      0b00111100,
      0b00011000,
    };

    uint8_t HappyDisplayTwo[COL_SIZE] = 
    {
    0b00001100,
    0b00011000,
    0b00011000,
    0b00110000,
    0b00110000,
    0b01110000,
    0b01110000, 
    0b01110000 
    };

  uint8_t SadDisplayOne[COL_SIZE] = 
  {
    0b00111110,
    0b00111110,
    0b01111100,
    0b01100000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  };

  uint8_t SadDisplayTwo[COL_SIZE] = 
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b11000000,
    0b11100000,
    0b01111100,
    0b00111110,
    0b00111110
  };

  uint8_t AngryDisplayOne[COL_SIZE] =
  {
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011110,
    0b00000000,
    0b00000000
  };

  uint8_t AngryDisplayTwo[COL_SIZE] =
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000
  };

  constexpr static uint8_t partMaxDevices = 2; 
  constexpr static uint8_t partFirstDeviceIndex = 3; 
};

#endif