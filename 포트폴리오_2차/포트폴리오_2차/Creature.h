#pragma once

#include "Include.h"

class CCreature
{
public :
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	CCreature();
	virtual ~CCreature();
};

