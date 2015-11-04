#ifndef Intake_H
#define Intake_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Intake: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DoubleSolenoid* grip;
	Relay* rIn;
	Relay* lIn;
public:
	Intake();
	void InitDefaultCommand();
	virtual void pin();
	virtual void pout();
	virtual void rin();
	virtual void rout();
	virtual void rstop();


};

#endif
