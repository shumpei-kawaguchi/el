/*
 * @Eremiru
 * Copyright 2020 Shumpei Kawaguchi. All rights reserved.
 *
 * This source code or any portion thereof must not be  
 * reproduced or used in any manner whatsoever.
 */
#include <WiFi.h>
#include <WiFiMulti.h>
#include <WiFiClientSecure.h>

WiFiClientSecure client;
WiFiMulti wifiMulti;

#define LIMIT 100
#define TIME_OUT 5

#define LEVEL 1
#define POSITION "L" //R or L
#define TEST false

#define RIGHT "Right"
#define LEFT "Left"
#define CENTER "Center"

#define UP "UP"
#define DOWN "DOWN"

int mData;
const int io[6] = {32,33,34,35,36,39};
const int ledList[7] = {0,4,16,17,5,18,19};

struct sencer {
  boolean isChecking;
  int stage;
  int timeOut;
};
sencer sencer[4];

typedef struct data {
  int count;
  int dataList[100];
  int sum;
  int average;
};

struct data data[4];
struct data bufData[4];


void setup() {
  Serial.begin(115200);
  for(int i = 0; i < 7; i++){
    pinMode(ledList[i],OUTPUT);
  }
  Init();
  WifiConnect();
  SystemPrint("setup()","END");
}

void loop() {
  SystemPrint("loop()",F("====================================="));
  if(WiFi.status() != WL_CONNECTED){
    WifiConnect();
  }

  int m = Mode();
  
  for(int mode = 0; mode < m; mode++) {
    int stage = sencer[mode].stage;
    
    FlashingCheck(mode);
    
    if(stage != sencer[mode].stage){
      sencer[mode].timeOut = 0;
    }
    IoPrint(mode);
    IoStatus(sencer[mode].stage, Position(mode));
  }
  SystemPrint("loop()","END");
  delay(100/m);
}