#include "vex.h"

//SETTINGS 
double kP = 0.0; 
double kI = 0.0; 
double kD = 0.0; 

double turnKP = 0.07; 
double turnKI = 0.005; 
double turnKD = 0.015;

//autonomous settings 
double desiredValue = 0; //want motor to go 200 degrees 
double desiredTurnValue = 180; 

//lateral pid values 
int error; //desired - current sensor val : positional value 
int prevError = 0; //position 20 msec ago 
int derivative; //error - prevError : speed 
int totalError = 0; //total error = total error + error

//turning pid values 
int turnError; //desired - current sensor val : positional value 
int turnPrevError = 0; //position 20 msec ago 
int turnDerivative; //error - prevError : speed 
int turnTotalError = 0; //total error = total error + error

int integralBound = 3; 

// bool resetDriveSensors = false; 

bool enableDrivePID = true; 

void enableDrivePIDFunc() {
  enableDrivePID = true; 
}

void disableDrivePIDFunc() {
  enableDrivePID = false; 
}

// void enableResetDriveSensors() {
//   resetDriveSensors = true; 
// }

void setDesiredTurn(double newDesiredTurn) {
  desiredTurnValue = newDesiredTurn; 
}

void resetDriveSensors() {
  LeftDriveSmart.setPosition(0, degrees);
  RightDriveSmart.setPosition(0, degrees);
}

void drivePID(/*double newDesiredLat,*/ double newDesiredTurn) { 
  // desiredValue = newDesiredLat; 
  desiredTurnValue = newDesiredTurn; 

  while(Drivetrain.heading() != desiredTurnValue) { //used to be while enableDrivePID

    // if (resetDriveSensors) {
    //   resetDriveSensors = false; 

    //   LeftDriveSmart.setPosition(0, degrees);
    //   RightDriveSmart.setPosition(0, degrees);
    //   // DrivetrainInertial.resetHeading();
    // }

    //side positions 
    int leftMotorPosition = LeftDriveSmart.position(degrees);
    int rightMotorPosition = RightDriveSmart.position(degrees);

    //////////////////////////
    // LATERAL MOVEMENT PID //
    //////////////////////////

    // int averagePosition = (leftMotorPosition + rightMotorPosition) / 2; //gets the average of the two sides 

    // //potential 
    // error = desiredValue - averagePosition; 

    // //derivative 
    // derivative = error - prevError; 

    // //integral
    // totalError += error; 

    // if (abs(error) < integralBound) {
    //   totalError += error;
    // } else {
    //   totalError = 0; 
    // }

    // double lateralMotorPower = (error * kP + derivative * kD + totalError * kI);

    //////////////////////////
    // TURNING MOVEMENT PID //
    //////////////////////////

    //avg of the two motors 
    // int turnDifference = leftMotorPosition - rightMotorPosition; //gets the average of the two sides 
    int turnDifference = desiredTurnValue - DrivetrainInertial.heading(); 

    //potential 
    turnError = desiredTurnValue - DrivetrainInertial.heading(); //turnDifference; 

    //derivative 
    turnDerivative = turnError - turnPrevError; 

    //integral
    turnTotalError += turnError; 

    // if (abs(error) < integralBound) {
    //   turnTotalError += totalError;
    // } else {
    //   turnTotalError = 0; 
    // }

    double turnMotorPower = (turnError * turnKP + turnDerivative * turnKD + turnTotalError * turnKI);

    Controller1.Screen.setCursor(2, 1); 
    Controller1.Screen.print(turnMotorPower);

    LeftDriveSmart.spin(forward, /*lateralMotorPower +*/ turnMotorPower, voltageUnits::volt); 
    RightDriveSmart.spin(forward, /*lateralMotorPower */-turnMotorPower, voltageUnits::volt);

    prevError = error; 
    turnPrevError = turnError; 
    vex::task::sleep(20);

  }

  // return 1; 
}
