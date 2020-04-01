/*
 * @Elemiru
 * Copyright 2020 Shumpei Kawaguchi. All rights reserved.
 *
 * This source code or any portion thereof must not be  
 * reproduced or used in any manner whatsoever.
 */
void Init(){
  for(int mode = 0; mode < Mode(); mode++){
    sencer[mode].isChecking = true;
    sencer[mode].stage = 0;
    sencer[mode].timeOut = 0;
    
    data[mode].count = 0;
    data[mode].dataList[100] = {};
    data[mode].sum = 0;
    data[mode].average = 0;
    
    bufData[mode].count = 0;
    bufData[mode].dataList[100] = {};
    bufData[mode].sum = 0;
    bufData[mode].average = 0;
    IoPrint(mode);
  }
  SystemPrint("init()","END");
}