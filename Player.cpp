#include "include.h"

Player::Player()
{
	x = 60;
	y = 15;
	body = 'A';
	fColor = WHITE;
	bColor = BLACK;
}

Player::~Player()
{
}

void Player::Update()
{
	Move();
	Clipping();

	if (GetAsyncKeyState(VK_SPACE))
		CreateBullet(x, y);
}

void Player::Draw()
{
	DrawChar(x, y, body, fColor, bColor);
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
