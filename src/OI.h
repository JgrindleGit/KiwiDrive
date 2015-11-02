#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* xbox;
public:
	OI();
	Joystick* getXbox();
};

#endif
