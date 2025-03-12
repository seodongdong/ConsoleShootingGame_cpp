#include "include.h"

Player::Player()
{
	isAlive = true;
	x = 60;
	y = 15;
	body = 'A';
}

Player::~Player()
{
}

void Player::Update()
{
	Unit::Update();		// 부모클래스의 함수를 호출. (같은 내용일 때)

	if (GetAsyncKeyState(VK_SPACE))
	{
		((GameState*)GameMng::GetIns()->stateCtrl.m_pCurState)->CreateBullet(x, y);
	}
}

void Player::Draw()
{
	if (isAlive)
		DrawChar(x, y, body, fColor, bColor);

	if (GetAsyncKeyState(VK_SPACE))  // 스페이스바 눌리면
	{
		if (level == 1)
		{
			// 플레이어 아래(몸체 밑)에 출력하기
			DrawStr(x - 1, y + 1, "빵!", YELLOW, BLACK);  // 발사 효과
		}
		if (level == 2)
		{
			DrawStr(x - 2, y + 1, "빵빵!", YELLOW, BLACK);  // 발사 효과
		}
		if (level == 3)
		{
			DrawStr(x - 3, y + 1, "빵빵빵!", YELLOW, BLACK);  // 발사 효과
		}
	}
	else
	{
		// 안 누르면 아무것도 안 그림
		DrawStr(x, y + 1, " ", BLACK, BLACK);
	}

	if (GetAsyncKeyState('A'))
		DrawStr(x - 2, y, "<", YELLOW, BLACK);
	if (GetAsyncKeyState('D'))
		DrawStr(x + 2, y, ">", YELLOW, BLACK);
}

void Player::Move()
{
	if (GetAsyncKeyState('W'))
		y--;
	if (GetAsyncKeyState('A'))
		x--;
	if (GetAsyncKeyState('S'))
		y++;
	if (GetAsyncKeyState('D'))
		x++;
}

void Player::Clipping()
{
	if (x < 0)
		x = 0;
	if (x > 119)
		x = 119;
	if (y < 0)
		y = 0;
	if (y > 29)
		y = 29;
}
