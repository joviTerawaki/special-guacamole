#include "vex.h" 
#include "robot-config.h"

bool toggle = false;

void print() { 
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print(toggle);
}

void shoot() {
  print();
  if (!toggle) {
    toggle = true;
    MotorShooties.spin(fwd, 100 , pct);
  }
  else if (toggle) { 
    MotorShooties.stop();
    toggle = false;
    return;
  }
}

void shootOn() {
  MotorShooties.spin(fwd,100,pct);
}

void shootOff() {
  MotorShooties.stop(hold);
}

void blockUp() {
  Blockah1.set(true);
  Blockah2.set(true);
}

void blockDown() {
  Blockah1.set(false);
  Blockah2.set(false);
}

// void tank() {
//   LeftFront.spin(forward, Controller1.Axis3.value(), pct);
//   LeftTop.spin(forward, Controller1.Axis3.value(), pct);
//   LeftBack.spin(forward, Controller1.Axis3.value(), pct);

//   RightFront.spin(forward, Controller1.Axis2.value(), pct);
//   RightTop.spin(forward, Controller1.Axis2.value(), pct);
//   RightBack.spin(forward, Controller1.Axis2.value(), pct);
// }

// void topMotors() {
//     LeftTop.spin(fwd, Controller1.Axis3.value(), pct);
//     RightTop.spin(fwd, Controller1.Axis2.value(), pct);
// }

// void flapjackDeploy() {
//   Flapjack.set(true); 
//   // Flapjack2.set(true); 
// }

// void flapjackRetract() {
//   Flapjack.set(false); 
//   // Flapjack2.set(false); 
// }

