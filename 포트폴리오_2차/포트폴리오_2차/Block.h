#pragma once

#include "Things.h"

class CBlock : public CThings
{
private :
	BLOCK m_sBlockInfo;
	BLOCK_LIST m_BlockList[Block_Max];

	BLOCK m_MovableBlock;

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

