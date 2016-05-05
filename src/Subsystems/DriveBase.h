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
	float deadzone;
	/**
	Timer* timer;
	float turnkp;
	float turnki;
	float turnkd;
	float turnoutput;
	float turnx;
	float turntx;
	float turnP;
	float turnI;
	float turnD;
	float turntim = 0;
	float turnprevError = 0;**/

	/**float velkp;
	float velki;
	float velkd;
	float veloutput;
	float velx;
	float veltx;
	float velI;
	float veltim = 0;
	float velprevError = 0;**/

public:
	DriveBase();
	void InitDefaultCommand();
	virtual void Drive(float, float, float);
	virtual void PIDDrive(float, float, float,float,float,float);
	virtual void VelPID(bool);
	float dzFixer(float);
	virtual void TimerStart();
	virtual void TimerStop();
	virtual void DStop();
	float des = 0;
	float error(float, float);
};

#endif
