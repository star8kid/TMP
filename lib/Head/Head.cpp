#include "Head.h"
#include <MD_MAX72xx.h>

// Task Function Defintions
void Head::updateHeadDisplay(MD_MAX72XX &mxIn){
    // Check emotion type first
    Head::Emotions currentEmote = this->getHeadEmotion();
    mxIn.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);

    // Update emotions on each part of the head
    // Eyes
    this->HeadEyeLeft.updateEyeLeftDisplay(mxIn, static_cast<int>(currentEmote)); 
    this->HeadEyeRight.updateEyeRightDisplay(mxIn, static_cast<int>(currentEmote));
    // Mouth
    // HeadMouthLeft.updateMouthLeftDisplay(mx, static_cast<int>(currentEmote));
    // HeadMouthRight.updateMouthRightDisplay(mx, static_cast<int>(currentEmote));
    mxIn.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);

}

// Helper Functions Defintions

Head::Emotions Head::getHeadEmotion(){
    return this->HeadEmotion;
}

void Head::setHeadEmotion(Emotions inEmote){
    this->HeadEmotion = inEmote;
}

