#include "MyLogo.h"

#include "DoubleBufferMgr.h"

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

	m_Logo[0] = "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
	m_Logo[1] = "¡á¡á¡á¡á¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡á¡á¡á¡á";
	m_Logo[2] = "¡á¡á¡á¡á¡á¡á¡á·Î¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á°í¡á¡á¡á¡á¡á¡á¡á¡á";
	m_Logo[3] = "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
	m_Logo[4] = "                                   Press Enter to Skip       ";

	//SetConsoleWindowInfo();
}

void CMyLogo::Progress()
{

}

void CMyLogo::Render()
{

	if (m_check == 0)
	{
		COORD coor = { m_ix, m_iy };

		for (int i = 0; i <= 4; i++)
		{
			coor.X = m_ix;
			coor.Y = m_iy + i;

			//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
			CDoubleBufferMgr::GetInst()->WriteBuffer(coor.X, coor.Y, m_Logo[i]);
		}

		m_check = 1;
	}

	if (GetAsyncKeyState(VK_RETURN))
	{
		system("cls");
	}
}

void CMyLogo::Release()
{

}