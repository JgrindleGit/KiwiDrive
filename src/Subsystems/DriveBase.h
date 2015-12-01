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
	float turnkp;
	float turnki;
	float turnkd;
	float turnoutput;
	float turnx;
	float turndeadzone;
	float turntx;
	float turnI;
	float turntim = 0;
	float turnprevError = 0;

	float velkp;
	float velki;
	float velkd;
	float veloutput;
	float velx;
	float veldeadzone;
	float veltx;
	float velI;
	float veltim = 0;
	float velprevError = 0;

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
