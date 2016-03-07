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
	SmartDashboard::PutNumber("DrivePID P Term: ", 0.8);
	SmartDashboard::PutNumber("DrivePID I Term: ", 0.1);
	SmartDashboard::PutNumber("DrivePID D Term: ", 1.0);

	driveB->TimerStart();
}

// Called repeatedly when this Command is scheduled to run
void TeleDrive::Execute()
{
	float drive = -(oi->getXbox()->GetRawAxis(LY))*(SmartDashboard::GetNumber("Drive: ", 0.8));
	float turn = (oi->getXbox()->GetRawAxis(RX))*(SmartDashboard::GetNumber("Turn: ", 0.8));
	float strafe = (oi->getXbox()->GetRawAxis(LX))*(SmartDashboard::GetNumber("Strafe: ", 0.8));


	float p = SmartDashboard::GetNumber("DrivePID P Term: ");
	float i = SmartDashboard::GetNumber("DrivePID I Term: ");
	float d = SmartDashboard::GetNumber("DrivePID D Term: ");

	driveB->PIDDrive(strafe, -drive, -(turn)*0.5,p,i,d);
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
