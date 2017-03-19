#include "Include.h"

/////
#include "MainGame.h"
#include "ExitMgr.h"
/////

////Start_Test
#include "Test_MainGame.h"
#include "MyLogo.h"
#include "Block.h"
#include "DoubleBufferMgr.h"
///End_Test

bool EXIT;

int main()
{
	EXIT = true;

	srand(time(NULL));

	CMainGame MainGame;
	MainGame.Initialize();

	DWORD dwTime = GetTickCount();

	while (EXIT)
	{
		if (dwTime + 80 < GetTickCount())
		{
			dwTime = GetTickCount();

			MainGame.Progress();
			MainGame.Render();
		}
	}

	/*CTest_MainGame obj;
	obj.Initialize();

	while (EXIT)
	{
		obj.Progress();
		obj.Render();

		Sleep(1000);
	}*/



	//CDoubleBufferMgr::GetInst()->CreateBuffer(WINC_X, WINC_Y);
	//
	//int i = 0;

	//while (true)
	//{
	//	CDoubleBufferMgr::GetInst()->FlippingBuffer();
	//	CDoubleBufferMgr::GetInst()->ClearingBuffer();

	//	if (i % 2 == 0)
	//	{
	//		CDoubleBufferMgr::GetInst()->WriteBuffer(1, 1, "¾È³çÇÏ¼¼¿ä");
	//	}
	//	else
	//	{
	//		CDoubleBufferMgr::GetInst()->WriteBuffer(1, 1, "¾È³ç");
	//	}

	//	i++;
	//	//Sleep(1000);
	//}
	/*
	CMyLogo obj02;
	obj02.Initialize();
	obj02.Render();
	*/

	/*FILE* TEST;
	fopen_s(&TEST, "Text.txt", "r");
	
	char str[128] = { '\0' };

	while (fgets(str, sizeof(str), TEST) != NULL)
	{
		int length = strlen(str);
		for (int i = 0; i < length; i++)
		{
			if (str[i] & 0x80)
			{ 
				printf("%1.2s", &(str[i]));
				i++;
			}
			else
			{
				printf("%.1s", &(str[i]));
			}

			Sleep(300);
		}
	}*/
}