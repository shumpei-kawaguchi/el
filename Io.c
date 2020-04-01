/*
 * @Eremiru
 * Copyright 2020 Shumpei Kawaguchi. All rights reserved.
 *
 * This source code or any portion thereof must not be  
 * reproduced or used in any manner whatsoever.
 */
int Mode() {
  if(LEVEL != 1){
    if(POSITION == "R") return 4;
    else return 2;    
  }else{
    if(POSITION == "R") return 2;
    else return 1;
  }
}

String Position(int mode) {
  int io = Io(mode);
  if(io == 32 || io == 33) return LEFT;
  else if(io == 34 || io == 35) return CENTER;
  else if(io == 36 || io == 39) return RIGHT;
}

String Direction(int mode) {
  int io = Io(mode);
  if(io == 32 || io == 34 || io == 36) return UP;
  else if (io == 33 || io == 35 || io == 39) return DOWN;
}

int Io(int mode) {
  int m = Mode();
  if(m == 4){
    if(mode == 0) return io[4];
    else if(mode == 1) return io[5];
    else if(mode == 2) return io[2];
    else if(mode == 3) return io[3];
  }
  else if(m == 2) {
    if(LEVEL != 1){
      if(mode == 0) return io[0];
      else if(mode == 1) return io[1];
    }
    else{
      if(mode == 0) return io[4];
      else if(mode == 1) return io[2];
    }
  }
  else return io[0];
}