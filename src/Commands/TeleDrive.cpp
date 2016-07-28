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
	SmartDashboard::PutNumber("Drive: ", 0.8);
	SmartDashboard::PutNumber("Turn: ", 0.8);
	SmartDashboard::PutNumber("Strafe: ", 0.8);

	driveB->TimerStart();
}

// Called repeatedly when this Command is scheduled to run
void TeleDrive::Execute()
{
	float dM = SmartDashboard::GetNumber("Drive: ", 0.8);
	float tM = SmartDashboard::GetNumber("Turn: ", 0.8);
	float sM = SmartDashboard::GetNumber("Strafe: ", 0.8);
	float drive = -(oi->getXbox()->GetRawAxis(LY))*(dM);
	float turn = (oi->getXbox()->GetRawAxis(RX))*(tM);
	float strafe = (oi->getXbox()->GetRawAxis(LX))*(sM);


	//float p = SmartDashboard::GetNumber("DrivePID P Term: ", 0.5);
	//float i = SmartDashboard::GetNumber("DrivePID I Term: ", 0.1);
	//float d = SmartDashboard::GetNumber("DrivePID D Term: ", 1.0);

	driveB->Drive(strafe, -drive, -(turn)*0.5);
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
