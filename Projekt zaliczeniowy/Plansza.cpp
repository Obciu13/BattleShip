#include "Plansza.h"
#include "Maszt.h"
#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;


CPlansza::CPlansza()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			pole[i][j] = new CMaszt;
		}
	}
}


CPlansza::~CPlansza()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			pole[i][j]->~CMaszt();
		}
	}

}

void CPlansza::DrukujPlansze()
{
	int n = 0;
	cout << " ";
	while (n < 10)
	{
		cout << " " << n;
		n++;
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i << " ";
		for (int j = 0; j < 10; j++)
		{
			cout << pole[i][j]->stan << " ";
		}
		cout << endl;
	}

}

void CPlansza::GenerujStatek(int rozmiar) // funkcja generujaca statek. przyjmuje rozmiar statku jako argument.
{
	int x;
	int y;
	int tryb;
	do
	{
		tryb = (rand() % 2) + 1;
		x = (rand() % 10);
		y = (rand() % 10);
	} while (sprawdzenie(x, y, rozmiar, tryb) != 0);
	if (CzyPokazacStatki) { pole[x][y]->stan = 'I'; }// zmiana na I
	else { pole[x][y]->stan = '.'; } // zmiana na .
	pole[x][y]->CzyStatek = 1;
	switch (tryb) // decyzja czy statek jest ustawiany pionowo czy poziomo
	{
	case 1:
		for (int i = 1; i < rozmiar; i++)
		{
			if (CzyPokazacStatki) { pole[x+i][y]->stan = 'I'; }// zmiana na I
			else { pole[x+i][y]->stan = '.'; } // zmiana na .
			pole[x + i][y]->CzyStatek = 1;
		}
		break;
	case 2:
		for (int i = 1; i < rozmiar; i++)
		{
			if (CzyPokazacStatki) { pole[x][y + i]->stan = 'I'; }// zmiana na I
			else { pole[x][y+i]->stan = '.'; } // zmiana na .
			pole[x][y + i]->CzyStatek = 1;
		}
		break;
	}
}


int CPlansza::sprawdzenie(int x, int y, int rozmiar, int tryb) // Przed ka¿dym warunkiem zabezpieczenie przed czytaniem nieistniej¹cych komórek
{
	switch (tryb)
	{
	case 1: // statek pionowy
		if (x + rozmiar >= 10) return 1; // warunek wyjscia poza mape
		if (pole[x][y]->CzyStatek == 1) return 1;  // warunek nie pojawienia sie na statku
		if (x != 0) { if (pole[x - 1][y]->CzyStatek == 1) return 1; } // warunki niestykania siê 1 punktu
		if (y != 9) { if (pole[x][y + 1]->CzyStatek == 1) return 1; }
		if (y != 0) { if (pole[x][y - 1]->CzyStatek == 1) return 1; }
		for (int i = 1; i < rozmiar + 1; i++) // warunki nie stykania siê pozosta³ych punktów
		{
			if (pole[x + i][y]->CzyStatek == 1) return 1;
			if (y != 9) { if (pole[x + i][y + 1]->CzyStatek == 1) return 1; }
			if (y != 0) { if (pole[x + i][y - 1]->CzyStatek == 1) return 1; }
		}
		break;
	case 2: //statek poziomy
		if (y + rozmiar >= 10) return 1; // warunek wyjscia poza mape
		if (pole[x][y]->CzyStatek == 1) return 1; // warunek nie pojawienia sie na statku
		if (y != 0) { if (pole[x][y - 1]->CzyStatek == 1) return 1; } // warunki niestykania siê 1 punktu
		if (x != 9) { if (pole[x + 1][y]->CzyStatek == 1) return 1; }
		if (x != 0) { if (pole[x - 1][y]->CzyStatek == 1) return 1; }
		for (int i = 1; i < rozmiar + 1; i++) // warunki nie stykania siê pozosta³ych punktów
		{
			if (pole[x][y + i]->CzyStatek == 1) return 1;
			if (x != 9) { if (pole[x + 1][y + i]->CzyStatek == 1) return 1; }
			if (x != 0) { if (pole[x - 1][y + i]->CzyStatek == 1) return 1; }
		}
	}
	return 0;
}

void CPlansza::Strzel(int x, int y)
{
	int licznik = 0;
	if (pole[x][y]->CzyStatek == 1)
	{
		if (y != 9) { if (pole[x][y + 1]->CzyStatek == 0) licznik++; }
		else licznik++;
		if (y != 0) { if (pole[x][y - 1]->CzyStatek == 0) licznik++; }
		else licznik++;
		if (x != 9) { if (pole[x + 1][y]->CzyStatek == 0) licznik++; }
		else licznik++;
		if (x != 0) { if (pole[x - 1][y]->CzyStatek == 0) licznik++; }
		else licznik++;
		pole[x][y]->CzyStatek = 0;
		pole[x][y]->stan = 'x';
		DrukujPlansze();
		if (licznik == 4) cout << "trafiony-zatopiony" << endl;
		else cout << "trafiony" << endl;
	}
	else if (pole[x][y]->CzyStatek == 0 && pole[x][y]->stan == 'x' || pole[x][y]->CzyStatek == 0 && pole[x][y]->stan == 'o') cout << "juz tu strzelalismy" << endl;
	if (pole[x][y]->CzyStatek == 0 && pole[x][y]->stan == '.')
	{
		pole[x][y]->stan = 'o';
		DrukujPlansze();
		cout << "pudlo" << endl;
	}
}

int CPlansza::raportuj()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (pole[i][j]->CzyStatek == 1) return 0;
		}
	}
	return 1;
}