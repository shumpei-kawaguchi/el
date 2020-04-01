/*
 * @Elemiru
 * Copyright 2020 Shumpei Kawaguchi. All rights reserved.
 *
 * This source code or any portion thereof must not be  
 * reproduced or used in any manner whatsoever.
 */
void AllOn() {
  for(int i; i < 7; i ++){
     digitalWrite(ledList[i],1);
  }
}

void AllOff() {
  for(int i; i < 7; i ++){
     digitalWrite(ledList[i],0);
  }
}

void IoStatus(int stage, String position){
  
    if(stage == 1){
      if(position == "Right"){
        digitalWrite(17,1);
        digitalWrite(5,0);
        digitalWrite(19,0);
      }
      else{
        digitalWrite(4,1);
        digitalWrite(16,0);
        digitalWrite(18,0);
      }
    }
    else if(stage == 2){
      if(position == "Right"){
        digitalWrite(17,0);
        digitalWrite(5,1);
        digitalWrite(19,0);
      }
      else{
        digitalWrite(4,0);
        digitalWrite(16,1);
        digitalWrite(18,0);
      }
    }
    else if(stage == 3){
      if(position == "Right"){
        digitalWrite(19,1);
      }else{
        digitalWrite(18,1);
      }
    }
    else{
      if(position == "Right"){
        digitalWrite(17,0);
        digitalWrite(5,0);
        digitalWrite(19,0);
     }
     else{
      digitalWrite(4,0);
      digitalWrite(16,0);
      digitalWrite(18,0);
    }
  }
}