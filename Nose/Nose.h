#ifndef Nose_h
#define Nose_h

#include "Arduino.h"
#include <MD_MAX72xx.h>

class NoseLeft{
    public:
        void updateNoseLeftDisplay(MD_MAX72XX &mxSPI, int inputInt);
    private:
        // Draw displays for each Nose class here (later!)

        
        // Not final values. Will be changed in the future    
        constexpr static uint8_t partMaxDevices = 0;  
        constexpr static uint8_t partFirstDeviceIndex = 0;
};  

class NoseRight{
    public:
        void updateNoseRightDisplay(MD_MAX72XX &mxSPI, int inputInt);
    private:
        constexpr static uint8_t partMaxDevices = 0;  
        constexpr static uint8_t partFirstDeviceIndex = 0;
};

#endif