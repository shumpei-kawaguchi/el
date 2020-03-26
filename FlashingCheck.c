void FlashingCheck(int mode){
  String TAG = "FlashingCheck()";
  mData = analogRead(sencer[mode].io);
  SystemPrint(TAG,String(mData) + ":" + String(sencer[mode].position));
  if (sencer[mode].average - mData > 100) {
    OverAverage(mode);
  }
  else {
    UnderAverage(mode);
  }
}

void OverAverage(int mode){
  String TAG = "OverAverage()";
  
  SystemPrint(TAG,String(sencer[mode].stage));

  if (sencer[mode].isChecking){
    
    if (sencer[mode].stage == 0) {
      sencer[mode].stage++;
    }
    else if (sencer[mode].stage == 1) {
      if (TimeOutCheck(mode) == TIME_OUT) {
        sencer[mode].stage = 0;
      }
      else {
        sencer[mode].timeOut++;
      }
    }
    else {
      FirebaseDataSend(mode);
    }
  }
  else{
    if (TimeOutCheck(mode) != TIME_OUT){
      sencer[mode].timeOut++;
      sencer[mode].stage = 1;
    }
  }
}

void UnderAverage(int mode){
  String TAG = "UnderAverage()";
  SystemPrint(TAG,String(sencer[mode].stage));
  
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
    return TIME_OUT;
  }
  else {
    return 0;
  }
}