#pragma once

#include "Include.h"

class CExitMgr
{
private :
	static CExitMgr* m_pInst;
public :
	static CExitMgr* GetInst()
	{
		if (m_pInst == NULL)
		{
			m_pInst = new CExitMgr;
		}

		return m_pInst;
	}

private :
	bool ExitMgr;
public :
	void Set_ExitMgr(bool _tureORfalse);
	bool Get_ExitMgr();

private :
	CExitMgr();
public:
	~CExitMgr();
};

