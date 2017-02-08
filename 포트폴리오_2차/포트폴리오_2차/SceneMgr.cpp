#include "SceneMgr.h"

//SCENE included
#include "MyLogo.h"
#include "MyMenu.h"
#include "Score.h"
#include "Ranking.h"

#include "MyStage_01.h"
//end

CSceneMgr* CSceneMgr::m_pInst = NULL;

CSceneMgr::CSceneMgr()
	: m_pSceneMgr(NULL)
{
}


CSceneMgr::~CSceneMgr()
{
}

void CSceneMgr::SetScene(STATE_SCENE _stageids)
{
	if (m_pSceneMgr != NULL)
	{
		delete m_pSceneMgr;
		m_pSceneMgr = NULL;
	}

	switch (_stageids)
	{
	case IDS_LOGO :
		m_pSceneMgr = new CMyLogo;
		break;

	case IDS_MENU :
		m_pSceneMgr = new CMyMenu;
		break;

	case IDS_STAGE_01 :
		m_pSceneMgr = new CMyStage_01;
		break;

	case IDS_SCENE_SCORE :
		m_pSceneMgr = new CScore;
		break;

	case IDS_SCENE_RANKING :
		m_pSceneMgr = new CRanking;
		break;
	}

	m_pSceneMgr->Initialize();
}

void CSceneMgr::Progress()
{
	m_pSceneMgr->Progress();
}

void CSceneMgr::Render()
{
	m_pSceneMgr->Render();
}

void CSceneMgr::Release()
{

}