#include "Block.h"

#include "DoubleBufferMgr.h"


CBlock::CBlock()
{
}


CBlock::~CBlock()
{
}

void CBlock::Initialize()
{
	Input_BlockList();

	//초기화 진행
	m_MovableBlock.c_BlockName = NULL;
	m_MovableBlock.bIsCollided = false;
	m_MovableBlock.bIsMoving = false;
	m_MovableBlock.iIsInitialized = 0;
}

void CBlock::Progress()
{
	if (!(m_MovableBlock.bIsCollided))
	{
		if (!(m_MovableBlock.iIsInitialized))
		{
			if (!(m_MovableBlock.bIsMoving))
			{
				//int iRandomList = rand() % Block_Max; //블록 맥스만큼 다 적질 않아서 문제가 생겼었음. 일단은 적어놓은 갯수가 2개니까 2개만
				int iRandomList = rand() % 2;
				for (int j = 0; j < Block_Count; j++)
				{
					int iX = m_BlockList[iRandomList].pInfo_List.iX_List[j];
					int iY = m_BlockList[iRandomList].pInfo_List.iY_List[j];

					m_MovableBlock.iX_List[j] = iX;
					m_MovableBlock.iY_List[j] = iY;
					//MovableBlock에 랜덤하게 뽑혀진 블록의 좌표값들이 저장됨.
				}
				m_MovableBlock.iIsInitialized = 1;
				//m_MovableBlock.bIsMoving = true;
			}
		}
	}

	if (m_MovableBlock.bIsCollided)
	{
		for (int i = 0; i < Block_Count; i++)
		{
			m_MovableBlock.iX_List[i] = 0;
			m_MovableBlock.iY_List[i] = 0;
		}
		//m_MovableBlock.bIsMoving = false;//어디에 넣어야할 지 고민중임.
	}
}

void CBlock::Render()
{
	for (int i = 0; i < Block_Count; i++)
	{
		CDoubleBufferMgr::GetInst()->WriteBuffer(m_MovableBlock.iX_List[i], m_MovableBlock.iY_List[i], "X"); //Movable block에 저장된 좌표값만큼 이동시킨다.
		int ix = m_MovableBlock.iX_List[i];
		int iy = m_MovableBlock.iY_List[i];
	}
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
		Block_02	,
		Block_03	,
		Block_04	,
		Block_05	,
		Block_06	,
		Block_07	,
		Block_08	,
		Block_09	,
	};

	//시간이 없어서 수동으로 적습니다.
	//블록 1
	BLOCK BLOCK_00;
	BLOCK_00.c_BlockName = "블록00";
	BLOCK_00.bIsCollided = false;
	BLOCK_00.bIsMoving = false;
	BLOCK_00.iIsInitialized = 0;

	BLOCK_00.iX_List[0] = 1;
	BLOCK_00.iY_List[0] = 0;

	BLOCK_00.iX_List[1] = 1;
	BLOCK_00.iY_List[1] = 1;

	BLOCK_00.iX_List[2] = 0;
	BLOCK_00.iY_List[2] = 1;

	BLOCK_00.iX_List[3] = 2;
	BLOCK_00.iY_List[3] = 1;
	
	m_BlockList[Block_00].pInfo_List = BLOCK_00;

	//블록2
	BLOCK BLOCK_01;
	BLOCK_01.c_BlockName = "블록01";
	BLOCK_01.bIsCollided = false;
	BLOCK_01.bIsMoving = false;
	BLOCK_01.iIsInitialized = 0;

	BLOCK_01.iX_List[0] = 0;
	BLOCK_01.iY_List[0] = 0;

	BLOCK_01.iX_List[1] = 0;
	BLOCK_01.iY_List[1] = 1;

	BLOCK_01.iX_List[2] = 0;
	BLOCK_01.iY_List[2] = 2;

	BLOCK_01.iX_List[3] = 0;
	BLOCK_01.iY_List[3] = 3;

	m_BlockList[Block_01].pInfo_List = BLOCK_01;
}