/*
 * PID.h
 *
 *  Created on: Mar 8, 2016
 *      Author: John
 */

#ifndef SRC_PID_H_
#define SRC_PID_H_

#include "WPILib.h"

class PID
{
public:
	PID();
	PID(float kp, float ki, float kd);
	virtual float pid(float des, float cur);
	virtual void setKs(float kp, float ki, float kd);
	virtual float error(float initial, float var);
	virtual float dzFix(float z, float deadzone);

private:
	Timer* timer;
	float integral;
	float tim;
	float prevErr = 0;
	float kP;
	float kI;
	float kD;
};


#endif /* SRC_PID_H_ */
