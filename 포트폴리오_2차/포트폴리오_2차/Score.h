#pragma once

#include "SceneObj.h"

class CScore : public CSceneObj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	CScore();
	virtual ~CScore();
};

