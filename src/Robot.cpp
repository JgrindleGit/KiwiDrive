#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
public:
	bool isAuto;
private:
	Command *autonomousCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		//CameraServer::GetInstance()->SetQuality(50);
		//the camera name (ex "cam0") can be found through the roborio web interface
		//CameraServer::GetInstance()->StartAutomaticCapture("cam0");
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

