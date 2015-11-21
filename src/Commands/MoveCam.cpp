#include "MoveCam.h"

MoveCam::MoveCam()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(cam);
}

// Called just before this Command runs the first time
void MoveCam::Initialize()
{
	cam->CamSet();
}

// Called repeatedly when this Command is scheduled to run
void MoveCam::Execute()
{
	cam->spin();
}

// Make this return true when this Command no longer needs to run execute()
bool MoveCam::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveCam::End()
{
	cam->CamSet();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveCam::Interrupted()
{
	End();
}
