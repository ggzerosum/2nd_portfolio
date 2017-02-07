#pragma once

#include "Include.h"

class CDoubleBufferMgr
{
private :
	static CDoubleBufferMgr* m_pInst;

private :
	static int m_iBufferIndex;
	static HANDLE m_hBuffer[2];

public :
	static CDoubleBufferMgr* GetInst()
	{
		if (m_pInst == NULL)
		{
			m_pInst = new CDoubleBufferMgr;
		}

		return m_pInst;
	}

public :
	void CreateBuffer(const int &_width, const int &_heigth);
	void WriteBuffer(const int &_width, const int &_height, char* string);
	void FlippingBuffer();
	void ClearingBuffer();
	void DestroyBuffer();


public:
	CDoubleBufferMgr();
	~CDoubleBufferMgr();
};

