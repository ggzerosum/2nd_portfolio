#pragma once

#include "Include.h"

class CSceneObj
{
public :
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	CSceneObj();
	virtual ~CSceneObj();
};

