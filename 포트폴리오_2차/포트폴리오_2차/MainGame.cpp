#include "MainGame.h"

//#include "MyLogo.h"
//#include "CreateNPCMgr.h"
#include "DoubleBufferMgr.h"
#include "SceneMgr.h"
#include "CheckKeyMgr.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{
	CDoubleBufferMgr::GetInst()->CreateBuffer(WINC_X, WINC_Y);
	CSceneMgr::GetInst()->SetScene(IDS_LOGO);
}

void CMainGame::Progress()
{
	CSceneMgr::GetInst()->Progress();
	
	//버퍼 전환과 버퍼 화면 공백으로 채우기
	CDoubleBufferMgr::GetInst()->FlippingBuffer();
	CDoubleBufferMgr::GetInst()->ClearingBuffer();
	
	//눌려진 키 체크 (0x8000 으로 정확히 눌려진 시점에 체크함)
	CCheckKeyMgr::GetInst()->KeyCheck();
}

void CMainGame::Render()
{
	CSceneMgr::GetInst()->Render();
	/*
	CCreature* Npc01 = CCreateNPCMgr::GetInst()->MakeNPC01();
	Npc01->Render();
	*/
}

void CMainGame::Release()
{

}