#include "DriveBase.h"
#include "../RobotMap.h"
#include "Commands/TeleDrive.h"

DriveBase::DriveBase() :
		Subsystem("DriveBase")
{
	deadzone = 0.03;
	try {
		nav = new AHRS(I2C::Port::kMXP);
	} catch (std::exception ex ) {
		std::string err_string = "Error instantiating navX MXP:  ";
        err_string += ex.what();
        DriverStation::ReportError(err_string.c_str());
	}
	c1 = new Victor(CON1);
	c2 = new Victor(CON2);
	c3 = new Victor(CON3);

	timer = new Timer();
}

void DriveBase::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TeleDrive());
}
void DriveBase::Drive(float joy_X, float joy_Y, float joy_Z){
	float Con1 = (0.5*(joy_X + joy_Z));
	float Con2 = (0.5*((-((joy_X)/2))+((sqrt(3)/2)*(joy_Y)) + joy_Z));
	float Con3 = (0.5*((-((joy_X)/2))-((sqrt(3)/2)*(joy_Y)) + joy_Z));

	c1->Set(Con1);
	c2->Set(Con2);
	c3->Set(Con3);
}
void DriveBase::TimerStart(){
	timer->Start();
}
void DriveBase::TimerStop(){
	timer->Stop();
}
//Used to fix deadzones on Joysticks, Gyros, or anything else
void DriveBase::dzFixer(float z){
	if((z >-(deadzone)) && (z < (deadzone))){
		z = 0;
	}
}

void DriveBase::PIDDrive(float drive, float turn, float strafe, float kpp, float kip, float kid)
{
	kp = kpp;
	ki = kip;
	kd = kid;
	dzFixer(turn);
	tim = float(timer->Get());
	if(turn == 0)
	{
		x = nav->GetYaw();
		dzFixer(x);
		float P = (error()*kp);
		I += ((error()/tim)*ki);
		float D = ((error()-prevError)*kd);
		output = (P + I + D);// First Parentheses = Error, Second set = Derivitive of the first term
		Drive(drive, output, strafe); //Correction made here
		tim -= float(timer->Get());
		prevError = error();
	}else{
		Drive(drive,turn,strafe);
	}
}
float DriveBase::error(){
	float err;
	err = (0-x);
	return err;
}
void DriveBase::DStop(){
	Drive(0,0,0);
}

