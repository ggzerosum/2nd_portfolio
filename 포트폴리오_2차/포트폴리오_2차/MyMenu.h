#pragma once

#include "SceneObj.h"

class CMyMenu : public CSceneObj
{
private :
	char* m_cStr[IDS_MENU_MAX];
	char* m_cMenuTitle[7];
	
	int m_iX;
	int m_iY;
	int m_iEndOfStr;

	int m_iArrowX;
	int m_iArrowY;

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	CMyMenu();
	virtual ~CMyMenu();
};

