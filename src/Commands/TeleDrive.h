#ifndef TeleDrive_H
#define TeleDrive_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"

class TeleDrive: public CommandBase
{
public:
	TeleDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
