void Init(){
  String TAG = "Init()";
  for(int mode = 0; mode < preference.mode; mode++){
    sencer[mode].io = preference.io[mode];
    sencer[mode].position = preference.position[mode];
    sencer[mode].dir = preference.dir[mode];
    sencer[mode].inProgress = false;
    sencer[mode].isChecking = true;
    sencer[mode].stage = 0;
    sencer[mode].count = 0;
    sencer[mode].dataList[100] = {};
    sencer[mode].average = 0;
    sencer[mode].bufCount = 0;
    sencer[mode].bufDataList[100] = {};
    sencer[mode].bufAverage = 0;
    sencer[mode].timeOut = 0;
    IoPrint(mode);
  }
  SystemPrint(TAG,"END");
}

void SetPreference(){
  String TAG = "SetPreference()";
  
  if(LEVEL != 1){
    if(POSITION == "R"){

      preference.io[0] = 36;
      preference.io[1] = 39;
      preference.io[2] = 34;
      preference.io[3] = 35;
      
      for(int i = 0; i < 4; i++){

        if(i < 2) {
          preference.position[i] = "right";
        }
        else {
          preference.position[i] = "center";
        }
        
        if(i == 1 || i == 3) {
          preference.dir[i] = "DOWN";
        }
        else {
          preference.dir[i] = "UP";
        }
      }
      
      preference.mode = 4;
    }else{
      preference.io[0] = 32;
      preference.io[1] = 33;
      preference.position[0] = "left";
      preference.position[1] = "left";

      preference.dir[0] = "UP";
      preference.dir[1] = "BOWN";
        
      preference.mode = 2;
    }
    
  }else{
    
    if(POSITION == "R"){
      preference.io[0] = 36;
      preference.io[1] = 34;
      preference.position[0] = "right";
      preference.position[1] = "center";
      preference.dir[0] = "UP";
      preference.dir[1] = "UP";
      preference.mode = 2;
    }else{
      preference.io[0] = 32;
      preference.position[0] = "left";
      preference.dir[0] = "UP";
      preference.mode = 1;
    }
    
  }
  SystemPrint(TAG,"preference.mode:" + String(preference.mode));
  for(int i = 0; i < preference.mode; i++) {
    SystemPrint(TAG,"io:" + String(preference.io[i]) + ",position:" + preference.position[i] + ",dir:" + preference.dir[i]);
  }
  SystemPrint(TAG,"END");
}