void MakeAverage(int mode) {
  String TAG = "makeAverage()";
  
  int sum = 0;
  sencer[mode].dataList[sencer[mode].count] = mData;
 
  for (int i = 0; i < LIMIT; i++) {
      sum += sencer[mode].dataList[i];
  }

  sencer[mode].count++;

  if (!sencer[mode].inProgress){
    sencer[mode].average = sum / sencer[mode].count; 
  }
  else {
    sencer[mode].average = sum / LIMIT;
  }
  
  if (sencer[mode].count >= LIMIT) {
    if (!sencer[mode].inProgress){
      sencer[mode].inProgress = true;
    }
    sencer[mode].count -= LIMIT;
  }
}

void MakeBufAverage(int mode) {
  String TAG = "makeBufAverage()";

  int sum = 0;
          
  sencer[mode].bufCount = sencer[mode].count + sencer[mode].timeOut;
  sencer[mode].bufDataList[sencer[mode].bufCount] = mData;
  
  for (int i = 0; i < LIMIT; i++) {
    sencer[mode].bufDataList[i] = sencer[mode].dataList[i];
    sum += sencer[mode].bufDataList[i];
  }

  sencer[mode].timeOut++;

  if (!sencer[mode].inProgress && sencer[mode].bufCount <= LIMIT) {
    sencer[mode].bufAverage = sum / sencer[mode].bufCount;
  }
  else {
    sencer[mode].bufAverage = sum / LIMIT;
  }
  if (sencer[mode].bufCount >= LIMIT) {
    sencer[mode].bufCount -= LIMIT;
  }
}

void PushAverage(int mode) {
  String TAG = "makeBufAverage()";
  for (int i = 0; i < LIMIT; i++) {
    sencer[mode].dataList[i] = sencer[mode].bufDataList[i];
  }
  sencer[mode].bufDataList[100] = {};
  sencer[mode].average = sencer[mode].bufAverage;
  sencer[mode].count = sencer[mode].bufCount;
}