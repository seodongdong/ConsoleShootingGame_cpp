#pragma once

class CStateCtrl
{
public:
	CState* m_pCurState;			// 현재 state
	CState* m_pPrevState;			// 전 state

	CState* m_pStates[STATE::MAX];
	
public:
	CStateCtrl();
	~CStateCtrl();

public:
	void Init();
	bool StateAdd(int nIndex, CState* pState);
	bool StateRelease(int nIndex);
	bool StateChange(int nIndex);
	bool StateChange(CState* pState);	// 오버로드

public:
	void Update();
	void Draw();
};