#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Cam.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
DriveBase* CommandBase::driveB = NULL;
Shooter* CommandBase::shoot = NULL;
Cam* CommandBase::cam = NULL;
OI* CommandBase::oi = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	examplesubsystem = new ExampleSubsystem();
	driveB = new DriveBase();
	shoot = new Shooter();
	cam = new Cam();
	oi = new OI();
}
