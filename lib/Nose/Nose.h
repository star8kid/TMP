#ifndef Nose_h
#define Nose_h

#include "Arduino.h"
#include <MD_MAX72xx.h>

class NoseLeft{
    public:
        void updateNoseLeftDisplay(MD_MAX72XX &mxSPI, int inputInt);
    private:
        // Idle Displays
         uint8_t IdleDisplay [COL_SIZE] = 
        {
            0b01111111,
            0b11111110,
            0b11111100,
            0b11000000,
            0b11000000,
            0b11000000,
            0b11000000,
            0b10000000
        };
        
        // Not final values. Will be changed in the future    
        constexpr static uint8_t partMaxDevices = 0;  
        constexpr static uint8_t partFirstDeviceIndex = 0;
};  

class NoseRight{
    public:
        void updateNoseRightDisplay(MD_MAX72XX &mxSPI, int inputInt);
    private:
        // Idle Displays
        uint8_t IdleDisplay [COL_SIZE] = 
        {
            0b11111110,
            0b01111111,
            0b00111111,
            0b00000011,
            0b00000011,
            0b00000011,
            0b00000011,
            0b00000001
        };
        constexpr static uint8_t partMaxDevices = 0;  
        constexpr static uint8_t partFirstDeviceIndex = 0;
};

#endif