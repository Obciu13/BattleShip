#pragma once

#include "Mast.h"

class Player
{
public:
	Player();
	~Player();
	Mast* tMasts[10][10];

	void GenerateShip(int size);
	void PrintBoard();
	int Check(int x, int y, int size, int direction);
	void Shoot(int x, int y);
	int Report();
	bool bShowShips = false;

};
