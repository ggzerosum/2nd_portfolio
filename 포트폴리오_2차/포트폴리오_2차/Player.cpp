#include "Player.h"

#include "CheckKeyMgr.h"
#include "Block.h"

CPlayer::CPlayer()
{
	for (int i = 0; i < total_block_information; i++)
	{
		m_pBlock[i] = NULL;
	}

	dwKeyCheck = 0;
}


CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	
}

void CPlayer::Progress()
{
	for (int i = 0; i < total_block_information; i++)
	{
		if (m_pBlock[i] == NULL)
		{
			m_pBlock[i] = new CBlock;
			m_pBlock[i]->Initialize(); //Block ��ü �ʱ�ȭ�� ������ ��� ��� ���ý�Ű��.
		}
	}

	CheckKey();

	for (int i = 0; i < total_block_information; i++)
	{
		if (m_pBlock[i] != NULL)
		{
			m_pBlock[i]->Progress();
		}
	}
}

void CPlayer::Render()
{
	m_pBlock[0]->Render();
}

void CPlayer::Release()
{

}

void CPlayer::CheckKey()
{

	dwKeyCheck = CCheckKeyMgr::GetInst()->GetKey();

	if (dwKeyCheck & KEY_LEFT)
	{
		for (int i = 0; i < Block_Count; i++)
		{
			int &iX = ((CBlock*)m_pBlock[0])->Get_MovableBlock().iX_List[i];

			if (iX - 1 < 0)
				break;

			iX -= 1; //�����ڸ� ����ߴ�.
		}
	}

	//dwKeyCheck & KEY_RIGHT
	if (true)
	{
		for (int i = 0; i < Block_Count; i++)
		{
			int &iX = ((CBlock*)m_pBlock[0])->Get_MovableBlock().iX_List[i];

			if (iX + 1 > WINC_X)
				break;

			iX += 1; //�����ڸ� ����ߴ�.
		}
	}
}