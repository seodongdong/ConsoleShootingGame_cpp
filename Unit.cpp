#include "include.h"

Unit::Unit()
{
	isAlive = false;
	x = 0;
	y = 0;
	fColor = WHITE;
	bColor = BLACK;
	body = ' ';
}

Unit::~Unit()
{
}

void Unit::Update()
{
	if (isAlive)
	{
		Move();
		Clipping();
	}
}

void Unit::Draw()
{
	if (isAlive)
		DrawChar(x, y, body, fColor, bColor);
}

void Unit::Move()
{

}

void Unit::Clipping()
{

}

void Unit::Enable(int x, int y)
{
	this->x = x;
	this->y = y;
	isAlive = true;
}

void Unit::Disable()
{
	isAlive = false;
}
