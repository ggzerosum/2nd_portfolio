#include "CheckKeyMgr.h"

CCheckKeyMgr* CCheckKeyMgr::m_pInst = NULL;

CCheckKeyMgr::CCheckKeyMgr()
{
}


CCheckKeyMgr::~CCheckKeyMgr()
{
}

void CCheckKeyMgr::KeyCheck()
{
	m_dwCheckKey = 0;

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_dwCheckKey |= KEY_UP;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_dwCheckKey |= KEY_DOWN;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_dwCheckKey |= KEY_LEFT;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_dwCheckKey |= KEY_RIGHT;
	}

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		m_dwCheckKey |= KEY_ENTER;
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		m_dwCheckKey |= KEY_SPACE;
	}

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		m_dwCheckKey |= KEY_ESCAPE;
	}
}