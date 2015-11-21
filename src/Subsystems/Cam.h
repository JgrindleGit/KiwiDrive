#ifndef Cam_H
#define Cam_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Cam: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DigitalInput* camstop;
	Victor* cam;
public:
	Cam();
	void InitDefaultCommand();
	virtual void spin();
	virtual void CamSet();
};

#endif
