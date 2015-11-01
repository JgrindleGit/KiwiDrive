#include "DriveBase.h"
#include "../RobotMap.h"

DriveBase::DriveBase() :
		Subsystem("DriveBase")
{
	deadzone = 0.3;
	g1 = new Gyro(GYRO1);

	c1 = new Victor(CON1);
	c2 = new Victor(CON3);
	c3 = new Victor(CON3);

	timer = new Timer();
	timer->Start();
}

void DriveBase::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void DriveBase::Drive(float joy_X, float joy_Y, float joy_Z){
	float Con1 = (joy_X + joy_Z);
	float Con2 = ((-((joy_X)/2))+((sqrt(3)/2)*(joy_Y)) + joy_Z);
	float Con3 = ((-((joy_X)/2))-((sqrt(3)/2)*(joy_Y)) + joy_Z);

	c1->Set(Con1);
	c2->Set(Con2);
	c3->Set(Con3);
}

//Used to fix deadzones on Joysticks, Gyros, or anything else
void DriveBase::dzFixer(float z){
	if((z >-(deadzone)) && (z < (deadzone))){
		z = 0;
	}
}

void DriveBase::PIDDrive(float drive, float turn, float strafe, float kp, float kd)
{

	x = g1->GetAngle();
	dzFixer(x);
	dzFixer(turn);
	I += (error()/tim);
	tim = float(timer->Get());
	if(turn == 0 && (strafe > deadzone|| strafe < deadzone))
	{
		output = (error()* kp) + ((x+kp)*kd) + (I*ki);// First Parentheses = Error, Second set = Derivitive of the first term
	}
	Drive(drive, output, strafe); //Correction made here
	tim -= float(timer->Get());
}
float DriveBase::error(){
	float err;
	err = (0-x);
	return err;
}
