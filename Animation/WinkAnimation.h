
// #ifndef WinkAnimation_h
// #define WinkAnimation_h
// #include "Animation.h"

// // An example class containing everything for a Wink animation

// class WinkAnimation : public Animation{
//     public:
//         // uint8_t * getFrame(int frameNum){
//         //     return this->(frameSequence + frameNum);
//         // }

//         // Returns a pointer to the Nth (input integer) frame within the class's sequence 
//         // **Figure out how to move this function to the base class (since this should really be a part of all animations)
//         uint8_t* getFrame(int frameNum);
        
//         // This function plays through the whole animation one time
//         void playAnimation(MD_MAX72XX &mxSPI, int inputDeviceIndex);

//     private:
//         static const uint8_t frame0000[];
//         static const uint8_t frame0001[];
//         static const uint8_t frame0002[];
//         static const uint8_t frame0003[];
//         static const uint8_t frame0004[];
//         static const uint8_t frame0005[];
//         static const uint8_t frame0006[];
//         static const uint8_t frame0007[];
//         static const uint8_t frame0008[];
//         static const uint8_t frame0009[];
//         static const uint8_t frame0010[];

//         static const uint8_t* const frameSequence[11];
//         static const int frameSequenceSize;
// };

// // Define individual frames, frameSequence and frameSequenceSize outside of the derived class

// // Example of defining individual frames:

// const uint8_t WinkAnimation::frame0000[] = 
// {
//     0b00000000,
//     0b00000000,
//     0b01000100,
//     0b01000100,
//     0b00000000,
//     0b00000000,
//     0b01111110,
//     0b00000000
// };

// const uint8_t WinkAnimation::frame0001[] = 
// {
//     0b00000000,
//     0b00000000,
//     0b01000100,
//     0b01000100,
//     0b00000000,
//     0b00000000,
//     0b01111110,
//     0b00000000
// };

// const uint8_t WinkAnimation::frame0002[] = 
// {
//     0b00000000,
//     0b00000000,
//     0b01000100,
//     0b00000000,
//     0b00000000,
//     0b00000000,
//     0b01111110,
//     0b00000000
// };

// const uint8_t WinkAnimation::frame0003[] = 
// {
//     0b00000000,
//     0b00000000,
//     0b01000100,
//     0b00000000,
//     0b00000000,
//     0b00000000,
//     0b01111110,
//     0b00000000
// };

// const uint8_t WinkAnimation::frame0004[] = 
// {
//     0b00000000,
//     0b00000000,
//     0b11001100,
//     0b00000000,
//     0b00000000,
//     0b00000000,
//     0b01111110,
//     0b00000000
// };

// const uint8_t WinkAnimation::frame0005[] = 
// {
//     0b00000000,
//     0b10000000,
//     0b01001100,
//     0b10000000,
//     0b00000000,
//     0b00000000,
//     0b01111110,
//     0b00000000
// };

// const uint8_t WinkAnimation::frame0006[] = 
// {
//     0b00000000,
//     0b10000000,
//     0b01001100,
//     0b10000000,
//     0b00000000,
//     0b00000000,
//     0b01111110,
//     0b00000000
// };

// const uint8_t WinkAnimation::frame0007[] = 
// {
//     0b00000000,
//     0b10000000,
//     0b01001100,
//     0b10000000,
//     0b00000000,
//     0b00000000,
//     0b01111110,
//     0b00000000
// };

// const uint8_t WinkAnimation::frame0008[] = 
// {
//     0b00000000,
//     0b00000000,
//     0b01100100,
//     0b00000000,
//     0b00000000,
//     0b00000000,
//     0b01111110,
//     0b00000000
// };

// const uint8_t WinkAnimation::frame0009[] = 
// {
//     0b00000000,
//     0b00000000,
//     0b01000100,
//     0b01000100,
//     0b00000000,
//     0b00000000,
//     0b01111110,
//     0b00000000
// };

// const uint8_t WinkAnimation::frame0010[] = 
// {
//     0b00000000,
//     0b00000000,
//     0b01000100,
//     0b01000100,
//     0b00000000,
//     0b00000000,
//     0b01111110,
//     0b00000000
// };

// // Example of defining the frame sequence and frame sequence size:
// // Array that stores all the frames of the animation
// const uint8_t * const WinkAnimation::frameSequence[] = {frame0000,frame0001,frame0002,frame0003,frame0004,frame0005,frame0006,frame0007,frame0008,frame0009,frame0010};
// // Integer that stores the sizse of the animation
// const int WinkAnimation::frameSequenceSize = sizeof(WinkAnimation::frameSequence) / sizeof(WinkAnimation::frameSequence[0]);

// #endif