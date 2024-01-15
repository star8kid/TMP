#ifndef Eyes_h
#define Eyes_h

#include "Arduino.h"
#include <MD_MAX72xx.h>

class EyeLeft{
  public: 
  
    void updateEyeLeftDisplay(MD_MAX72XX mxSPI, int inputInt);

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

  // Sad Display

  uint8_t SadDisplayOne[COL_SIZE] = 
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000110,
    0b00111110,
    0b01111100,
    0b01111100
  };

  uint8_t SadDisplayTwo[COL_SIZE] = 
  {
    0b01111100,
    0b01111100,
    0b00111110,
    0b00000111,
    0b00000011,
    0b00000001,
    0b00000000,
    0b00000000
  };

  constexpr static uint8_t partMaxDevices = 2; 
  constexpr static uint8_t partFirstDeviceIndex = 0; 
};

class EyeRight{
  public:
    void updateEyeRightDisplay(MD_MAX72XX mxSPI, int inputInt);
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

  uint8_t SadDisplayOne[COL_SIZE] = 
  {
    0b00000000,
    0b00000000,
    0b00000001,
    0b00000011,
    0b00000111,
    0b00111110,
    0b01111100,
    0b01111100
  };

  uint8_t SadDisplayTwo[COL_SIZE] = 
  {
    0b01111100,
    0b01111100,
    0b00111110,
    0b00000110,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  };
  constexpr static uint8_t partMaxDevices = 2; 
  constexpr static uint8_t partFirstDeviceIndex = 2; 
};

#endif