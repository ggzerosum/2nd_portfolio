#include "Score.h"

#include "DoubleBufferMgr.h"
#include "SceneMgr.h"

CScore::CScore()
{
}


CScore::~CScore()
{
}

void CScore::Initialize()
{

}

void CScore::Progress()
{

}

void CScore::Render()
{
	CDoubleBufferMgr::GetInst()->WriteBuffer(25, 5, "���ھ��Դϴ�");

	if (GetAsyncKeyState(VK_ESCAPE))
	{
		CSceneMgr::GetInst()->SetScene(IDS_MENU);
	}
}

void CScore::Release()
{

}