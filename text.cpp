#include "include.h"

Text::Text()
{
	str = "Hello";
	isAlive = true;

	std::stringstream ss;
	ss << "Hello" << 10 << 'A';

	str = ss.str();
}

Text::~Text()
{
}

void Text::Draw()
{
	if (isAlive)
		DrawStr(x, y, str.c_str(), fColor, bColor);
}
