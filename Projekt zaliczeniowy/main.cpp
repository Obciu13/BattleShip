#include "Plansza.h"
#include "Maszt.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <cstdlib>

using namespace std;


int main()
{
	srand(time(NULL));
	int x;
	int y;
	string odpowiedz;
	CPlansza gracz1;
	CPlansza gracz2;


	cout << "Czy pokazac lokalizacje statkow? (tryb debugowania). Wpisz Tak lub Nie " << endl;
	cin >> odpowiedz;
	if (odpowiedz == "Tak") {
		gracz1.CzyPokazacStatki = true;
		gracz2.CzyPokazacStatki = true;
	}
	system("cls");

	 gracz1.GenerujStatek(1);
	 gracz1.GenerujStatek(1);
	 gracz1.GenerujStatek(1);
	 gracz1.GenerujStatek(1);
	 gracz1.GenerujStatek(2);
	 gracz1.GenerujStatek(2);
	 gracz1.GenerujStatek(2);
	 gracz1.GenerujStatek(3);
	 gracz1.GenerujStatek(3);
	 gracz1.GenerujStatek(4);
	
	 gracz2.GenerujStatek(1);
	 gracz2.GenerujStatek(1);
	 gracz2.GenerujStatek(1);
	 gracz2.GenerujStatek(1);
	 gracz2.GenerujStatek(2);
	 gracz2.GenerujStatek(2);
	 gracz2.GenerujStatek(2);
	 gracz2.GenerujStatek(3);
	 gracz2.GenerujStatek(3);
	 gracz2.GenerujStatek(4);

	 

	while (gracz1.raportuj() == 0 && gracz2.raportuj() == 0)
	{
		cout << "RUCH 1 GRACZA" << endl << "Podaj wspolrzedne wystrzalu (x,y) " << endl;
		gracz2.DrukujPlansze();
		do
		{
			scanf("%d,%d", &x, &y);
			if (x == 13 && y == 13) { x = (rand() % 10); y = (rand() % 10); }
		} while (x > 9 || x < 0 || y>9 || y < 0);
		system("cls");
		cout << "RUCH 1 GRACZA" << endl << "(" << x << "," << y << ")" << endl;
		gracz2.Strzel(x, y);
		cout << "Zakoncz ture" << endl;
		_getch();
		system("cls");
		cout << "RUCH 2 GRACZA" << endl << "Podaj wspolrzedne wystrzalu (x,y) " << endl;
		gracz1.DrukujPlansze();
		do
		{
			scanf("%d,%d", &x, &y);
			if (x == 13 && y == 13) { x = (rand() % 10); y = (rand() % 10); }
		} while (x > 9 || x < 0 || y>9 || y < 0);
		system("cls");
		cout << "RUCH 2 GRACZA" << endl << "(" << x << "," << y << ")" << endl;
		gracz1.Strzel(x, y);
		cout << "Zakoncz ture" << endl;
		_getch();
		system("cls");

	}
	if (gracz2.raportuj() == 1) cout << "Zwyciezyl gracz 1" << endl;
	else cout << "Zwyciezyl gracz 2" << endl;
}