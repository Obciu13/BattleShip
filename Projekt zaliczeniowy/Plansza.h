#pragma once
#include "Maszt.h"

class CPlansza
{
public: 
	CPlansza();
	~CPlansza();
	CMaszt * pole[10][10];

	void GenerujStatek(int rozmiar);
	void DrukujPlansze();
	int sprawdzenie(int x, int y, int rozmiar, int tryb);
	void Strzel(int x, int y);
	int raportuj();
	bool CzyPokazacStatki = false;

};

