#pragma once

#include "Include.h"

class CSceneObj;
class CSceneMgr
{
private :
	static CSceneMgr* m_pInst;
public :
	static CSceneMgr* GetInst()
	{
		if (m_pInst == NULL)
		{
			m_pInst = new CSceneMgr;
		}

		return m_pInst;
	}

private :
	CSceneObj* m_pSceneMgr;
public :
	void SetScene(STATE_SCENE _stageids);
	void Progress();
	void Render();
	void Release();

private:
	CSceneMgr();

public:
	~CSceneMgr();
};

