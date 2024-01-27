#include "vex.h"

vex::timer myTimer; 

double kP = 0.11; 
double kI = 0.000; 
double kD = 0.00; 

double desiredAngle = 0.0; 

double integralSum = 0.0; 

double lastError = 0.0; 
double error = 0.0; 


void turnTo(double newDesiredAngle) {
  myTimer.reset();
  desiredAngle = newDesiredAngle; 

  while(!(Drivetrain.heading() > desiredAngle - 2 && Drivetrain.heading() < desiredAngle + 2)) {
    double pos = Drivetrain.heading(); 

    //calculate error 
    error = desiredAngle - pos; 

    //rate of change of the error 
    double derivative = (error - lastError) / myTimer.time(seconds);

    double integralSum = integralSum + (error * myTimer.time(seconds));

    double output = (kP * error) + (kI * integralSum) + (kD * derivative);

    LeftDriveSmart.spin(forward, output, voltageUnits::volt); 
    RightDriveSmart.spin(reverse, output, voltageUnits::volt);

    lastError = error; 
  }
  Drivetrain.stop();
}
