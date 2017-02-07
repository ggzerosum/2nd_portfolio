#include "DoubleBufferMgr.h"

CDoubleBufferMgr* CDoubleBufferMgr::m_pInst = NULL;
int CDoubleBufferMgr::m_iBufferIndex = 0;
HANDLE CDoubleBufferMgr::m_hBuffer[2];

CDoubleBufferMgr::CDoubleBufferMgr()
{
}


CDoubleBufferMgr::~CDoubleBufferMgr()
{
}

void CDoubleBufferMgr::CreateBuffer(const int &_width, const int &_heigth)
{
	CONSOLE_CURSOR_INFO DeCursor;
	COORD buffer_size = { _width , _heigth };
	SMALL_RECT rect;

	rect.Top = 0;
	rect.Bottom = _heigth;

	rect.Left = 0;
	rect.Right = _width;


	//1번 버퍼 생성
	m_hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_hBuffer[0], buffer_size);
	SetConsoleWindowInfo(m_hBuffer[0], true, &rect);

	//2번 버퍼 생성
	m_hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_hBuffer[1], buffer_size);
	SetConsoleWindowInfo(m_hBuffer[1], true, &rect);

	//버퍼의 커서 지우기
	DeCursor.dwSize = 1;
	DeCursor.bVisible = false;

	SetConsoleCursorInfo(m_hBuffer[0], &DeCursor);
	SetConsoleCursorInfo(m_hBuffer[1], &DeCursor);

	//cout << "Create Buffer" << endl;
}

void CDoubleBufferMgr::WriteBuffer(const int &_width, const int &_height, char* string)
{
	DWORD dw;
	COORD CursurPosition;

	CursurPosition.X = _width;
	CursurPosition.Y = _height;

	SetConsoleCursorPosition(m_hBuffer[m_iBufferIndex], CursurPosition);
	WriteFile(m_hBuffer[m_iBufferIndex], string, strlen(string), &dw, NULL);

	//cout << "Write Buffer" << endl;
}

void CDoubleBufferMgr::FlippingBuffer()
{
	//Sleep(3);
	
	SetConsoleActiveScreenBuffer(m_hBuffer[m_iBufferIndex]);
	m_iBufferIndex = !m_iBufferIndex;

	//cout << "Flipping Buffer" << endl;
}

void CDoubleBufferMgr::ClearingBuffer()
{
	COORD coor = {0 , 0};
	DWORD dw;

	FillConsoleOutputCharacter(m_hBuffer[m_iBufferIndex], ' ', WINC_X * WINC_Y, coor, &dw);

	//cout << "Clearing Buffer" << endl;
}

void CDoubleBufferMgr::DestroyBuffer()
{
	CloseHandle(m_hBuffer[0]);
	CloseHandle(m_hBuffer[1]);
}