#include "vex.h"]

//variables 
bool catDone = true; 

bool catapultFinished() {
  return catDone;
}

void IntakeSpin(){  //hold button
  Intake.spin(forward, 100, pct);
}

void outtakeSpin() {
  Intake.spin(reverse, 100, pct);
}

void IntakeStop(){
  Intake.stop();
}

void catapultHome() {   //brings catapult to home position and uses "pid" (hold brake type) to stay in place 
  Catapult1.spinToPosition(0, degrees); 
  //Catapult2.spinToPosition(0, degrees);
  Catapult1.stop(hold);
  //Catapult2.stop(hold);
}

//"ready" position at 0 degree encs 
void catapultOnce(/*bool waitForCompletion=true*/) {
  catDone = false;

  catapultHome();
  Catapult1.spinToPosition(360, degrees); 
  //Catapult2.spinToPosition(360, degrees);
  catapultHome();

  catDone = true;

}

void rapidFire() {
  Catapult1.spin(forward, 127, pct);
  //Catapult2.spin(forward, 127, pct);
  catapultHome();
}

void intakeDeploy() {
  IntakePiston1.set(true); 
  //IntakePiston2.set(true); 

}

void intakeRetract() {
  IntakePiston1.set(false); 
  //IntakePiston2.set(false); 
}