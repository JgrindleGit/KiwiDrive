#ifndef FauxShooter_H
#define FauxShooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class FauxShooter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	FauxShooter();
	void InitDefaultCommand();
};

#endif
