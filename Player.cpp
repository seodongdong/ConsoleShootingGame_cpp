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
	Unit::Update();		// �θ�Ŭ������ �Լ��� ȣ��. (���� ������ ��)

	if (GetAsyncKeyState(VK_SPACE))
		gameMng.CreateBullet(x, y);
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
