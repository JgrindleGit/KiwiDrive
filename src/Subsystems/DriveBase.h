#ifndef DriveBase_H
#define DriveBase_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "AHRS.h"
class DriveBase: public Subsystem
{
private:
	//GYRO NAVX MXP
	AHRS* nav;

	//DRIVEBASE WHEELS
	Victor* c1;
	Victor* c2;
	Victor* c3;

	//PID LOOP STUFF
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
	float prevError = 0;

public:
	DriveBase();
	void InitDefaultCommand();
	virtual void Drive(float, float, float);
	virtual void PIDDrive(float, float, float, float, float, float);
	virtual void dzFixer(float);
	virtual void TimerStart();
	virtual void TimerStop();
	virtual void DStop();
	float des = 0;
	float error();
};

#endif
