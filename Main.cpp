#include "Player.h"
#include "Mast.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <cstdlib>
#include <string>

using namespace std;



int* get_move()
{
	string sx;
	int x = 0;
	string sy;
	int y= 0;
	int move[2];

	try
	{
		do
		{
			cout << "Give X: ";
			cin >> sx;
			cout << "Give y: ";
			cin >> sy;

			if (sx == "r" && sy == "r")
			{
				cout << "gowno";
				x = (rand() % 10);
				y = (rand() % 10);
			}
			else
			{
				x = std::stoi(sx);
				y = std::stoi(sy);
			}
			move[0] = x;
			move[1] = y;
		} while (x > 9 || x < 0 || y>9 || y < 0);
		return move;

	}
	catch (std::invalid_argument const& e)
	{
		cout << "Bad input";
	}
	catch (std::out_of_range const& e)
	{
		cout << "Bad input";
	}
}




int main()
{
	srand(time(NULL));
	int x;
	int y;
	int* move;
	string answer;
	Player Player1;
	Player Player2;


	cout << "Launch game in debug mode? (all ships will be visible) " << endl;
	cout << "Type Yes or No" << endl;
	cin >> answer;
	if (answer == "Yes") {
		Player1.set_bShowShips(true);
		Player2.set_bShowShips(true);
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
		move = get_move();
		x = *move;
		y = *(move + 1);
		system("cls");
		cout << "PLAYER 1 TURN" << endl << "(" << x << "," << y << ")" << endl;
		Player2.Shoot(x, y);
		cout << "End turn" << endl;
		_getch();
		system("cls");
		cout << "PLAYER 2 TURN" << endl << "Give coordinates (x,y) " << endl;
		Player1.PrintBoard();
		move = get_move();
		x = *move;
		y = *(move + 1);
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