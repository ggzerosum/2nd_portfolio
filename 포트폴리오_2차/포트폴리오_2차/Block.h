#pragma once

#include "Things.h"

class CBlock : public CThings
{
private :
	BLOCK m_sBlockInfo;

public :
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public :
	void Input_BlockList();

public:
	CBlock();
	virtual ~CBlock();
};

