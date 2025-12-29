#ifndef Head_h
#define Head_h

#include "Arduino.h"
#include <MD_MAX72xx.h>

#include <Eyes.h>
#include <Mouth.h>

class Head{

    public:
        // Head(MD_MAX72XX &inMX) : mxInst(inMX){};
        enum class Emotions{
            Idle = 0,
            Happy = 1,
            Sad = 2,
            Angry = 3
        };
        void updateHeadDisplay(MD_MAX72XX &mxIn);
        Emotions getHeadEmotion();
        void setHeadEmotion(Emotions inEmote);
    private:
        // Stores the instance of mx for use on parent classes
        Head::Emotions HeadEmotion{Emotions::Idle};
        // Parts of the head
        //Eyes
        EyeLeft HeadEyeLeft;
        EyeRight HeadEyeRight;
        //Mouth
        // MouthLeft HeadMouthLeft;
        // MouthMiddle HeadMouthMiddle;
        // MouthRight HeadMouthRight;
        // Nose
        // NoseLeft HeadNoseLeft; <--- Do This Later
        // NoseRight HeadNoseRight; <--- Do This Later
};


#endif