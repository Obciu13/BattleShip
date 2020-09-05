#pragma once
class Mast
{
public:
	Mast();
	Mast(char sign, int size, int direction);
	~Mast();

	void set_state(char character);
	void set_bShip(bool bShip);

	char get_state();
	bool get_bShip();

private:
	char state; // . - zakryte, x - zestrzelone, o - pud³o
	bool bShip; //0 - nie , 1 - tak

};

