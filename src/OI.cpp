#include "OI.h"
#include "Commands/MoveCam.h"

OI::OI()
{
	// Process operator interface input here.
	xbox = new Joystick(0);
	frisShot = new JoystickButton(xbox, 6);
	frisShot->WhileHeld(new MoveCam());


	SmartDashboard::PutData("Actuate Cam", new MoveCam());
}
Joystick* OI::getXbox(){
	return (xbox);
}
