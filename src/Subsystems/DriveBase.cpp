#include "DriveBase.h"
#include "../RobotMap.h"
#include "Commands/TeleDrive.h"

DriveBase::DriveBase() :
		Subsystem("DriveBase")
{
	deadzone = 0.03;
	try {
		nav = new AHRS(SPI::Port::kMXP);
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
void DriveBase::Drive(float joy_X/**Strafe*/, float joy_Y/**Drive*/, float joy_Z/**Turn*/){
	float Con1 = ((joy_X + joy_Z));
	float Con2 = (((-((joy_X)/2))+((sqrt(3)/2)*(joy_Y)) + joy_Z));
	float Con3 = (((-((joy_X)/2))-((sqrt(3)/2)*(joy_Y)) + joy_Z));

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
float DriveBase::dzFixer(float z){
	if((z >-(deadzone)) && (z < (deadzone))){
		z = 0;
	}
	return z;
}

void DriveBase::PIDDrive(float drive, float turn, float strafe,float turnkp,float turnki,float turnkd)
{
	/**
	float dzTurn = dzFixer(turn);
	//float dzDrive = dzFixer(drive);
	//float dzStrafe = dzFixer(strafe);
	turntim = float(timer->Get());
	float turnHeading = nav->GetYaw();
	if(dzTurn == 0)
	{
		turnx = nav->GetYaw();
		dzFixer(turnx);
		turnP = (error(turnHeading, turnx)*turnkp);
		turnI += ((error(turnHeading, turnx)/turntim)*turnki);
		turnD = ((error(turnHeading, turnx)-turnprevError)*turnkd);
		turnoutput = (turnP + turnI + turnD);// First Parentheses = Error, Second set = Derivitive of the first term
		Drive(drive, strafe, turnoutput); //Correction made here
		turntim -= float(timer->Get());
		turnprevError = error(turnHeading, turnx);
	}else {
		Drive(strafe, drive, turn);
	}**/
}
float DriveBase::error(float initial, float var){
	float err;
	err = (initial-var);
	return err;
}
void DriveBase::DStop(){
	Drive(0,0,0);
}
void DriveBase::VelPID(bool strafe){
	/**velkp = SmartDashboard::GetNumber("VelKp",1.0);
	velki = SmartDashboard::GetNumber("VelKi",0.1);
	velkd = SmartDashboard::GetNumber("VelKd",1.0);
	if(strafe == true){
		velx = nav->GetVelocityY();
	}**/
}
