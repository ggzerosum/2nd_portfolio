#include "MyStage_01.h"

#include "DoubleBufferMgr.h"
#include "SceneMgr.h"

//objfactory������
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
	CDoubleBufferMgr::GetInst()->WriteBuffer(25, 5, "��������_01 �Դϴ�");
	
	m_pPlayer->Render();

	if (GetAsyncKeyState(VK_ESCAPE))
	{
		CSceneMgr::GetInst()->SetScene(IDS_MENU);
	}
}

void CMyStage_01::Release()
{

}