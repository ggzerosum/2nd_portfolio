#pragma once

#include "Creature.h"

class CPlayer : public CCreature
{
private :
	INFO m_PlayerInfo;

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

private:
	DWORD dwKeyCheck;

public:
	CPlayer();
	virtual ~CPlayer();
};

