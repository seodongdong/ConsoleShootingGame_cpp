#include "include.h"

// 1000 = 1초
float currentTime = GetTickCount();     // 현재 시간

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


    // 위 방향키 처리
    if (GetAsyncKeyState(VK_UP))
    {
        cursorPos--;
        if (cursorPos < 0)
            cursorPos = menuCount - 1;  // 위에서 아래로 순환
    }

    // 아래 방향키 처리
    if (GetAsyncKeyState(VK_DOWN))
    {
        cursorPos++;
        if (cursorPos >= menuCount)
            cursorPos = 0;  // 아래에서 위로 순환
    }

    // 엔터키 처리
    if (GetAsyncKeyState(VK_RETURN))
    {
        if (cursorPos == 0)
        {
            // 게임 시작
            GameMng::GetIns()->stateCtrl.StateChange(new GameState);
        }
        else if (cursorPos == 1)
        {
            // 게임 종료
            exit(0);
        }
    }

    Sleep(100);
}

void MenuState::Draw()
{
    // 테두리 박스
    DrawStr(50, 10, "+----------------------+", WHITE, BLACK);
    DrawStr(50, 11, "     콘솔 슈팅 게임        ", YELLOW, BLACK);
    DrawStr(50, 12, "                        ", WHITE, BLACK);
    DrawStr(50, 13, "     1. 게임 시작         ", GREEN, BLACK);
    DrawStr(50, 14, "     2. 게임 종료         ", RED, BLACK);
    DrawStr(50, 15, "+----------------------+", WHITE, BLACK);

    // 선택 커서
    if (cursorPos == 0)
        DrawStr(50, 13, "▶", WHITE, BLACK);
    else        
        DrawStr(50, 13, " ", BLACK, BLACK);

    if (cursorPos == 1)
        DrawStr(50, 14, "▶", WHITE, BLACK);
    else        
        DrawStr(50, 14, " ", BLACK, BLACK);


    // 선택 후 입력 텍스트 (아래쪽에)
    if (currentTime)
    DrawStr(56, 20, "PRESS ENTER", WHITE, BLACK);
}

void MenuState::Exit()
{
}
