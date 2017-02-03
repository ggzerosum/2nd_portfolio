#pragma once

#include "SceneObj.h"

class CMyLogo : public CSceneObj
{
private :
	int m_ix;
	int m_iy;
	int m_check;

	char* m_Logo[5];

public :
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	CMyLogo();
	virtual ~CMyLogo();
};

