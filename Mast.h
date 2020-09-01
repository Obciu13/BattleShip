#pragma once
class Mast
{
public:
	Mast();
	Mast(char sign, int size, int direction);
	~Mast();

	char state; // . - zakryte, x - zestrzelone, o - pud³o
	int bShip; //0 - nie , 1 - tak

};

