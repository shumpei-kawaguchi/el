/*
 * @Elemiru
 * Copyright 2020 Shumpei Kawaguchi. All rights reserved.
 *
 * This source code or any portion thereof must not be  
 * reproduced or used in any manner whatsoever.
 */
void WifiConnect(){
  AllOff();
  WiFi.disconnect(true);
  delay(10);
  wifiMulti.addAP(GetSSID(), GetPASS());
  Serial.print("WiFi connecting");
  while (wifiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(1);
  }
   Serial.println();
  SystemPrint("WifiConnect()","WiFi connected: " + String(WiFi.SSID()));
  digitalWrite(0,1);
  SystemPrint("WifiConnect()","END");
}

const char* GetSSID(){
  if(TEST){
    return "ssid1";
  }else{
    if(LEVEL == 1){
      return "ssid2";
    }
    else if(LEVEL == 2){
      return "ssid3";
    }
  }
}


const char* GetPASS(){
  if(TEST){
    return "pass1";
  }else{
    if(LEVEL == 1){
      return "pass2";
    }
    else if(LEVEL == 2){
      return "pass3";
    }

  }
}