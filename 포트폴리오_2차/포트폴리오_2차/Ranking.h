#pragma once

#include "SceneObj.h"

class CRanking : public CSceneObj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	CRanking();
	virtual ~CRanking();
};

