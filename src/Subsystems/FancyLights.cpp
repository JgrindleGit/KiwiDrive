#include "FancyLights.h"
#include "../RobotMap.h"

FancyLights::FancyLights() :
		Subsystem("ExampleSubsystem")
{

	arduino = new I2C(I2C::Port::kOnboard, arduinoPort);
}

void FancyLights::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void FancyLights::SetFrisLights(int speed, int FrameSet){
	switch(speed){
	case 0:
		thing[0]=0;
	case 1:
		thing[0]=1;
	case 2:
		thing[0]=2;
	}
	switch(FrameSet){
	case 1:
		thing[1] = 1;
	case 2:
		thing[1] = 2;
	case 3:
		thing[1] = 3;
	default:
		thing[1] = 0;

	}


	arduino->Transaction(thing, 2, NULL, 0);
}
