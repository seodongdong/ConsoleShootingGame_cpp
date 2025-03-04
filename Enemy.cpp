#include "include.h"

Enemy::Enemy()
{
	fColor = RED;
	bColor = RED;
}

Enemy::~Enemy()
{
}

void Enemy::Move()
{
	y++;
}

void Enemy::Clipping()
{
	if (y >= 30)
		Disable();
}