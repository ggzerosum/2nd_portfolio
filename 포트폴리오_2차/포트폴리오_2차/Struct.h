#pragma once

typedef struct __HUMAN
{
	char* cName;
	int iAge;

	int iHp;
	int iMp;

	int iGender;

	__HUMAN() {};
	__HUMAN(char* _cName, int _iAge, int _iHp, int _iMp, int _iGender) : cName(_cName), iAge(_iAge), iHp(_iHp), iMp(_iMp), iGender(_iGender) {};
}HUMAN;

typedef struct __BLOCK
{
	char* c_BlockName;

	int iX_List[Block_Count];
	int iY_List[Block_Count];

	bool bIsCollided;

	__BLOCK() {};
}BLOCK;