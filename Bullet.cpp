#include "include.h"


Bullet::Bullet()
{
	body = '|';
	fColor = GREEN;
	id = ID::BULLET;
}

Bullet::~Bullet()
{
}

void Bullet::Move()
{
	y--;
}

void Bullet::Clipping()
{
	if (y < 0)
		Disable();
}

//void CreateBullet(int x, int y)
//{
//
//}
