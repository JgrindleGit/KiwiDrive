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

	driveB->PIDDrive(strafe, -drive, -(turn*0.5));
	SmartDashboard::GetNumber("DrivePID P Term: ", 1.0);
	SmartDashboard::GetNumber("DrivePID I Term: ", 0.1);
	SmartDashboard::GetNumber("DrivePID D Term: ", 1.0);
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
