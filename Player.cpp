#include "Player.h"
#include "Mast.h"
#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;


Player::Player()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			tMasts[i][j] = new Mast;
		}
	}
}


Player::~Player()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			tMasts[i][j]->~Mast();
		}
	}

}

void Player::set_bShowShips(bool show)
{
	bShowShips = show;
}

bool Player::get_bShowShips()
{
	return bShowShips;
}

void Player::PrintBoard()
{
	int n = 0;
	cout << " ";
	while (n < 10)
	{
		cout << " " << n;
		n++;
	}
	cout << " x" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i << " ";
		for (int j = 0; j < 10; j++)
		{
			cout << tMasts[j][i]->get_state() << " ";
		}
		cout << endl;
	}
	cout << "y" << endl;

}

void Player::GenerateShip(int size) // funkcja generujaca statek. przyjmuje size statku jako argument.
{
	int x;
	int y;
	int direction;
	do
	{
		direction = (rand() % 2) + 1;
		x = (rand() % 10);
		y = (rand() % 10);
	} while (Check(x, y, size, direction) != 0);
	if (bShowShips) { tMasts[x][y]->set_state('I'); }// zmiana na I
	else { tMasts[x][y]->set_state('.'); } // zmiana na .
	tMasts[x][y]->set_bShip(true);
	switch (direction) // decyzja czy statek jest ustawiany pionowo czy poziomo
	{
	case 1:
		for (int i = 1; i < size; i++)
		{
			if (bShowShips) { tMasts[x + i][y]->set_state('I'); }// zmiana na I
			else { tMasts[x + i][y]->set_state('.'); } // zmiana na .
			tMasts[x + i][y]->set_bShip(true);
		}
		break;
	case 2:
		for (int i = 1; i < size; i++)
		{
			if (bShowShips) { tMasts[x][y + i]->set_state('I'); }// zmiana na I
			else { tMasts[x][y + i]->set_state('.'); } // zmiana na .
			tMasts[x][y + i]->set_bShip(true);
		}
		break;
	}
}


int Player::Check(int x, int y, int size, int direction) // Przed ka¿dym warunkiem zabezpieczenie przed czytaniem nieistniejšcych komórek
{
	switch (direction)
	{
	case 1: // statek pionowy
		if (x + size >= 10) return 1; // warunek wyjscia poza mape
		if (tMasts[x][y]->get_bShip() == true) return 1;  // warunek nie pojawienia sie na statku
		if (x != 0) { if (tMasts[x - 1][y]->get_bShip() == true) return 1; } // warunki niestykania siê 1 punktu
		if (y != 9) { if (tMasts[x][y + 1]->get_bShip() == true) return 1; }
		if (y != 0) { if (tMasts[x][y - 1]->get_bShip() == true) return 1; }
		for (int i = 1; i < size + 1; i++) // warunki nie stykania siê pozosta³ych punktów
		{
			if (tMasts[x + i][y]->get_bShip() == true) return 1;
			if (y != 9) { if (tMasts[x + i][y + 1]->get_bShip() == true) return 1; }
			if (y != 0) { if (tMasts[x + i][y - 1]->get_bShip() == true) return 1; }
		}
		break;
	case 2: //statek poziomy
		if (y + size >= 10) return 1; // warunek wyjscia poza mape
		if (tMasts[x][y]->get_bShip() == true) return 1; // warunek nie pojawienia sie na statku
		if (y != 0) { if (tMasts[x][y - 1]->get_bShip() == true) return 1; } // warunki niestykania siê 1 punktu
		if (x != 9) { if (tMasts[x + 1][y]->get_bShip() == true) return 1; }
		if (x != 0) { if (tMasts[x - 1][y]->get_bShip() == true) return 1; }
		for (int i = 1; i < size + 1; i++) // warunki nie stykania siê pozosta³ych punktów
		{
			if (tMasts[x][y + i]->get_bShip() == true) return 1;
			if (x != 9) { if (tMasts[x + 1][y + i]->get_bShip() == true) return 1; }
			if (x != 0) { if (tMasts[x - 1][y + i]->get_bShip() == true) return 1; }
		}
	}
	return 0;
}

void Player::Shoot(int x, int y)
{
	int licznik = 0;
	if (tMasts[x][y]->get_bShip() == true)
	{
		if (y != 9) { if (tMasts[x][y + 1]->get_bShip() == false) licznik++; }
		else licznik++;
		if (y != 0) { if (tMasts[x][y - 1]->get_bShip() == false) licznik++; }
		else licznik++;
		if (x != 9) { if (tMasts[x + 1][y]->get_bShip() == false) licznik++; }
		else licznik++;
		if (x != 0) { if (tMasts[x - 1][y]->get_bShip() == false) licznik++; }
		else licznik++;
		tMasts[x][y]->set_bShip(false);
		tMasts[x][y]->set_state('x');
		PrintBoard();
		if (licznik == 4) cout << "Destroyed" << endl;
		else cout << "Hitted" << endl;
	}
	else if (tMasts[x][y]->get_bShip() == false && tMasts[x][y]->get_state()=='x' || tMasts[x][y]->get_bShip() == false && tMasts[x][y]->get_state() == 'o') cout << "We shot here already" << endl;
	if (tMasts[x][y]->get_bShip() == false && tMasts[x][y]->get_state() == '.')
	{
		tMasts[x][y]->set_state('o');
		PrintBoard();
		cout << "Missed" << endl;
	}
}

int Player::Report()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (tMasts[i][j]->get_bShip() == true) return 0;
		}
	}
	return 1;

}