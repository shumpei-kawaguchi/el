/*
 * @Eremiru
 * Copyright 2020 Shumpei Kawaguchi. All rights reserved.
 *
 * This source code or any portion thereof must not be  
 * reproduced or used in any manner whatsoever.
 */
void FlashingCheck(int mode){
  mData = analogRead(Io(mode));
  SystemPrint("flashingCheck()",String(mData) + ":" + Position(mode));
  if (data[mode].average - mData > 100) {
    OverAverage(mode);
  }
  else {
    UnderAverage(mode);
  }
}

void OverAverage(int mode){  
  SystemPrint("overAverage()",String(data[mode].average - mData));

  if (sencer[mode].isChecking){
    
    if (sencer[mode].stage == 0) {
      sencer[mode].stage++;
    }
    else if (sencer[mode].stage == 1) {
      if (TimeOutCheck(mode) == TIME_OUT) {
        PushAverage(mode);
      }
      else {
        MakeBufAverage(mode);
      }
    }
    else {
      sencer[mode].timeOut = 0;
      sencer[mode].isChecking = false;
      FirebaseDataSend(mode);
      sencer[mode].stage = 0;
    }
  }
  else{
    if (TimeOutCheck(mode) == TIME_OUT) {
        PushAverage(mode);
      }
      else {
        MakeBufAverage(mode);
        sencer[mode].stage = 1;
      }
  }
}

void UnderAverage(int mode){
  SystemPrint("underAverage()",String(data[mode].average - mData));
  
  if (sencer[mode].isChecking){
    
    if(sencer[mode].stage == 0) {
      MakeAverage(mode);
    }
    else if (sencer[mode].stage == 1) {
      sencer[mode].stage++;
    }
    else {
      if (TimeOutCheck(mode) == TIME_OUT) {
        PushAverage(mode);
      }
      else {
        MakeBufAverage(mode);
      }
    }
  }
  else {
    if (TimeOutCheck(mode) == TIME_OUT) {
      PushAverage(mode);
    }
    else {
      MakeBufAverage(mode);
      sencer[mode].stage = 0;
    }
  }
}

int TimeOutCheck(int mode) {
  
  if (TIME_OUT < sencer[mode].timeOut) {
    sencer[mode].timeOut = 0;
    sencer[mode].stage = 0;
    if(!sencer[mode].isChecking) {
      sencer[mode].isChecking = true;
    }
    SystemPrint("TimeOutCheck()","TIME_OUT");
    return TIME_OUT;
  }
  else {
    return 0;
  }
}