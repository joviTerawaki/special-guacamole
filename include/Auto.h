#include "vex.h"
#include "AnotherPID.h"
// #include "pid.h"
#include "DriverControl.h"

void revampedTurnFor(double ang, char dir, double error) {
  while(true) {
    if (fmod(Drivetrain.rotation(degrees), 360.0) >= ang-error && (fmod(Drivetrain.rotation(degrees), 360.0)) <= ang+error) {
      Drivetrain.stop(hold);
      break;
    }
    if (dir == 'R') {Drivetrain.turn(right);}
    else if (dir == 'L') {Drivetrain.turn(left);}
  }
}

void setCatapult(double ang) {

  // RotationalSensor.resetPosition();
  // while(true) {
    if (RotationalSensor.angle() <= ang + 3 && RotationalSensor.angle() >= ang - 3) {
      // Controller1.Screen.setCursor(2, 1);
      // Controller1.Screen.print("IN RANGE");
      // wait(0.005, seconds);
      MotorShooties.stop(hold);
      // break;
    } else {
      // Controller1.Screen.setCursor(2, 1);
      // Controller1.Screen.print("NOT IN RANGE");
      MotorShooties.spin(forward, 40, pct);
    }
  // }

  // while(!(RotationalSensor.angle() <= ang + 2 && RotationalSensor.angle() >= ang - 2)) {
  //   MotorShooties.spin(forward, 60, pct);
  //   // MotorShooties.stop(coast);
  // }
  // // MotorShooties.spin(forward, 60, pct);
  // MotorShooties.stop(coast);

}

void bash(double inc, int iterations) {
  for (int i = 0; i < iterations; i++) {
    wait(250, msec);
    Drivetrain.setDriveVelocity(60, percent); 
    Drivetrain.driveFor(reverse, inc, inches);
    wait(250, msec); 
    Drivetrain.setDriveVelocity(70, percent);
    Drivetrain.driveFor(forward, inc+1, inches);
  }
}

void skills() {
  //Catapult tingies towards goal
  Drivetrain.setDriveVelocity(40, pct);
  Drivetrain.setTurnVelocity(3, pct);

  Drivetrain.setHeading(240, deg);
  MotorShooties.spin(fwd, 100, pct);
  wait(30, sec); //catapult for 30 seconds, 3 seconds is just a test value
  MotorShooties.stop(hold);
  
  //turn to bar, drive under bar
  Drivetrain.driveFor(reverse, .5, inches);
  setCatapult(305);
  Drivetrain.turnToHeading(273, deg);
  Drivetrain.setDriveVelocity(25, pct);
  Drivetrain.driveFor(reverse, 38, inches);
  Drivetrain.turnToHeading(0, deg);

  //go out to push in 
  Drivetrain.setDriveVelocity(30, pct);
  Drivetrain.driveFor(fwd, 8, inches);
  Drivetrain.turnToHeading(312, deg);

  // Drivetrain.setDriveVelocity(17, percent); 
  // Drivetrain.driveFor(forward, 7, inches); 
  // Drivetrain.driveFor(reverse, 15, inches);
  Drivetrain.setDriveVelocity(40, percent);
  // Drivetrain.driveFor(reverse, 38.25, inches);

  //turn to goal, score
  Drivetrain.driveFor(fwd,19.375,inches);
  Drivetrain.setTurnVelocity(4, percent);
  Drivetrain.turnToHeading(73, degrees);
  Flapjack1.set(true);
  Intake.spin(reverse,80,pct);
  wait(500,msec);
  Drivetrain.setDriveVelocity(60, percent);
  Drivetrain.driveFor(fwd, 10, inches);
  bash(9, 1);

  // //2nd push in 
  // Drivetrain.driveFor(reverse, 11, inches);
  // Drivetrain.turnToHeading(79, degrees);
  // Drivetrain.setDriveVelocity(40, percent);
  // Drivetrain.driveFor(fwd, 10, inches);
  // bash(9, 1);

  //reverse
  Flapjack1.set(false);
  wait(100,msec);
  Drivetrain.setDriveVelocity(35,pct);
  Drivetrain.driveFor(reverse, 16, inches);
  wait(100,msec);

  //drive left, start herding items to left
  Drivetrain.turnToHeading(0, deg);
  Drivetrain.driveFor(fwd, 16.5, inches);
  Flapjack1.set(true);
  Drivetrain.turnToHeading(109, deg);
  Drivetrain.setDriveVelocity(70, percent);
  Drivetrain.driveFor(fwd, 11, inches);
  Drivetrain.setDriveVelocity(30,pct);
  bash(10, 1);
  Drivetrain.driveFor(reverse, 11, inches);
}

void skillsMotorGroups() {
    //Catapult tingies towards goal
  Drivetrain.setDriveVelocity(40, pct);
  Drivetrain.setTurnVelocity(3, pct);

  Drivetrain.setHeading(240, deg);
  MotorShooties.spin(fwd, 100, pct);
  wait(1, sec); //catapult for 30 seconds, 3 seconds is just a test value
  MotorShooties.stop(hold);
  
  //turn to bar, drive under bar
  Drivetrain.driveFor(reverse, .5, inches);
  setCatapult(305);
  Drivetrain.turnToHeading(273, deg);
  Drivetrain.setDriveVelocity(25, pct);
  Drivetrain.driveFor(reverse, 38, inches);
  Drivetrain.turnToHeading(0, deg);

  //go out to push in 
  Drivetrain.setDriveVelocity(30, pct);
  Drivetrain.driveFor(fwd, 8, inches);
  Drivetrain.turnToHeading(305, deg);

  // Drivetrain.setDriveVelocity(17, percent); 
  // Drivetrain.driveFor(forward, 7, inches); 
  // Drivetrain.driveFor(reverse, 15, inches);
  Drivetrain.setDriveVelocity(40, percent);
  // Drivetrain.driveFor(reverse, 38.25, inches);

  //turn to goal, score
  Drivetrain.driveFor(fwd,19.375,inches);
  Drivetrain.setTurnVelocity(4, percent);
  Drivetrain.turnToHeading(73, degrees);
  Flapjack1.set(true);
  Intake.spin(fwd,127,pct);
  wait(500,msec);
  Drivetrain.setDriveVelocity(60, percent);
  Drivetrain.driveFor(fwd, 10, inches);
  bash(9, 1);

  // //2nd push in 
  // Drivetrain.driveFor(reverse, 11, inches);
  // Drivetrain.turnToHeading(79, degrees);
  // Drivetrain.setDriveVelocity(40, percent);
  // Drivetrain.driveFor(fwd, 10, inches);
  // bash(9, 1);

  //reverse
  Flapjack1.set(false);
  Intake.stop();
  wait(100,msec);
  Drivetrain.setDriveVelocity(35,pct);
  Drivetrain.driveFor(reverse, 16, inches);
  wait(100,msec);

  //drive left, start herding items to left
  Drivetrain.turnToHeading(0, deg);
  Drivetrain.driveFor(fwd, 16.5, inches);
  Flapjack1.set(true);
  Drivetrain.turnToHeading(109, deg);
  // Drivetrain.setDriveVelocity(70, percent);
  LeftDriveSmart.setVelocity(55, percent);
  RightDriveSmart.setVelocity(70, percent);
  Drivetrain.driveFor(fwd, 11, inches);
  Drivetrain.setDriveVelocity(30,pct);
  bash(10, 1);
  Drivetrain.driveFor(reverse, 11, inches);

}

void testSides() {
  LeftDriveSmart.setVelocity(20, percent);
  RightDriveSmart.setVelocity(70, percent);

  Drivetrain.driveFor(20, inches);
}

//score preload & touch bar 
// void autoOpp() {
//   Drivetrain.setDriveVelocity(48, pct); 
//   Drivetrain.setTurnVelocity(3, pct);

//   //start parallel to match load bar 
//   Drivetrain.setHeading(320, degrees);
//   Drivetrain.turnFor(right, 12, degrees);
//   Drivetrain.driveFor(reverse, 12, inches);
//   wait(500, msec);

//   //touch bar 
//   Drivetrain.setDriveVelocity(20, percent); 
//   Drivetrain.driveFor(forward, 13, inches); 
//   Drivetrain.turnFor(right, 8, degrees);
//   Drivetrain.driveFor(forward, 2, inches);
//   //turning to bar 
//   Drivetrain.driveFor(reverse, 1.5, inches); 
//   Drivetrain.turnFor(right, 90, degrees);
//   //deploy intake 
//   MotorShooties.spin(forward, 60, pct); 
//   wait(0.3, sec); 
//   MotorShooties.stop(hold); 
//   setCatapult(0);

//   Drivetrain.setDriveVelocity(25, percent);
//   Drivetrain.driveFor(reverse, 14, inches); 
// }

void off6Ball() {
  // disableDrivePIDFunc();
  //pre auton config
  Flapjack2.set(false);
  Drivetrain.setDriveVelocity(25, pct);
  Drivetrain.setTurnVelocity(4, pct);
  DrivetrainInertial.setHeading(180, deg);
  Drivetrain.setStopping(hold);

  //drive forward, intake triball under da bar
  Intake.spin(fwd, 127, pct);
  Drivetrain.driveFor(fwd, 1, inches);
  wait(500, msec);

  //drive backwards
  Drivetrain.setDriveVelocity(43, pct);
  Intake.stop();
  Drivetrain.driveFor(reverse, 14, inches);
  // Drivetrain.setDriveVelocity(25, pct);
  // Drivetrain.driveFor(reverse, 4, inches);

  //knock triball out from match load zone and spit out preload toward goal 
  // drivePID(310); // Drivetrain.turnToHeading(310, deg);
  turnTo(310);
  Flapjack2.set(true);
  Drivetrain.setDriveVelocity(30, pct);
  Drivetrain.driveFor(forward, 5, inches);
  Drivetrain.turnFor(left, 30, deg);
  Drivetrain.setDriveVelocity(43, pct);
  Flapjack2.set(false);
  Intake.spin(reverse, 127, pct);
  wait(500, msec);

  //turn around to bash with back 
  Drivetrain.setTurnVelocity(4, pct);
   turnTo(135); //Drivetrain.turnToHeading(135, degrees);

  //curve
  RightDriveSmart.setVelocity(30, pct);
  LeftDriveSmart.setVelocity(60, pct);
  RightDriveSmart.spin(reverse);
  LeftDriveSmart.spin(reverse);
  wait(0.9, sec);
  RightDriveSmart.stop();
  LeftDriveSmart.stop();

  // //BASH BUT BACKWARDS 
  Drivetrain.setDriveVelocity(70, percent); 
  Drivetrain.driveFor(forward, 4, inches);
  wait(250, msec); 
  Drivetrain.setDriveVelocity(77, percent);
  Drivetrain.driveFor(reverse, 5.5, inches);

  Intake.stop();

  //turn to mid triball
  Drivetrain.setDriveVelocity(40, pct);
  Drivetrain.driveFor(3, inches);
  turnTo(198); // Drivetrain.turnToHeading(192, deg);
  Drivetrain.setDriveVelocity(70, pct);

  // //drive to triball in mid 
  Intake.spin(forward, 127, pct);
  Drivetrain.driveFor(19, inches);

  //outtake triball in direction of goal 
  turnTo(335); //Drivetrain.turnToHeading(340, deg);
  Drivetrain.driveFor(3.25, inches); 
  Intake.spin(reverse, 85, pct);
  wait(0.5, sec); 
  Intake.stop();
  wait(0.5, sec);

  //get other triball next to bar 
  // Drivetrain.driveFor(3.25, inches); 
  turnTo(225); 
  Intake.spin(forward, 127, pct); 
  Drivetrain.setDriveVelocity(22, pct); //IUWEF
  Drivetrain.driveFor(9, inches); 

  //turn and push all into goal 
  turnTo(360); 
  Flapjack2.set(true); 
  Intake.spin(reverse, 127, pct);
  wait(0.8, seconds);
  Drivetrain.setDriveVelocity(77, pct);
  Drivetrain.driveFor(13, inches); 

  //back out and blocker 
  Drivetrain.driveFor(reverse, 3, inches); 
  Flapjack2.set(false);
  blockUp();


/*
  //get ball in middle of field 
  turnTo(287); 
  Intake.spin(forward, 127, pct); 
  Drivetrain.driveFor(9, inches); 

  //turn to goal n spit it out 
  turnTo(360); 
  Intake.spin(reverse, 127, pct);
  wait(0.5, sec); 
  Intake.stop(); 

  //get last triball 
  turnTo(190); 
  Intake.spin(forward, 127, pct);
  Drivetrain.driveFor(5, inches);
*/
}

void off4Ball() {
  //352.5 GOLDEN SPOT
  //RED ELEVATION BAR IS THE 0 

  // init 
  Drivetrain.setHeading(270, degrees); 
  Drivetrain.setDriveVelocity(80, pct);

  //flap preload out 
  Flapjack2.set(true); 
  wait(0.25, sec); 
  Flapjack2.set(false); 

  //intake ball in middle of field 
  // Drivetrain.turnToHeading(262, deg);// turnTo(250); 
  Intake.spin(forward, 127, pct); 
  Drivetrain.driveFor(fwd, 22, inches); 
  wait(0.25, sec); 
  Intake.stop(); 

  //spit first triball out 
  Drivetrain.driveFor(reverse, 2, inches);
  turnTo(20); 
  Intake.spin(reverse, 85, pct); 
  wait(0.75, sec); 
  Intake.stop(); 

  //intake triball right under it 
  turnTo(200); //210
  Intake.spin(forward, 127, pct); 
  Drivetrain.driveFor(5, inches); 

  //spit second triball out 
  Drivetrain.driveFor(reverse, 2.5, inches);
  turnTo(15); 
  Intake.spin(reverse, 92, pct); 
  wait(0.35, sec); 
  // Intake.stop(); 

  //PUSH !! 
  Intake.stop(); 
  turnTo(180); 
  // Flapjack2.set(true); 
  Drivetrain.driveFor(reverse, 9, inches); 

 /* //BASH AGAIN !! 
  Drivetrain.driveFor(reverse, 2, inches); 
  wait(0.25, sec); 
  Drivetrain.setDriveVelocity(90, pct); 
  Drivetrain.driveFor(fwd, 2.5, inches); 
*/
  //back up 
  // Intake.stop(); 
  Drivetrain.driveFor(forward, 3, inches);
  // Flapjack2.set(false); 

  //get last triball 
  Drivetrain.setDriveVelocity(77, pct);
  Drivetrain.setTurnVelocity(3, pct);
  Drivetrain.turnToHeading(160, deg); // turnTo(150); //157
  Intake.spin(forward, 127, pct);
  Drivetrain.driveFor(10, inches);
  wait(0.3, sec); 
  Intake.stop();

  //go to knock out load zone triball 
  turnTo(55); 
  Drivetrain.setDriveVelocity(77, pct);
  Drivetrain.driveFor(19.6, inches); 
  Flapjack2.set(true);
  Drivetrain.setHeading(160, deg);
  turnTo(115); 
  Drivetrain.driveFor(fwd, 3, inches);
  Flapjack2.set(false);

  //outtake triball and BASH 
  Intake.spin(reverse, 127, pct); 
  wait(0.3, sec); 
  Intake.stop(); 

  turnTo(215);
  Drivetrain.driveFor(reverse, 10, inches);
  
}

void defWP() {
  //BLUE ELEV BAR IS ZERO 
  //init 
  Drivetrain.setHeading(270, deg); 
  Drivetrain.setDriveVelocity(63, pct);
  Drivetrain.setTurnVelocity(3, pct); 

  //push alliance triball in 
  Drivetrain.turnToHeading(303, deg); // turnTo(320); 
  Drivetrain.driveFor(reverse, 9, inches); 
  Drivetrain.turnToHeading(340, deg); 
  Drivetrain.driveFor(reverse, 5, inches); 

  //SECOND BASH 
  Drivetrain.driveFor(forward, 3, inches); 
  wait(0.25, sec); 
  Drivetrain.driveFor(reverse, 2.5, inches); 


}
