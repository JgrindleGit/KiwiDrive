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
	turnkp = SmartDashboard::GetNumber("TurnKp",1.0);
	turnki = SmartDashboard::GetNumber("TurnKi",0.1);
	turnkd = SmartDashboard::GetNumber("TurnKd",1.0);
	dzFixer(turn);
	turntim = float(timer->Get());
	if(turn == 0)
	{
		turnx = nav->GetYaw();
		dzFixer(turnx);
		float turnP = (error(turnx)*turnkp);
		turnI += ((error(turnx)/turntim)*turnki);
		float turnD = ((error(turnx)-turnprevError)*turnkd);
		turnoutput = (turnP + turnI + turnD);// First Parentheses = Error, Second set = Derivitive of the first term
		Drive(drive, turnoutput, strafe); //Correction made here
		turntim -= float(timer->Get());
		turnprevError = error(turnx);
	}else{
		Drive(drive,turn,strafe);
	}
}
float DriveBase::error(int var){
	float err;
	err = (0-var);
	return err;
}
void DriveBase::DStop(){
	Drive(0,0,0);
}

