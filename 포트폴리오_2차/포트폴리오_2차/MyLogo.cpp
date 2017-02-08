#include "MyLogo.h"

#include "DoubleBufferMgr.h"
#include "SceneMgr.h"

CMyLogo::CMyLogo()
{
}


CMyLogo::~CMyLogo()
{
}

void CMyLogo::Initialize()
{
	m_ix = 10;
	m_iy = 10;

	m_check = 0;

	m_Logo[0] = "���������������������������������������������";
	m_Logo[1] = "���������������������������������������������";
	m_Logo[2] = "��������Ρ������������������������������������";
	m_Logo[3] = "���������������������������������������������";
	m_Logo[4] = "                                   Press Enter to Skip       ";

	//cout << "�ΰ� �̴ϼȶ�����" << endl;
}

void CMyLogo::Progress()
{
	//cout << "�ΰ� ���α׷���" << endl;
}

void CMyLogo::Render()
{

	COORD coor = { m_ix, m_iy };

	for (int i = 0; i <= 4; i++)
	{
		coor.X = m_ix;
		coor.Y = m_iy + i;

		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
		CDoubleBufferMgr::GetInst()->WriteBuffer(coor.X, coor.Y, m_Logo[i]);
	}

	if (GetAsyncKeyState(VK_RETURN))
	{
		CSceneMgr::GetInst()->SetScene(IDS_MENU);
	}
}

void CMyLogo::Release()
{

}