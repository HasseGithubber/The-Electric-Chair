#include "pch.h"
#include "Game.h"
#include "Locations.h"
#include "Player.h"
#include <conio.h>

Player g_player;
Locations locate;

// Introduktion till spelet. Titel och kort förklaring av vad det är.
void Game::intro() {
	system("CLS");
	print("  You are a prisoner on death row. Wrongly accused you will do anything to escape the...", 35);
	pause(500, 5);
	locate.menu("  ***~~      ~~ELECTRIC CHAIR~~        ~~***", 6);
	print("\n\n  This is a text adventure game were your goal is to escape the prison.\n  To accomplish this you have to explore, find items and figure your way out\n  to freedom by choosing an option in each area.\n\n  You only have three chances to escape so make it good or try again from the beginning.\n\n", 35);
	menu();
}

// Spelets huvud meny
void Game::menu() {
	bool menuloop = true;
	do
	{
		answer = "";
		cout << "  Main menu:\n  1. Start || 2. Exit" << endl;
		cin >> answer;
		switch(answer[0])
		{
		case startgame:
			menuloop = false;
			cout << endl;
			locate.start();
			break;
		case exitgame:
			menuloop = false;
			break;
		default:
			print(wrongAnsw, 15);
			break;
		}
	} while (menuloop);
}

// Winner winner, we ain't getting thinner.
void Game::victory() {
	cout << "\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	print("         *              *                 *    ", 4);
	print("            *     *        *           *      *", 4);
	print("       *                     *            *", 4);
	cout << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	print("        *              **  *  **         *         * ", 4);
	print("     *                 ** *** **            *  ", 4);
	print("        *      *       *********                 *", 4);
	print("           *           *********           *        *", 4);
	cout << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	print("      *      *                   *         * ", 4);
	print("          *          *       *          *    *      *", 4);
	print("       *       *        *             *                  ", 4);
	print("                    *                         * ", 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl;
	print("        You escaped the electric chair!", 35);
	cout << "\n\n\n";

	system("pause"); // väntar på ett enter innan den går vidare
	intro(); // Skickar till introt igen.


}

// Funktion vars uppgift är att skapa en paus i spelet. Den skriver ut ett antal "." där man också kan välja hastigheten
void Game::pause(int a, int b) {
	cout << "  ";
	for (int i = 0; i < b; i++)
	{
		cout << ".";
		Sleep(a);
	}
	cout << endl;
}

// Funktion som skriver ut en string eller text en karaktär i taget med hastighets inställning.
// Man kan avbryta utskriften och få allting på en gång om man trycker på en tangent.
void Game::print(string a, int b) {
	int x = 0;
	bool blub = false;
	for (int i = 0; i < a.length(); i++)
	{
		cout << a[i];
		Sleep(b);
		if (_kbhit())
		{
			blub = true;
			x = i + 1;
			break;
		}
	}
	if (blub)
	{
		for (x; x < a.length(); x++)
		{
			cout << a[x];
		}
	}
	cout << endl;
}

// Random nummer generator för bull eventet
int Game::bulle() {
	bulleOutcome = 0;
	bulleOutcome = rand() % 2 + 1;
	return bulleOutcome;
}

// Random nummer generator för dice eventet
int Game::dice() {
	diceResult = 0;
	diceResult = rand() % 6 + 1;
	return diceResult;
}

Game::Game()
{
}

Game::~Game()
{
}
