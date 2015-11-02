#ifndef Elevator_H
#define Elevator_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Elevator: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor* eleL;
	Victor* eleR;
	Encoder* LRight;
	Encoder* LLeft;
	float topBound;
	float botBound;
	float leftPOS;
	float rightPOS;
public:
	Elevator();
	void InitDefaultCommand();
	virtual void Lift(float);
	virtual void Stop();
	virtual void LiftS(float);
	virtual void Matchsped(float);
	virtual void SetBounds(float, float);
};

#endif
