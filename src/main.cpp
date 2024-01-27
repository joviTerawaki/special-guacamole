/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// MotorShooties        motor         7               
// Intake               motor         8               
// Controller1          controller                    
// Flapjack1            digital_out   A               
// Flapjack2            digital_out   B               
// Drivetrain           drivetrain    1, 2, 9, 10, 21 
// LeftTop              motor         15              
// RightTop             motor         16              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
// #include "DriverControl.h"
#include "Auto.h"
// #include "AnotherPID.h"
// #include "pid.h"
// #include "robot-con fig.cpp"
// #include "robot-config.cpp"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void printingThread() {
  while(true){
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print(Drivetrain.heading());
  }
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Flapjack2.set(false);
  Drivetrain.setDriveVelocity(25, pct);
  Drivetrain.setTurnVelocity(4, pct);
  // DrivetrainInertial.setHeading(180, deg);
  Drivetrain.setStopping(hold);
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/* * * PID * * */

// //SETTINGS 
// double kP = 0.0; 
// double kI = 0.0; 
// double kD = 0.0; 

// double turnKP = 0.07; 
// double turnKI = 0.005; 
// double turnKD = 0.015;

// //autonomous settings 
// int desiredValue = 0; //want motor to go 200 degrees 
// int desiredTurnValue = 0; 

// //lateral pid values 
// int error; //desired - current sensor val : positional value 
// int prevError = 0; //position 20 msec ago 
// int derivative; //error - prevError : speed 
// int totalError = 0; //total error = total error + error

// //turning pid values 
// int turnError; //desired - current sensor val : positional value 
// int turnPrevError = 0; //position 20 msec ago 
// int turnDerivative; //error - prevError : speed 
// int turnTotalError = 0; //total error = total error + error

// int integralBound = 3; 

// bool resetDriveSensors = false; 

// bool enableDrivePID = true; 

// int drivePID() { 

//   while(enableDrivePID) {

//     if (resetDriveSensors) {
//       resetDriveSensors = false; 

//       LeftDriveSmart.setPosition(0, degrees);
//       RightDriveSmart.setPosition(0, degrees);
//       DrivetrainInertial.resetHeading();
//     }

//     //side positions 
//     int leftMotorPosition = LeftDriveSmart.position(degrees);
//     int rightMotorPosition = RightDriveSmart.position(degrees);

//     //////////////////////////
//     // LATERAL MOVEMENT PID //
//     //////////////////////////

//     int averagePosition = (leftMotorPosition + rightMotorPosition) / 2; //gets the average of the two sides 

//     //potential 
//     error = desiredValue - averagePosition; 

//     //derivative 
//     derivative = error - prevError; 

//     //integral
//     totalError += error; 

//     if (abs(error) < integralBound) {
//       totalError += error;
//     } else {
//       totalError = 0; 
//     }

//     double lateralMotorPower = (error * kP + derivative * kD + totalError * kI);

//     //////////////////////////
//     // TURNING MOVEMENT PID //
//     //////////////////////////

//     //avg of the two motors 
//     // int turnDifference = leftMotorPosition - rightMotorPosition; //gets the average of the two sides 
//     int turnDifference = desiredTurnValue - DrivetrainInertial.heading(); 

//     //potential 
//     turnError = desiredTurnValue - DrivetrainInertial.heading(); //turnDifference; 

//     //derivative 
//     turnDerivative = turnError - turnPrevError; 

//     //integral
//     turnTotalError += turnError; 

//     // if (abs(error) < integralBound) {
//     //   turnTotalError += totalError;
//     // } else {
//     //   turnTotalError = 0; 
//     // }

//     double turnMotorPower = (turnError * turnKP + turnDerivative * turnKD + turnTotalError * turnKI);

//     Controller1.Screen.setCursor(2, 1); 
//     Controller1.Screen.print(turnMotorPower);

//     LeftDriveSmart.spin(forward, lateralMotorPower + turnMotorPower, voltageUnits::volt); 
//     RightDriveSmart.spin(forward, lateralMotorPower - turnMotorPower, voltageUnits::volt);

//     prevError = error; 
//     turnPrevError = turnError; 
//     vex::task::sleep(20);

//   }

//   return 1; 
// }

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

// int drivePIDFunc() {
//   return drivePID();
// }

void autonomous(void) {
  thread newThread = thread(printingThread);

  // DrivetrainInertial.calibrate();
  // wait(200, msec);

  //TESTING PID 
  // vex::task pidTask(drivePIDFunc); //task var??

  // resetDriveSensors();
  // enableResetDriveSensors();
  // setDesiredTurn(90);
  // disableDrivePIDFunc();

  // vex::task::sleep(100);
  // Drivetrain.setHeading(0, degrees);

  // turnTo(245);
  // Drivetrain.setHeading(0, degrees);
  // Drivetrain.setTurnVelocity(5, pct);
  // Drivetrain.turnToHeading(245, degrees); // turnTo(315); 

  off6Ball(); //6 ball auto 
  // off4Ball();
  // defWP(); 
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  //PID 
  // enableDrivePID = false; 

  thread newThread = thread(printingThread);
  // User control code here, inside the loop
  while (1) {
    /* * * DRIVE * * */
    // tank(); 
    // topMotors();
    Drivetrain.setStopping(coast);
    
    /* * * FLAPJACK * * */
    if (Controller1.ButtonY.pressing()) {
      Flapjack1.set(true);
      Flapjack2.set(true);
    } else if (Controller1.ButtonX.pressing()) {
      Flapjack1.set(false);
      Flapjack2.set(false);
    } 

    /* * * CATAPULT * * */
    // MotorShooties.setBrake(coast);
    // Controller1.Screen.setCursor(3, 3);
    // Controller1.Screen.print("%d", RotationalSensor.position(degrees));
    if (Controller1.ButtonR1.pressing()) {
      MotorShooties.spin(fwd, 100, pct);
    } else if (Controller1.ButtonR2.pressing()) {
      MotorShooties.spin(fwd, 20, pct);
    } else {
      setCatapult(290);
      // MotorShooties.stop(coast);
    }

    /* * * INTAKE * * */ 
    if (Controller1.ButtonL1.pressing()) {
      Intake.spin(forward, 100, pct); 
    } else if (Controller1.ButtonL2.pressing()) {
      Intake.spin(reverse, 100, pct);
    } else {
      Intake.stop();
    }

    /* * * BLOCKER * * */
    if (Controller1.ButtonB.pressing()) {
      blockUp(); 
      setCatapult(300); 
    }
    // Controller1.ButtonB.pressed(blockUp);
    Controller1.ButtonA.pressed(blockDown);

    /* * * SET CATAPULT TO DOWN POSITION * * */
    if (Controller1.ButtonLeft.pressing()) {
      setCatapult(300);
    }

    // Controller1.ButtonDown.pressed(testSides);

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
