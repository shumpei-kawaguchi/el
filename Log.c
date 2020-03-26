
void SystemPrint(String TAG,String msg){
  Serial.println( "[S][" + TAG + "]:" + msg);
}

void IoPrint(int mode) {
  Serial.print( "[i]");
  Serial.print("[io:" + String(sencer[mode].io));
  if(sencer[mode].inProgress){
    Serial.print(",inProgress");
  }
  if(sencer[mode].isChecking){
    Serial.print(",isChecking");
  }
  Serial.print("\nstage:" + String(sencer[mode].stage));
  Serial.print(",average:" + String(sencer[mode].average));
  Serial.print(",bufAverage:" + String(sencer[mode].bufAverage));
  Serial.print(",count:" + String(sencer[mode].count));
  Serial.print(",bufcount:" + String(sencer[mode].bufCount));
  Serial.print(",timeOut:" + String(sencer[mode].timeOut));
}