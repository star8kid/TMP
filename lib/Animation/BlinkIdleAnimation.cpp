#include "Animation.h"

class BlinkIdleAnimation : public Animation{
    // Pseudocode
    // 1. Have the current Head emotion be saved before playing the animation


    private:
    static const int frameSeqSize = 10; // Defines the number of frames that are in this Animation

    // All Device Sequence Declarations and their Frames


    uint8_t const seq1[frameSeqSize][8] = {
        {
            0b00000000,
            0b00000000,
            0b01000100,
            0b01000100,
            0b00000000,
            0b00000000,
            0b01111110,
            0b00000000
        },
        {
            0b00000000,
            0b00000000,
            0b01000100,
            0b01000100,
            0b00000000,
            0b00000000,
            0b01111110,
            0b00000000
        },
        {
            0b00000000,
            0b00000000,
            0b01000100,
            0b00000000,
            0b00000000,
            0b00000000,
            0b01111110,
            0b00000000
        },
        {
            0b00000000,
            0b00000000,
            0b01000100,
            0b00000000,
            0b00000000,
            0b00000000,
            0b01111110,
            0b00000000
        },
        {
            0b00000000,
            0b00000000,
            0b11001100,
            0b00000000,
            0b00000000,
            0b00000000,
            0b01111110,
            0b00000000
        },
        {
            0b00000000,
            0b10000000,
            0b01001100,
            0b10000000,
            0b00000000,
            0b00000000,
            0b01111110,
            0b00000000
        },
        {
            0b00000000,
            0b10000000,
            0b01001100,
            0b10000000,
            0b00000000,
            0b00000000,
            0b01111110,
            0b00000000
        },
        {
            0b00000000,
            0b00000000,
            0b01100100,
            0b00000000,
            0b00000000,
            0b00000000,
            0b01111110,
            0b00000000
        },
        {
            0b00000000,
            0b00000000,
            0b01000100,
            0b01000100,
            0b00000000,
            0b00000000,
            0b01111110,
            0b00000000
        }
    };
    static uint8_t const seq2[frameSeqSize][8];
    static uint8_t const seq3[frameSeqSize][8];
    static uint8_t const seq4[frameSeqSize][8];

    public:

        // "getFrame" will look for the frameSequence of a particular device and get the frame being requested
        // if the frame doesn't exist, it will return a nullptr
        uint8_t* getFrame(const uint8_t frameSeqPtr[][8], int frameNum){
            if(frameNum >= 0 && frameNum < frameSeqSize)
                return (uint8_t*)&frameSeqPtr[frameNum];
            else    
                return nullptr;
        }

        // This function plays through the whole animation one time
        void playAnimation(MD_MAX72XX &mxSPI, int inputDeviceIndex){
        //     // Pseudocode for function next steps:
        //     /*
        //         1. Clear the LED matrix from the current Display (organize this in each Part Class)
        //         2. Play the animation
        //             a. Make support for pausing?
        //             b. Make support for stopping?
        //         3. Replace the LED matrix with the current Display (organize this in each Part Class)
        //     */

        //    // All timing calculations will be done in Milliseconds
            unsigned long startFrameTime = millis(); // Adds to the measured interval to account for the function being called later into a .ino execution
            unsigned long previousFrameTime = 0; // Tracks previous frame time
            unsigned long currentFrameTime;
            // const unsigned long nextFrameInterval =  double(60 / getFrameRate()) * 1000; // How long until switching to the next frame
            const unsigned long nextFrameInterval = double(1000 / getFrameRate());
            int frameCounter = 1;

        //     // // TO-DO: Utilize the variable below to track the current frame being displayed (with the getFrame function)
        
        // test-code to display only one frame using the getFrame function
        // mxSPI.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);
        // mxSPI.setBuffer(((inputDeviceIndex + 1) * COL_SIZE) - 1, COL_SIZE, currentFramePtr);
        // mxSPI.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
        
        // while-loop to play animation
        while(frameCounter < frameSeqSize){
                uint8_t* seq1FramePtr = getFrame(seq1, frameCounter);
                currentFrameTime = millis();
                // Compares the difference between the current time and the previous time 
                // the animation started against multiples (based on frame count) of "next frame" intervals 
                if(currentFrameTime - startFrameTime >= nextFrameInterval * frameCounter){
                    // Turn off SPI/Device updating
                    mxSPI.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);
                    // Increment frame counter
                    frameCounter++;
                    // Draw the new frame, now that the counter has incremented
                    // Note, each frame sequence will occur on different devices
                    mxSPI.setBuffer(((inputDeviceIndex + 1) * COL_SIZE) - 1, COL_SIZE, seq1FramePtr);
                    mxSPI.setBuffer(((inputDeviceIndex + 2) * COL_SIZE) - 1, COL_SIZE, seq1FramePtr);
                    mxSPI.setBuffer(((inputDeviceIndex + 3) * COL_SIZE) - 1, COL_SIZE, seq1FramePtr);
                    mxSPI.setBuffer(((inputDeviceIndex + 4) * COL_SIZE) - 1, COL_SIZE, seq1FramePtr);
                    
                    mxSPI.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
                }
            }

        }

};