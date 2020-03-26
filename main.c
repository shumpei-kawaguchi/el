#include <WiFi.h>
#include <WiFiMulti.h>
#include <WiFiClientSecure.h>

#define LIMIT 100
#define TIME_OUT 5

#define LEVEL 1
#define POSITION "R" //R or L
#define TEST false

int mData;
int ledList[7] = {0,4,16,17,5,18,19};

struct preference {
  const char* ssid;
  const char* password;
  int mode;
  int io[4];
  String position[4];
  String dir[4];
};

struct sencer {
  int io;
  String position;
  String dir;
  boolean inProgress;
  boolean isChecking;
  int stage;
  int count;
  int dataList[100];
  int average;
  int bufCount;
  int bufDataList[100];
  int bufAverage;
  int timeOut;
};

WiFiClientSecure client;
WiFiMulti wifiMulti;

preference preference;
sencer sencer[4];


void setup() {
  String TAG = "setup()";
  Serial.begin(115200);
  for(int i = 0; i < 6; i++){
    pinMode(ledList[i],OUTPUT);
  }
  SetPreference();
  Init();
  WifiConnect();
  SystemPrint(TAG,"END");
}

void loop() {
  String TAG = "loop()";

  if(WiFi.status() != WL_CONNECTED){
    WifiConnect();
  }else{
    SystemPrint(TAG,"WIFI DISCONNECTED");
  }
  
  for(int mode = 0; mode < preference.mode; mode++) {
    int stage = sencer[mode].stage;
    
    FlashingCheck(mode);
    
    if(stage != sencer[mode].stage){
      sencer[mode].timeOut = 0;
    }
    
    IoStatus(sencer[mode].stage, sencer[mode].position);
    IoPrint(mode);
    
  }
  SystemPrint(TAG,"END");
  delay(100);
}
