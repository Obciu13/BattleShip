#include "Mast.h"

Mast::Mast()
{
	state = '.';
	set_bShip(false);
}

Mast::Mast(char sign, int size, int direction)
{
	if (sign == '.')
	{
		set_bShip(true);
	}
	else
	{
		set_bShip(false);
	}
	state = sign;
}

Mast::~Mast()
{
}

void Mast::set_state(char character)
{
	state = character;
}

void Mast::set_bShip(bool boolean)
{
	bShip = boolean;
}

char Mast::get_state()
{
	return state;
}

bool Mast::get_bShip()
{
	return bShip;
}
