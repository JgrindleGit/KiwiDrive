#include "OI.h"

OI::OI()
{
	// Process operator interface input here.
	xbox = new Joystick(0);
}
Joystick* OI::getXbox(){
	return (xbox);
}
