#include "Npc01.h"



CNpc01::CNpc01()
{
	this->Initialize();
}


CNpc01::~CNpc01()
{
	this->Release();
}

void CNpc01::Initialize()
{
	HUMAN* Address = GetNPCInfo();
	tag_info = *Address;

	delete Address;
	Address = NULL;
}

void CNpc01::Progress()
{

}

void CNpc01::Render()
{
	cout << "안녕하세요" << endl;
	cout << "저는" << tag_info.cName << "입니다" << endl;
	cout << "저의 나이는 " << tag_info.iAge << "입니다" << endl;
}

void CNpc01::Release()
{
	delete[] tag_info.cName;
	tag_info.cName = NULL;
}

HUMAN* CNpc01::GetNPCInfo()
{
	FILE* Name_List;
	fopen_s(&Name_List, "NPC_Name.txt", "r");

	char str[128] = { '\0' };

	int Num = 0;
	int R_Line;

	int iAge;
	int iHp;
	int iMp;
	int iGender;

	for (int i = 1; fgets(str, sizeof(str), Name_List) != NULL; i++)
	{
		Num = i;
	}
	
	//cout << "최대 줄 수 : " << Num << endl;
	R_Line = rand() % Num + 1;
	rewind(Name_List);

	for (int i = 1; i <= Num; i++)
	{
		if (i == R_Line) break;
		fgets(str, sizeof(str), Name_List);
	}

	fscanf_s(Name_List, "%s %d %d %d %d", str, strlen(str) + 1, &iAge, &iHp, &iMp, &iGender); //형식 주의
	char* pName = new char[strlen(str) + 1];
	strcpy_s(pName, strlen(str) + 1, str);

	HUMAN* Temp = new HUMAN;
	*Temp = HUMAN(pName, iAge, iHp, iMp, iGender);

	return Temp;

	/*if (fgets(str, sizeof(str), Name_List) != NULL)
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