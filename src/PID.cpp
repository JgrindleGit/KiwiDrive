/*
 * PID.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: John
 */
#include "../../KiwiDrive/src/PID.h"

#include "WPILib.h"
PID::PID()
{
	kP = 0.75;
	kI = 0.8;
	kD = 1.0;
}
PID::PID(float kp, float ki, float kd)
{
	kP = kp;
	kI = ki;
	kD = kd;
	timer = new Timer();
}
void PID::setKs(float kp, float ki, float kd)
{
	kP = kp;
	kI = ki;
	kD = kd;
}
float PID::pid(float des, float cur)
{
	float err = error(des, cur);
	float prop = err * kP;
	integral = (err/tim)*kI;
	float derivative = (err - prevErr)*kD;
	float out = (prop + integral + derivative);
	prevErr = err;
	return out;
	tim -= float(timer->Get());
}
float PID::error(float initial, float var)
{
	float err;
	err = (initial-var);
	return err;
}
float PID::dzFix(float z, float deadzone)
{
	if((z >-(deadzone)) && (z < (deadzone))){
			z = 0;
		}
	return z;
}
void PID::TimerStart(){
	timer->Start();
}
void PID::TimerStop(){
	timer->Stop();
}
