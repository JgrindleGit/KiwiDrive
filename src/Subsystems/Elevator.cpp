#include "Elevator.h"
#include "../RobotMap.h"

Elevator::Elevator() :
		Subsystem("Elevator")
{
	eleL = new Victor(LIFTLEFT);
	eleR = new Victor(LIFTRIGHT);

	LRight = new Encoder(1,2);
	LLeft = new Encoder(3,4,true);
	leftPOS = float(LLeft->GetDistance());
	rightPOS = float(LRight->GetDistance());

}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Elevator::Lift(float joy){
	float sideL = -(joy);
	float sideR = (joy);
	eleL->Set(sideL);
	eleR->Set(sideR);
}
void Elevator::Stop()
{
	eleL->Set(0);
	eleR->Set(0);
}
void Elevator::LiftS(float joy){
	float avgPOS = ((leftPOS+rightPOS)/2);
	if(avgPOS <= topBound) {
	    if(joy < 0) {
	    	Matchsped(joy);
	    } else {
	    	Matchsped(0);
	   	}
	} else if(avgPOS >= botBound) {
		if(joy > 0) {
	    	Matchsped(joy);
	    } else {
	    	Matchsped(0);
	    }
	} else {
	    Matchsped(joy);
	}
}
void Elevator::SetBounds(float TopMbound, float bottomBound){
	topBound = TopMbound;
	botBound = bottomBound;
}
void Elevator::Matchsped(float joy){
	if (joy> 0){
		if(leftPOS>rightPOS){
			eleR->Set(joy+0.05);
		}else if(rightPOS<leftPOS){
			eleL->Set(joy+0.05);
		}
	}else if(joy<0){
		if(leftPOS>rightPOS){
			eleR->Set(joy-(0.05));
		}else if(rightPOS<leftPOS){
			eleL->Set(joy-(0.05));
		}
	}else{
		eleR->Set(joy);
		eleL->Set(joy);
	}
}

