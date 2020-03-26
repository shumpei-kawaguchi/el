void FirebaseDataSend(int mode){
  String TAG = "FirebaseDataSend()";

  IoStatus(3,sencer[mode].position);
  sencer[mode].timeOut = 0;
  sencer[mode].isChecking = false;
 
  const char *host = "your project host";
 
  if (client.connect(host, 443)) {
    SystemPrint(TAG,host);
    Serial.print(F("-------------"));
    Serial.println(F("connected"));
    Serial.println(F("--------------------Realtime Database HTTP GET Request Send"));
 
    String str1 = "GET /postLocation?position=" + sencer[mode].position + "&level=" + String(LEVEL) + "&dir=" + sencer[mode].dir + " HTTP/1.1\r\n";
    String str2 = "Host: " + String(host) + "\r\n";
    String str3 = "Content-Type: text/html; charset=utf-8\r\n";
    String str4 = "Connection:close\r\n\r\n";
 
    client.print( str1 );
    client.print( str2 );
    client.print( str3 );
    client.print( str4 );

    SystemPrint(TAG,str1 + str2 + str3 + str4 );

    Serial.println(F("--------------------Realtime Database HTTP Response"));
 
    char c;
    while(client.connected()){
      while (client.available()) {
        c = client.read();
        Serial.print(c);
      }
      client.flush();
      delay(10);
      client.stop();
      delay(10);
      Serial.println(F("--------------------Client Stop"));
      break;
    }
  }else {
    SystemPrint(TAG,F("connection failed"));
  }
  sencer[mode].stage = 0;
  SystemPrint(TAG,"END");
}