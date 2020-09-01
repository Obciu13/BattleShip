#include "Mast.h"

Mast::Mast()
{
	state = '.';
	bShip = 0;
}

Mast::Mast(char sign, int size, int direction)
{
	if (sign == '.')
	{
		bShip = 1;
	}
	else
	{
		bShip = 0;
	}
	state = sign;
}

Mast::~Mast()
{
}