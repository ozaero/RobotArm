#include <Servo.h>


#define platformPin 2
#define bottom1Pin 3
#define bottom2Pin 4
#define midPin 5
#define topPin 6
#define hookPin 7

Servo platformS;
Servo bottom1S;
Servo bottom2S;
Servo midS;
Servo topS;
Servo hookS;

int platform, bottom, mid, top, hook;

void setup() {

  //Wake the servo motors
  platformS.attach(platformPin);
  bottom1S.attach(bottom1Pin);
  bottom2S.attach(bottom2Pin);
  midS.attach(midPin);
  topS.attach(topPin);
  hookS.attach(hookPin);
}

void loop() {

  //Robots move loop

  for(int i = 0; i< 7; i++){

    switch (i) {

      case 0:
      scene1();
      break;

      case 1:
      scene2();
      break;

      case 2:
      case 5:
      scene3();
      break;

      case 3:
      case 6:
      scene4();
      break;
    }

    move();
  }
}

void move(){

  platformS.write(platform);
  bottom1S.write(bottom);
  
  bottom -= 180;
  if(bottom < 0) bottom *= -1;

  bottom2S.write(bottom);

  midS.write(mid);
  topS.write(top);
  hookS.write(hook);
}

void scene1(){

  platform = 90;
  bottom = 75;
  mid = 120;
  top = 105;
  hook = 180;
}

void scene2(){

  platform = 0;
  bottom = 120;
  mid = 35;
  top = 105;
  hook = 0;
}

void scene3(){

  hook = 150;
}

void scene4(){

  platform = 0;
  bottom = 75;
  mid = 120;
  top = 105;
  hook = 180;
}
