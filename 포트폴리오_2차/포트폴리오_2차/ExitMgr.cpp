#include "ExitMgr.h"

CExitMgr* CExitMgr::m_pInst = NULL;

CExitMgr::CExitMgr()
	: ExitMgr(true)
{
}


CExitMgr::~CExitMgr()
{
}

void CExitMgr::Set_ExitMgr(bool _tureORfalse)
{
	ExitMgr = _tureORfalse;
}

bool CExitMgr::Get_ExitMgr()
{
	return ExitMgr;
}