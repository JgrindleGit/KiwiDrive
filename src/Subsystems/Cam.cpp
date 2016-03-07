#include "Cam.h"
#include "../RobotMap.h"

Cam::Cam() :
		Subsystem("Cam")
{
	cam = new Victor(5);
	camstop = new DigitalInput(0);
}

void Cam::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void Cam::spin(float spin){
	cam->Set(spin);
}
void Cam::CamSet(){


}

// Put methods for controlling this subsystem
// here. Call these from Commands.
