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
	
	//���� ��ȯ�� ���� ȭ�� �������� ä���
	CDoubleBufferMgr::GetInst()->FlippingBuffer();
	CDoubleBufferMgr::GetInst()->ClearingBuffer();
	
	//������ Ű üũ (0x8000 ���� ��Ȯ�� ������ ������ üũ��)
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