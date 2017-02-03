#pragma once

#include "SceneObj.h"

class CMyMenu : public CSceneObj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	CMyMenu();
	virtual ~CMyMenu();
};

