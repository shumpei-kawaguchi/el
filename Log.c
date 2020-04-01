/*
 * @Elemiru
 * Copyright 2020 Shumpei Kawaguchi. All rights reserved.
 *
 * This source code or any portion thereof must not be  
 * reproduced or used in any manner whatsoever.
 */
void SystemPrint(String TAG,String msg){
  Serial.println( "[S][ " + TAG + " ]:" + msg);
}

void IoPrint(int mode) {
  Serial.print( "[i]");
  Serial.print(" io:" + String(Io(mode)));
  
  if(sencer[mode].isChecking){
    Serial.print(" isChecking");
  }
  Serial.print("---->");
  Serial.print("stage:" + String(sencer[mode].stage));
  Serial.print(",count:" + String(data[mode].count));
  Serial.print(",sum:" + String(data[mode].sum));
  Serial.print(",average:" + String(data[mode].average));  
  Serial.print(",bufcount:" + String(bufData[mode].count));
  Serial.print(",bufSum:" + String(bufData[mode].sum));
  Serial.print(",bufAverage:" + String(bufData[mode].average));
  Serial.println(",timeOut:" + String(sencer[mode].timeOut));
}