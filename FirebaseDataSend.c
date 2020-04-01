/*
 * @Eremiru
 * Copyright 2020 Shumpei Kawaguchi. All rights reserved.
 *
 * This source code or any portion thereof must not be  
 * reproduced or used in any manner whatsoever.
 */
void FirebaseDataSend(int mode){

  IoStatus(3,Position(mode));
   
  if (client.connect("your client", 443)) {
    SystemPrint("FirebaseDataSend()","your client");
    Serial.print(F("-------------"));
    Serial.println(F("connected"));
    Serial.println(F("--------------------Realtime Database HTTP GET Request Send"));
 
    client.print("GET /postLocation?position=" + Position(mode) + "&level=" + String(LEVEL) + "&dir=" + Direction(mode) + " HTTP/1.1\r\n");
    client.print("Host: host\r\n");
    client.print("Content-Type: text/html; charset=utf-8\r\n");
    client.print("Connection:close\r\n\r\n");

    Serial.println(F("--------------------Realtime Database HTTP Response"));
 
    while(client.connected()){
      while (client.available()) {
        Serial.print(client.read());
      }
      client.flush();
      delay(10);
      client.stop();
      delay(10);
      Serial.println(F("--------------------Client Stop"));
      break;
    }
  }else {
    SystemPrint("FirebaseDataSend()","connection failed");
  }
  SystemPrint("FirebaseDataSend()","END");
}