// #include "Arduino.h"
#include "Eyes.h"

void EyeLeft::updateEyeLeftDisplay(MD_MAX72XX &mxSPI, int inputInt){ // Passing the `mx` object by reference so it doesn't get copied
    switch(inputInt){
        case 0: // Idle Display
          mxSPI.setBuffer(((1)*COL_SIZE)-1, COL_SIZE, IdleDisplayOne);
          mxSPI.setBuffer(((2)*COL_SIZE)-1, COL_SIZE, IdleDisplayTwo);
          break;
        case 1: // Happy Display
          mxSPI.setBuffer(((1)*COL_SIZE)-1, COL_SIZE, HappyDisplayOne);
          mxSPI.setBuffer(((2)*COL_SIZE)-1, COL_SIZE, HappyDisplayTwo);
          break;
        case 2: // Sad Display
          mxSPI.setBuffer(((1)*COL_SIZE)-1, COL_SIZE, SadDisplayOne);
          mxSPI.setBuffer(((2)*COL_SIZE)-1, COL_SIZE, SadDisplayTwo);
          break;
        case 3:
          break;
    }
}

void EyeRight::updateEyeRightDisplay(MD_MAX72XX &mxSPI, int inputInt){
    switch(inputInt){
        case 0: // Idle Display
          mxSPI.setBuffer(((3)*COL_SIZE)-1, COL_SIZE, IdleDisplayOne);
          mxSPI.setBuffer(((4)*COL_SIZE)-1, COL_SIZE, IdleDisplayTwo);
          break;
        case 1: // Happy Display
          mxSPI.setBuffer(((3)*COL_SIZE)-1, COL_SIZE, HappyDisplayOne);
          mxSPI.setBuffer(((4)*COL_SIZE)-1, COL_SIZE, HappyDisplayTwo);
          break;
        case 2: // Sad Display
          mxSPI.setBuffer(((3)*COL_SIZE)-1, COL_SIZE, SadDisplayOne);
          mxSPI.setBuffer(((4)*COL_SIZE)-1, COL_SIZE, SadDisplayTwo);
          break;
        case 3:
          break;
    }
}