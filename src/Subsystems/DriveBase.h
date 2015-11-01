#ifndef DriveBase_H
#define DriveBase_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveBase: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities]
	Gyro* g1;

	Victor* c1;
	Victor* c2;
	Victor* c3;

	Timer* timer;

	float kp;
	float ki;
	float kd;
	float output;
	float x;
	float deadzone;
	float tx;
	float I;
	float tim = 0;

public:
	DriveBase();
	void InitDefaultCommand();
	virtual void Drive(float, float, float);
	virtual void PIDDrive(float, float, float, float, float);
	virtual void dzFixer(float);
	float des = 0;
	float error();
};

#endif
