#include "MyStage_01.h"

#include "DoubleBufferMgr.h"
#include "SceneMgr.h"

CMyStage_01::CMyStage_01()
{
}


CMyStage_01::~CMyStage_01()
{
}

void CMyStage_01::Initialize()
{

}

void CMyStage_01::Progress()
{

}

void CMyStage_01::Render()
{
	CDoubleBufferMgr::GetInst()->WriteBuffer(25, 5, "스테이지_01 입니다");

	if (GetAsyncKeyState(VK_ESCAPE))
	{
		CSceneMgr::GetInst()->SetScene(IDS_MENU);
	}
}

void CMyStage_01::Release()
{

}