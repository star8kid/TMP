#include "Arduino.h"
#include "Mouth.h"

void MouthLeft::updateMouthLeftDisplay(MD_MAX72XX &mxSPI, int inputInt){
      // First determine which switch case based no the Emotions enum
      switch(inputInt){
        case 0:

          // Future Refactoring: Figure out how to loop between each array pointer in the array of displays below

          // for(uint8_t a = partFirstDeviceIndex; a < (partFirstDeviceIndex + partMaxDevices); a++){
          //   // need something to properly set each of these cases for the different displays
          //   mx.setBuffer(((a + 1)*COL_SIZE)-1, COL_SIZE, IdleDisplayArray[a - partFirstDeviceIndex]);
          // }

          // Array Address Test
          // uint8_t *testPtr = &IdleDisplayOne[0];
          // int aArray[] = {10,20,30};
          // int *aPtr = &aArray[0];
          // Serial.print(&IdleDisplayOne[0]);
          // Serial.print(testPtr);
          // Serial.println((uint8_t)&IdleDisplayOne);
          // Serial.println((uint8_t)&IdleDisplayTwo);
          // Serial.println((uint8_t)&IdleDisplayThree);
          // Serial.println((uint8_t)&IdleDisplayFour);
          // Serial.println(IdleDisplayArray[0]);
          // Serial.println(IdleDisplayArray[0][0]);

          // mx.setBuffer(((1)*COL_SIZE)-1, COL_SIZE, IdleDisplayOne);
          // mx.setBuffer(((2)*COL_SIZE)-1, COL_SIZE, IdleDisplayTwo);
          // mx.setBuffer(((3)*COL_SIZE)-1, COL_SIZE, IdleDisplayThree);
          // mx.setBuffer(((4)*COL_SIZE)-1, COL_SIZE, IdleDisplayFour);

          mxSPI.setBuffer(((this->partFirstDeviceIndex + 1)*COL_SIZE)-1, COL_SIZE, IdleDisplayOne);
          mxSPI.setBuffer(((this->partFirstDeviceIndex + 2)*COL_SIZE)-1, COL_SIZE, IdleDisplayTwo);
          mxSPI.setBuffer(((this->partFirstDeviceIndex + 3)*COL_SIZE)-1, COL_SIZE, IdleDisplayThree);
          mxSPI.setBuffer(((this->partFirstDeviceIndex + 4)*COL_SIZE)-1, COL_SIZE, IdleDisplayFour);

          break;
        case 1:
          break;
        case 2:
          break;
        case 3:
          break;
      }
}

void::MouthMiddle::updateMouthMiddleDisplay(MD_MAX72XX &mxSPI, int inputInt){

}

void::MouthRight::updateMouthRightDisplay(MD_MAX72XX &mxSPI, int inputInt){
  switch(inputInt){
    case 0:
          mxSPI.setBuffer(((this->partFirstDeviceIndex + 1)*COL_SIZE)-1, COL_SIZE, IdleDisplayOne);
          mxSPI.setBuffer(((this->partFirstDeviceIndex + 2)*COL_SIZE)-1, COL_SIZE, IdleDisplayTwo);
          mxSPI.setBuffer(((this->partFirstDeviceIndex + 3)*COL_SIZE)-1, COL_SIZE, IdleDisplayThree);
          mxSPI.setBuffer(((this->partFirstDeviceIndex + 4)*COL_SIZE)-1, COL_SIZE, IdleDisplayFour);
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
  }
}