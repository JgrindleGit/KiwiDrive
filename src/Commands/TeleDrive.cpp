#include "TeleDrive.h"

TeleDrive::TeleDrive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveB);
}

// Called just before this Command runs the first time
void TeleDrive::Initialize()
{
	driveB->TimerStart();
}

// Called repeatedly when this Command is scheduled to run
void TeleDrive::Execute()
{
	float drive = (oi->getXbox()->GetRawAxis(LY));
	float turn = (oi->getXbox()->GetRawAxis(RX));
	float strafe = (oi->getXbox()->GetRawAxis(LX));
	driveB->PIDDrive(drive, turn, strafe);
}

// Make this return true when this Command no longer needs to run execute()
bool TeleDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TeleDrive::End()
{
	driveB->DStop();
	driveB->TimerStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleDrive::Interrupted()
{
	End();
}
