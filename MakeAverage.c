/*
 * @Elemiru
 * Copyright 2020 Shumpei Kawaguchi. All rights reserved.
 *
 * This source code or any portion thereof must not be  
 * reproduced or used in any manner whatsoever.
 */
void MakeAverage(int mode) {

  int count = data[mode].count;
  int sum = data[mode].sum;
  int average = 0;

  count++;

  if ( count < 100 ) {
    sum += mData;
    data[mode].dataList[count] = mData;
    average = sum / count;
  }
  else {
    if( count > 199 ) count -= 100;
    sum += ( mData - data[mode].dataList[count - 100] );
    data[mode].dataList[count - 100] = mData;
    average = sum / 100;
  }

  data[mode].count = count;
  data[mode].sum = sum;
  data[mode].average = average;
}

void MakeBufAverage(int mode) {

  int sum = bufData[mode].sum;
  
  if(sencer[mode].timeOut == 0){
    sum = 0;
    for (int i = 0; i < LIMIT; i++) {
      bufData[mode].dataList[i] = data[mode].dataList[i];
      sum += bufData[mode].dataList[i];
    }
  }
  
  sencer[mode].timeOut++;

  int count = data[mode].count + sencer[mode].timeOut;
  int average = 0;

  if ( count < 100 ) {
    sum += mData;
    bufData[mode].dataList[count] = mData;
    average = sum / count;
  }
  else {
    if( count > 199 ) count -= 100;
    sum += ( mData - bufData[mode].dataList[count - 100] );
    bufData[mode].dataList[count - 100] = mData;
    average = sum / 100;
  }

  bufData[mode].count = count;
  bufData[mode].sum = sum;
  bufData[mode].average = average;
  
}

void PushAverage(int mode) {
  for (int i = 0; i < LIMIT; i++) {
    data[mode].dataList[i] = bufData[mode].dataList[i];
  }
  data[mode].sum = bufData[mode].sum;
  data[mode].average = bufData[mode].average;
  data[mode].count = bufData[mode].count;
}