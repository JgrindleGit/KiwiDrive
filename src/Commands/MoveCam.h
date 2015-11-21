#ifndef MoveCam_H
#define MoveCam_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveCam: public CommandBase
{
public:
	MoveCam();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
