#pragma once

#include "Include.h"

class CCheckKeyMgr
{
private :
	static CCheckKeyMgr* m_pInst;
public :
	static CCheckKeyMgr* GetInst()
	{
		if (m_pInst == NULL)
		{
			m_pInst = new CCheckKeyMgr;
		}

		return m_pInst;
	}

private :
	DWORD m_dwCheckKey;
public :
	void KeyCheck();
	DWORD GetKey()
	{
		return m_dwCheckKey;
	}

private :
	CCheckKeyMgr();
public:
	~CCheckKeyMgr();
};

