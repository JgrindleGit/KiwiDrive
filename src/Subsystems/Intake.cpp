#include "Intake.h"
#include "../RobotMap.h"

Intake::Intake() :
		Subsystem("Intake")
{
	rIn = new Relay(0);
	lIn = new Relay(1);
	grip = new DoubleSolenoid(0,1);
}

void Intake::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void Intake::pin(){
	grip->Set(DoubleSolenoid::kForward);
}
void Intake::pout(){
	grip->Set(DoubleSolenoid::kReverse);
}
void Intake::rin(){
	rIn->Set(Relay::kForward);
	lIn->Set(Relay::kReverse);
}
void Intake::rout(){
	lIn->Set(Relay::kForward);
	rIn->Set(Relay::kReverse);
}
void Intake::rstop(){
	lIn->Set(Relay::kOff);
	rIn->Set(Relay::kOff);
}
