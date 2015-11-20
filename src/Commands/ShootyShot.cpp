#include "ShootyShot.h"

ShootyShot::ShootyShot()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shoot);
}

// Called just before this Command runs the first time
void ShootyShot::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShootyShot::Execute()
{
	shoot->MotShoot(oi->getXbox()->GetPOV());
}

// Make this return true when this Command no longer needs to run execute()
bool ShootyShot::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShootyShot::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootyShot::Interrupted()
{

}
