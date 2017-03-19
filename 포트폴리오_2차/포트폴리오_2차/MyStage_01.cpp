#include "MyStage_01.h"

#include "DoubleBufferMgr.h"
#include "SceneMgr.h"

//objfactory만들어라
#include "Player.h"
//end

CMyStage_01::CMyStage_01()
{
}


CMyStage_01::~CMyStage_01()
{
}

void CMyStage_01::Initialize()
{
	m_pPlayer = new CPlayer;
	m_pPlayer->Initialize();
}

void CMyStage_01::Progress()
{
	m_pPlayer->Progress();
}

void CMyStage_01::Render()
{
	CDoubleBufferMgr::GetInst()->WriteBuffer(25, 5, "스테이지_01 입니다");
	
	m_pPlayer->Render();

	if (GetAsyncKeyState(VK_ESCAPE))
	{
		CSceneMgr::GetInst()->SetScene(IDS_MENU);
	}
}

void CMyStage_01::Release()
{

}