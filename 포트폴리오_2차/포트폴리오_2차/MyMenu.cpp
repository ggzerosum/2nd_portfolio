#include "MyMenu.h"

#include "DoubleBufferMgr.h"
#include "SceneMgr.h"

#include "ExitMgr.h"

CMyMenu::CMyMenu()
{
}


CMyMenu::~CMyMenu()
{
}

void CMyMenu::Initialize()
{
	m_cStr[IDS_MENU_START] = "시 작 하 기";
	m_cStr[IDS_MENU_SCORE] = "스코어 보기";
	m_cStr[IDS_MENU_RANKING] = "랭 킹 보 기";
	m_cStr[IDS_MENU_EXIT] = "종 료 하 기";
	//////////////////////////
	m_cMenuTitle[0] = "@@@@@@@   @@@@@@@@  @@@@@@@   @@@@@@@@     @@@@@@    @@@@@@@@@";
	m_cMenuTitle[1] = "  @@@     @@@         @@@     @@    @@       @@      @@       ";
	m_cMenuTitle[2] = "  @@@     @@@@@@@@    @@@     @@@@@@@@       @@      @@       ";
	m_cMenuTitle[3] = "  @@@     @@@@@@@@    @@@     @@  @@@        @@      @@@@@@@@@";
	m_cMenuTitle[4] = "  @@@     @@@         @@@     @@   @@@       @@             @@";
	m_cMenuTitle[5] = "  @@@     @@@@@@@@    @@@     @@    @@@      @@             @@";
	m_cMenuTitle[6] = "  @@@     @@@@@@@@    @@@     @@     @@@   @@@@@@    @@@@@@@@@";
	//////////////////////////

	m_iX = 50;
	m_iY = 20;
	m_iEndOfStr = 0;

	m_iArrowX = m_iX;
	m_iArrowY = m_iY;
}

void CMyMenu::Progress()
{

}

void CMyMenu::Render()
{
	int MenuBar_ix = 25;
	int MenuBar_iy = 5;

	for (int i = 0; i < 7; i++)
	{
		CDoubleBufferMgr::GetInst()->WriteBuffer(MenuBar_ix, MenuBar_iy, m_cMenuTitle[i]);
		MenuBar_iy++;
	}

	COORD coor;

	m_iEndOfStr = 0;
	for (int i = 0; i < IDS_MENU_MAX; i++)
	{
		coor.X = m_iX;
		coor.Y = m_iY + i;

		CDoubleBufferMgr::GetInst()->WriteBuffer(coor.X, coor.Y, m_cStr[i]);
		
		m_iEndOfStr++;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		if (m_iY < m_iArrowY)
		{
			CDoubleBufferMgr::GetInst()->WriteBuffer(m_iArrowX - 2, m_iArrowY -= 1, "▶");
		}
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		if (m_iY + (m_iEndOfStr - 1) > m_iArrowY)
		{
			CDoubleBufferMgr::GetInst()->WriteBuffer(m_iArrowX - 2, m_iArrowY += 1, "▶");
		}
	}

	CDoubleBufferMgr::GetInst()->WriteBuffer(m_iArrowX - 2, m_iArrowY, "▶");

	if (GetAsyncKeyState(VK_RETURN))
	{
		switch (m_iArrowY - m_iY)
		{
		case IDS_MENU_START :
			CSceneMgr::GetInst()->SetScene(IDS_STAGE_01);
			break;

		case IDS_MENU_SCORE :
			CSceneMgr::GetInst()->SetScene(IDS_SCENE_SCORE);
			break;

		case IDS_MENU_RANKING :
			CSceneMgr::GetInst()->SetScene(IDS_SCENE_RANKING);
			break;

		case IDS_MENU_EXIT :
			//CExitMgr::GetInst()->Set_ExitMgr(false);//extern을 쓰는게 더 간단하다.
			EXIT = false;
			break;
		}
	}
}

void CMyMenu::Release()
{

}