using namespace vex;

extern brain Brain;

// VEXcode devices
extern drivetrain Drivetrain;
extern controller Controller1;
extern motor Intake;
extern motor Catapult1;
extern motor Catapult2;
extern digital_out IntakePiston1;
extern digital_out IntakePiston2;
extern digital_out FlapjackPiston1;
extern digital_out flapjackPiston2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );