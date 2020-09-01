#include "Player.h"
#include "Mast.h"
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
	string answer;
	Player Player1;
	Player Player2;


	cout << "Launch game in debug mode? (all ships will be visible) " << endl;
	cout << "Type Yes or No" << endl;
	cin >> answer;
	if (answer == "Yes") {
		Player1.bShowShips = true;
		Player2.bShowShips = true;
	}
	system("cls");

	Player1.GenerateShip(1);
	Player1.GenerateShip(1);
	Player1.GenerateShip(1);
	Player1.GenerateShip(1);
	Player1.GenerateShip(2);
	Player1.GenerateShip(2);
	Player1.GenerateShip(2);
	Player1.GenerateShip(3);
	Player1.GenerateShip(3);
	Player1.GenerateShip(4);

	Player2.GenerateShip(1);
	Player2.GenerateShip(1);
	Player2.GenerateShip(1);
	Player2.GenerateShip(1);
	Player2.GenerateShip(2);
	Player2.GenerateShip(2);
	Player2.GenerateShip(2);
	Player2.GenerateShip(3);
	Player2.GenerateShip(3);
	Player2.GenerateShip(4);



	while (Player1.Report() == 0 && Player2.Report() == 0)
	{
		cout << "PLAYER 1 TURN" << endl << "Give coordinates (x,y) " << endl;
		Player2.PrintBoard();
		do
		{
			scanf_s("%d,%d", &x, &y);
			if (x == 13 && y == 13) { x = (rand() % 10); y = (rand() % 10); }
		} while (x > 9 || x < 0 || y>9 || y < 0);
		system("cls");
		cout << "PLAYER 1 TURN" << endl << "(" << x << "," << y << ")" << endl;
		Player2.Shoot(x, y);
		cout << "End turn" << endl;
		_getch();
		system("cls");
		cout << "PLAYER 2 TURN" << endl << "Give coordinates (x,y) " << endl;
		Player1.PrintBoard();
		do
		{
			scanf_s("%d,%d", &x, &y);
			if (x == 13 && y == 13) { x = (rand() % 10); y = (rand() % 10); }
		} while (x > 9 || x < 0 || y>9 || y < 0);
		system("cls");
		cout << "PLAYER 2 TURN" << endl << "(" << x << "," << y << ")" << endl;
		Player1.Shoot(x, y);
		cout << "End turn" << endl;
		_getch();
		system("cls");

	}
	if (Player2.Report() == 1) cout << "PLAYER 1 HAS WON!" << endl;
	else cout << "PLAYER 2 HAS WON!" << endl;

	return 0;
}