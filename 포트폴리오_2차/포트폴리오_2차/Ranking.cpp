#include "Ranking.h"

#include "DoubleBufferMgr.h"
#include "SceneMgr.h"

CRanking::CRanking()
{
}


CRanking::~CRanking()
{
}

void CRanking::Initialize()
{

}

void CRanking::Progress()
{

}

void CRanking::Render()
{
	CDoubleBufferMgr::GetInst()->WriteBuffer(25, 5, "��ŷ�Դϴ�");

	if (GetAsyncKeyState(VK_ESCAPE))
	{
		CSceneMgr::GetInst()->SetScene(IDS_MENU);
	}
}

void CRanking::Release()
{

}