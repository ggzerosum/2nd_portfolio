#pragma once

#include "SceneObj.h"

class CCreature;
class CMyStage_01 : public CSceneObj
{
private :
	CCreature* m_pPlayer;

public :
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	CMyStage_01();
	virtual ~CMyStage_01();
};

