#pragma once

#include "Include.h"

class CThings
{
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	CThings();
	virtual ~CThings();
};

