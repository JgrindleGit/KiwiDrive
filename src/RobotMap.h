#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;
const int GYRO1 = 0;

const int CON1 = 0;
const int CON2 = 1;
const int CON3 = 2;

/**const int LIFTRIGHT = 3;
const int LIFTLEFT = 4;

const int INTAKELSPIKE = 0;
const int INTAKERSPIKE = 1;

const int INTAKELPNE = 0;
const int INTAKERPNE = 1;**/

//!!!!Joystick!!!!
const int LX = 0;
const int LY = 1;
const int RX = 4;
const int RY = 5;
#endif
