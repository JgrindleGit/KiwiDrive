#include "Elevator.h"
#include "../RobotMap.h"

Elevator::Elevator() :
		Subsystem("ExampleSubsystem")
{
	eleL = new Victor(LIFTLEFT);
	eleR = new Victor(LIFTRIGHT);

}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Elevator::Lift(float joy){
	float sideL = -(joy);
	float sideR = (joy);
	eleL->Set(sideL);
	eleR->Set(sideR);
}
void Elevator::Stop()
{
	eleL->Set(0);
	eleR->Set(0);
}
void Elevator::LiftS(float joy){
	Lift(joy);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
