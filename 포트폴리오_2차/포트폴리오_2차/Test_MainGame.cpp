#include "Test_MainGame.h"

#include "DoubleBufferMgr.h"
#include "SceneMgr.h"
#include "CheckKeyMgr.h"

CTest_MainGame::CTest_MainGame()
{
}


CTest_MainGame::~CTest_MainGame()
{
}

void CTest_MainGame::Initialize()
{
	CDoubleBufferMgr::GetInst()->CreateBuffer(WINC_X, WINC_Y);
	test_block.Initialize();
}

void CTest_MainGame::Progress()
{
	//버퍼 전환과 버퍼 화면 공백으로 채우기
	CDoubleBufferMgr::GetInst()->FlippingBuffer();
	CDoubleBufferMgr::GetInst()->ClearingBuffer();

	//눌려진 키 체크 (0x8000 으로 정확히 눌려진 시점에 체크함)
	CCheckKeyMgr::GetInst()->KeyCheck();

	test_block.Progress();
}

void CTest_MainGame::Render()
{
	/*
	CCreature* Npc01 = CCreateNPCMgr::GetInst()->MakeNPC01();
	Npc01->Render();
	*/

	test_block.Render();
}

void CTest_MainGame::Release()
{

}