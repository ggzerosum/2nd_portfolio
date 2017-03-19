#pragma once

//test
#include "Block.h"
//end

class CTest_MainGame
{
private :
	CBlock test_block;

public:
	void Initialize();
	void Progress();
	void Render();
	void Release();

public:
	CTest_MainGame();
	~CTest_MainGame();
};

