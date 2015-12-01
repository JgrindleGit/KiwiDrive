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
	uint8_t thing[];
	uint8_t arduinoPort;
	bool change;
	int lightSet;
public:
	FancyLights();
	void InitDefaultCommand();
	void SetFrisLights(int, int);
	void SetBase(int);
};

#endif
