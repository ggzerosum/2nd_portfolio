#include "MainGame.h"

#include "CreateNPCMgr.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{
	
}

void CMainGame::Progress()
{

}

void CMainGame::Render()
{
	CCreature* Npc01 = CCreateNPCMgr::GetInst()->MakeNPC01();
	Npc01->Render();
}

void CMainGame::Release()
{

}