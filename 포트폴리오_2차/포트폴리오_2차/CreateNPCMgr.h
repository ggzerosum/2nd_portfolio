#pragma once

#include "Include.h"

#include "Npc01.h"

class CCreature;
class CCreateNPCMgr
{
private :
	static CCreateNPCMgr* m_pInst;
public :
	static CCreateNPCMgr* GetInst()
	{
		if (m_pInst == NULL)
		{
			m_pInst = new CCreateNPCMgr;
		}

		return m_pInst;
	}

public :
	CCreature* MakeNPC01()
	{
		CCreature* pNPC01 = new CNpc01;
		return pNPC01;
	}

public:
	CCreateNPCMgr();
	~CCreateNPCMgr();
};

