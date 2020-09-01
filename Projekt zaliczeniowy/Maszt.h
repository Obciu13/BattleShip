#pragma once
class CMaszt
{
public:
	CMaszt();
	CMaszt(char znak, int rozmiar, int tryb);
	~CMaszt();

	char stan; // . - zakryte, x - zestrzelone, o - pud³o
	int CzyStatek; //0 - nie , 1 - tak

};

