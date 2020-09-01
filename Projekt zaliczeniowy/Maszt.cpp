#include "Maszt.h"



CMaszt::CMaszt()
{
	stan = '.';
	CzyStatek = 0;
}

CMaszt::CMaszt(char znak, int rozmiar, int tryb)
{
	if (znak == '.')
	{
		CzyStatek = 1;
	}
	else
	{
		CzyStatek = 0;
	}
	stan = znak;
}

CMaszt::~CMaszt()
{
}
