#pragma once

#include "Creature.h"

class CThings;
class CPlayer : public CCreature
{
private :
	INFO m_PlayerInfo;
	CThings* m_pBlock[total_block_information];

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

private:
	DWORD dwKeyCheck;
public :
	void CheckKey();
public:
	CPlayer();
	virtual ~CPlayer();
};

