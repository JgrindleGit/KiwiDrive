#ifndef ShootyShot_H
#define ShootyShot_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShootyShot: public CommandBase
{
public:
	ShootyShot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
