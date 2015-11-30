#include "FancyLights.h"
#include "../RobotMap.h"

FancyLights::FancyLights() :
		Subsystem("ExampleSubsystem")
{
	arduino = new I2C(I2C::Port::kOnboard, 4);
}

void FancyLights::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
