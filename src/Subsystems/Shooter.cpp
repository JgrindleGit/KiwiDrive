#include "Shooter.h"
#include "../RobotMap.h"
#include "Commands/ShootyShot.h"

Shooter::Shooter() :
		Subsystem("ExampleSubsystem")
{
	wh1 = new Victor(4);
	wh2 = new Victor(3);

}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ShootyShot());
}
void Shooter::Speedup(int dir){
	switch(dir){
	case 0:
		//do something
		if (change == false){
			if (sped < 2){
				sped = sped + 1;
				printf("Speed up \n");
				change = true;
			}
		}
		break;
	case 180:
		//do some other thing
		if(change == false){
			if(sped > 0){
				sped = sped - 1;
				printf("Speed Down \n");
				change = true;
			}
		}

		break;
	default:
		printf("Nothing\n");
		change = false;
		break;
	}
	printf("%d", sped);
	printf("\n");

}
void Shooter::Motset(float power){
	wh1->Set(power);
	wh2->Set(power);
}
void Shooter::MotShoot(int POV){
	Speedup(POV);
	Motset(speeds[sped]);

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
