#include "include.h"

Enemy::Enemy()
{
	fColor = RED;
	bColor = RED;
	id = ID::ENEMY;
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
	if (y >= 29)
		Disable();
}