#include "MainGame.h"

#include "MyLogo.h"

#include "CreateNPCMgr.h"
#include "DoubleBufferMgr.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{
	CDoubleBufferMgr::GetInst()->CreateBuffer(WINC_X, WINC_Y);
}

void CMainGame::Progress()
{
	CDoubleBufferMgr::GetInst()->FlippingBuffer();
	CDoubleBufferMgr::GetInst()->ClearingBuffer();
}

void CMainGame::Render()
{
	/*
	CCreature* Npc01 = CCreateNPCMgr::GetInst()->MakeNPC01();
	Npc01->Render();
	*/
}

void CMainGame::Release()
{

}