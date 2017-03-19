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
	//���� ��ȯ�� ���� ȭ�� �������� ä���
	CDoubleBufferMgr::GetInst()->FlippingBuffer();
	CDoubleBufferMgr::GetInst()->ClearingBuffer();

	//������ Ű üũ (0x8000 ���� ��Ȯ�� ������ ������ üũ��)
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