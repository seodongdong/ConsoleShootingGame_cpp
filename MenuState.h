#pragma once
class MenuState : public CState
{
public:
	MenuState();
	~MenuState();

	int cursorPos;	 // 커서 위치
	int menuCount;  // 메뉴 항목 개수 (게임 시작 / 게임 종료)

	void Start();
	void Update();
	void Draw();
	void Exit();
};