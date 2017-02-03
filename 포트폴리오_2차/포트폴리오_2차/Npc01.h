#pragma once

#include "Creature.h"

class CNpc01 : public CCreature
{
private :
	HUMAN tag_info;

public :
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public :
	HUMAN* GetNPCInfo();

public:
	CNpc01();
	virtual ~CNpc01();
};