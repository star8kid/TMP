#include "Eyes.h"
// #include "Arduino.h"

void EyeLeft::updateEyeLeftDisplay(MD_MAX72XX &mxSPI, int inputInt){ // Passing the `mx` object by reference so it doesn't get copied
  // Debug Print Statements
  // Serial.println("Setting Buffer in Left Eye display...");  
  switch(inputInt){
        case 0: // Idle Display
          mxSPI.setBuffer((this->partFirstDeviceIndex + 0)*COL_SIZE - 1, COL_SIZE, IdleDisplayOne);
          mxSPI.setBuffer((this->partFirstDeviceIndex + 1)*COL_SIZE - 1, COL_SIZE, IdleDisplayTwo);
          // Serial.println("Set Buffer to Idle Display");
          break;
        case 1: // Happy Display
          mxSPI.setBuffer((this->partFirstDeviceIndex + 0)*COL_SIZE - 1, COL_SIZE, HappyDisplayOne);
          mxSPI.setBuffer((this->partFirstDeviceIndex + 1)*COL_SIZE - 1, COL_SIZE, HappyDisplayTwo);
          // Serial.println("Set Buffer to Happy Display");
          break;
        case 2: // Sad Display
          mxSPI.setBuffer((this->partFirstDeviceIndex + 0)*COL_SIZE - 1, COL_SIZE, SadDisplayOne);
          mxSPI.setBuffer((this->partFirstDeviceIndex + 1)*COL_SIZE - 1, COL_SIZE, SadDisplayTwo);
          // Serial.println("Set Buffer to Sad Display");
          break;
        case 3: // Angry Display
          mxSPI.setBuffer((this->partFirstDeviceIndex + 0)*COL_SIZE - 1, COL_SIZE, AngryDisplayOne);
          mxSPI.setBuffer((this->partFirstDeviceIndex + 1)*COL_SIZE - 1, COL_SIZE, AngryDisplayTwo);
          // Serial.println("Set Buffer to Angry Display");
          break;
    }
}

void EyeRight::updateEyeRightDisplay(MD_MAX72XX &mxSPI, int inputInt){
  // Serial.println("Setting Buffer in Right Eye display...");  
    switch(inputInt){
      case 0:
        mxSPI.setBuffer((this->partFirstDeviceIndex + 0)*COL_SIZE - 1, COL_SIZE, IdleDisplayOne);
        mxSPI.setBuffer((this->partFirstDeviceIndex + 1)*COL_SIZE - 1, COL_SIZE, IdleDisplayTwo);
        // Serial.println("Set Buffer to Idle Display");
        break;
      case 1:
        mxSPI.setBuffer((this->partFirstDeviceIndex + 0)*COL_SIZE - 1, COL_SIZE, HappyDisplayOne);
        mxSPI.setBuffer((this->partFirstDeviceIndex + 1)*COL_SIZE - 1, COL_SIZE, HappyDisplayTwo);
        // Serial.println("Set Buffer to Happy Display");
        break;
      case 2:
        mxSPI.setBuffer((this->partFirstDeviceIndex + 0)*COL_SIZE - 1, COL_SIZE, SadDisplayOne);
        mxSPI.setBuffer((this->partFirstDeviceIndex + 1)*COL_SIZE - 1, COL_SIZE, SadDisplayTwo);
        // Serial.println("Set Buffer to Sad Display");
        break;
      case 3: 
        mxSPI.setBuffer((this->partFirstDeviceIndex + 0)*COL_SIZE - 1, COL_SIZE, AngryDisplayOne);
        mxSPI.setBuffer((this->partFirstDeviceIndex + 1)*COL_SIZE - 1, COL_SIZE, AngryDisplayTwo);
        // Serial.println("Set Buffer to Angry Display");
        break;
    }
}