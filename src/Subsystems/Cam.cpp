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
void Cam::spin(){
	if(camstop->Get()){
		cam->Set(1);
	}else{
		cam->Set(0);
	}
}
void Cam::CamSet(){
	if(camstop->Get() == false){
		cam->Set(1);
	}
	cam->Set(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
