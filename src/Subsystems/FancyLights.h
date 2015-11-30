#ifndef FancyLights_H
#define FancyLights_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class FancyLights: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	I2C* arduino;
public:
	FancyLights();
	void InitDefaultCommand();
};

#endif
