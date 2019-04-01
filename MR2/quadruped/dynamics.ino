
const float bone_length = 32;
const float l1 = 10;
const float l2 = 21;
const float stand_height = 30;
const int leg_2_servo[4] = {0,2,4,6};

void straight_pos() {
  for(int i=0; i<4; i++) {
    move_leg(i,0,0);
  }
}

void rest_pos() {
  float t1,t2;
  ik(0,0,NULL,&t1,&t2);

  for(int i=0; i<4; i++) {
    move_leg(i,t1,t2);
  }
}

void ik(float x,float y,int leg_no,float *t1,float *t2) {
  
  // y coordinate transform
  y = stand_height-y;
  
  //float k=acos(sqrt(x*x+y*y)/2/bone_length);
  //*t1 = (atan2(x,y)+k)*180/PI; // for > config
  //*t1 = (-atan2(x,y)+k)*180/PI; // for < config
  //*t2 = 2*k*180/PI;

  *t1 = ((atan2(x,y)+acos((l1*l1+x*x+y*y-l2*l2)/2/l1/sqrt(x*x+y*y))))*180/PI;
  *t2 = 180-acos((l1*l1+l2*l2-x*x-y*y)/2/l1/l2)*180/PI;
}

void move_leg(int leg_no,float t1, float t2) {
  move_servo(leg_2_servo[leg_no],t1);
  move_servo(leg_2_servo[leg_no]+1,t2);
}
