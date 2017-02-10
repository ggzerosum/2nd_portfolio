#include "Block.h"



CBlock::CBlock()
{
}


CBlock::~CBlock()
{
}

void CBlock::Initialize()
{
	Input_BlockList();

	//�ʱ�ȭ ����
	m_MovableBlock.c_BlockName = NULL;
	m_MovableBlock.bIsCollided = false;
	m_MovableBlock.bIsMoving = false;
}

void CBlock::Progress()
{
	if (!(m_MovableBlock.bIsCollided))
	{
		if (!(m_MovableBlock.bIsMoving))
		{
			int iRandomList = rand() % Block_Max;
			for (int j = 0; j < Block_Count; j++)
			{
				int iX = m_BlockList[iRandomList].pInfo_List.iX_List[j];
				int iY = m_BlockList[iRandomList].pInfo_List.iY_List[j];

				m_MovableBlock.iX_List[j] = iX;
				m_MovableBlock.iY_List[j] = iY;
				//MovableBlock�� �����ϰ� ������ ����� ��ǥ������ �����.
			}
			m_MovableBlock.bIsMoving = true;
		}
	}

	if (m_MovableBlock.bIsCollided)
	{
		for (int i = 0; i < Block_Count; i++)
		{
			m_MovableBlock.iX_List[i] = 0;
			m_MovableBlock.iY_List[i] = 0;
		}
		//m_MovableBlock.bIsMoving = false;//��� �־���� �� �������.
	}
}

void CBlock::Render()
{


}

void CBlock::Release()
{

}

void CBlock::Input_BlockList()
{
	enum
	{
		Block_00	,
		Block_01	,
	};

	//�ð��� ��� �������� �����ϴ�.
	//��� 1
	BLOCK BLOCK_00;
	BLOCK_00.c_BlockName = "���00";
	BLOCK_00.bIsCollided = false;
	BLOCK_00.bIsMoving = false;

	BLOCK_00.iX_List[0] = 1;
	BLOCK_00.iY_List[0] = 0;

	BLOCK_00.iX_List[1] = 1;
	BLOCK_00.iY_List[1] = 1;

	BLOCK_00.iX_List[2] = 0;
	BLOCK_00.iY_List[2] = 1;

	BLOCK_00.iX_List[3] = 2;
	BLOCK_00.iY_List[3] = 1;
	
	m_BlockList[Block_00].pInfo_List = BLOCK_00;

	//���2
	BLOCK BLOCK_01;
	BLOCK_01.c_BlockName = "���01";
	BLOCK_01.bIsCollided = false;
	BLOCK_01.bIsMoving = false;

	BLOCK_01.iX_List[0] = 0;
	BLOCK_01.iY_List[0] = 0;

	BLOCK_01.iX_List[1] = 0;
	BLOCK_01.iY_List[1] = 1;

	BLOCK_01.iX_List[2] = 0;
	BLOCK_01.iY_List[2] = 2;

	BLOCK_01.iX_List[3] = 0;
	BLOCK_01.iY_List[3] = 3;

	m_BlockList[Block_01].pInfo_List = BLOCK_00;
}