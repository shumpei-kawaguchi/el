
void WifiConnect(){
  String TAG = "WifiConnect()";
  AllOff();
  WiFi.disconnect(true);
  delay(10);
  SetWifiPass();
  wifiMulti.addAP(preference.ssid, preference.password);
  SystemPrint(TAG,String(preference.ssid));
  Serial.print("WiFi connecting");
  while (wifiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(1);
  }
   Serial.println();
  SystemPrint(TAG,"WiFi connected: " + String(WiFi.SSID()));
  digitalWrite(0,1);
  SystemPrint(TAG,"END");
}

void SetWifiPass(){
  String TAG = "SetWifiPass()";
  if(TEST){
    preference.ssid = "ssid";
    preference.password = "pass";
  }else{
    if(LEVEL == 1){
      preference.ssid = "ssid";
      preference.password = "ssid";
    }
    else if(LEVEL == 2){
      preference.ssid = "ssid";
      preference.password = "pass";
    }
    else if(LEVEL == 3){
      preference.ssid = "ssid";
      preference.password = "pass";
    }
    else if(LEVEL == 4){
      preference.ssid = "ssid";
      preference.password = "pass";
    }
    else if(LEVEL == 5){
      preference.ssid = "ssid";
      preference.password = "pass";
    }
    else if(LEVEL == 6){
      preference.ssid = "ssid";
      preference.password = "pass";
    }
    else if(LEVEL == 7){
      preference.ssid = "ssid";
      preference.password = "pass";
    }
    else if(LEVEL == 8){
      preference.ssid = "ssid";
      preference.password = "pass";
    }
    else if(LEVEL == 9){
      preference.ssid = "ssid";
      preference.password = "pass";
    }
  }
  SystemPrint(TAG,"END");
}