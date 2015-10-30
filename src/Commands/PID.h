#ifndef PID_H
#define PID_H

#include "../CommandBase.h"
#include "WPILib.h"

class PID: public CommandBase
{
public:
	PID();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
