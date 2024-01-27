using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor MotorShooties;
extern motor Intake;
extern controller Controller1;
extern digital_out Flapjack1;
extern digital_out Flapjack2;
extern digital_out Blockah1;
extern digital_out Blockah2;
extern motor_group LeftDriveSmart; 
extern motor_group RightDriveSmart; 
extern smartdrive Drivetrain;
extern gps DrivetrainGPS;
extern inertial DrivetrainInertial;
extern rotation RotationalSensor;
extern motor LeftTop;
extern motor RightTop;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
