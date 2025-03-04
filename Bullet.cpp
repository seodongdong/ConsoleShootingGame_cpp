#include "include.h"


Bullet::Bullet()
{
	body = '|';
	fColor = GREEN;
}

Bullet::~Bullet()
{
}

void Bullet::Move()
{
	//if (isAlive)
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
