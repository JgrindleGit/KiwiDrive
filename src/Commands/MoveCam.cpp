#include "MoveCam.h"

MoveCam::MoveCam()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(camM);
}

// Called just before this Command runs the first time
void MoveCam::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void MoveCam::Execute()
{
	camM->spin(1);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveCam::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveCam::End()
{
	camM->spin(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveCam::Interrupted()
{
	End();
}
