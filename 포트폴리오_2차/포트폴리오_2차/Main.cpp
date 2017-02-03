#include "Include.h"

#include "MainGame.h"

int main()
{
	srand(time(NULL));
	
	CMainGame obj;
	obj.Render();

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