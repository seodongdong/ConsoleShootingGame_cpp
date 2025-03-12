#include "include.h"

// 1000 = 1초
float currentTime = GetTickCount();     // 현재 시간
DWORD lastInputTime = 0;    // 마지막 입력 시간
DWORD inputDelay = 1000;	// 딜레이 시간 (1초)

MenuState::MenuState()
{
	cursorPos = 0;
	menuCount = 2;
}

MenuState::~MenuState()
{
}

void MenuState::Start()
{
}

void MenuState::Update()
{
	//if (GetAsyncKeyState(VK_RETURN))
	//{
	//	GameMng::GetIns()->stateCtrl.StateChange(new GameState);
	//}

    if (currentTime)

    // 위 방향키 처리
    if (GetAsyncKeyState(VK_UP))
    {
		if (currentTime - lastInputTime >= inputDelay)
		{
			cursorPos--;
			if (cursorPos < 0)
				cursorPos = menuCount - 1;  // 위에서 아래로 순환
			lastInputTime = currentTime;
		}   
        cursorPos--;
        if (cursorPos < 0)
            cursorPos = menuCount - 1;  // 위에서 아래로 순환
    }

    // 아래 방향키 처리
    if (GetAsyncKeyState(VK_DOWN))
    {
		if (currentTime - lastInputTime >= inputDelay)
		{
			cursorPos++;
			if (cursorPos >= menuCount)
				cursorPos = 0;  // 아래에서 위로 순환
			lastInputTime = currentTime;
		}
    }

    // 엔터키 처리
    if (GetAsyncKeyState(VK_RETURN))
    {
        if (cursorPos == 0)
        {
            // 게임 시작!
            GameMng::GetIns()->stateCtrl.StateChange(new GameState);
        }
        else if (cursorPos == 1)
        {
            // 게임 종료!
            exit(0);
        }
    }
}

void MenuState::Draw()
{
    // 테두리 박스
    DrawStr(50, 4, "+----------------------+", WHITE, BLACK);
    DrawStr(50, 5, "     콘솔 슈팅 게임        ", YELLOW, BLACK);
    DrawStr(50, 6, "                        ", WHITE, BLACK);
    DrawStr(50, 7, "     1. 게임 시작         ", GREEN, BLACK);
    DrawStr(50, 8, "     2. 게임 종료         ", RED, BLACK);
    DrawStr(50, 9, "+----------------------+", WHITE, BLACK);

    // 선택 커서
    if (cursorPos == 0)
        DrawStr(50, 7, "▶", WHITE, BLACK);
    else        
        DrawStr(50, 7, " ", BLACK, BLACK);

    if (cursorPos == 1)
        DrawStr(50, 8, "▶", WHITE, BLACK);
    else        
        DrawStr(50, 8, " ", BLACK, BLACK);


    // 선택 후 입력 텍스트 (아래쪽에)
    DrawStr(56, 12, "PRESS ENTER", YELLOW, BLACK);
}

void MenuState::Exit()
{
}
