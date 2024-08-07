#ifndef Animation_h
#define Animation_h

#include "Arduino.h"
#include <MD_MAX72xx.h>

// Base Class for simple 2D Animations

class Animation{
    public:
        // frameRate Getter
        uint8_t getFrameRate(){
            return this->frameRate;
        }

        // frameRate Setter
        void setFrameRate(uint8_t inputVal){ 
            if (0 <= inputVal <= 255){ // Ensure that the argument can fit within the datatype range
                this->frameRate = inputVal;
            }
        }

        // Create a PlayAnimation Function (Look into how to do timing and prevent program delay)

    private: 
        uint8_t frameRate = 12; // This value will determine how many frames per minute an animation object should cycle through
};
#endif