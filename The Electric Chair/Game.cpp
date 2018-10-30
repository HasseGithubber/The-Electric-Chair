#include "pch.h"
#include "Game.h"
#include "Locations.h"
#include "Player.h"

Player g_player;
Locations locate;
Game g_game;

// Introduktion till spelet. Titel och kort f�rklaring av vad det �r.
void Game::intro() {


	print("  you are a prisoner on death row. wrongly accused you will do anything to escape the...", 35);
	cout << "  ";
	pause(500, 5);
	locate.menu(" ***~~      ~~electric chair~~        ~~***", 6);
	print("\n\n  this is a text adventure game were your goal is to escape the prison.\n  to accomplish this you have to explore, find items and figure your way out\n  to freedom by choosing an option in each area.\n\n  you only have three chances to escape so make it good or try again from the beginning.\n\n", 35);
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
			start();
			break;
		case exitgame:
			menuloop = false;
			break;
		default:
			break;
		}
	} while (menuloop);
}

// Spelet ber om input fr�n anv�ndaren att ge ett namn till sin karakt�r som sparas i game klassen.
void Game::start() {
	answer = "";
	g_game.s_name = "";
	print("  What is your name?", 15);
	while (getline(cin, g_game.s_name))
	{
		if (g_game.s_name != "")
		{
			break;
		}
	}
	print("\n  ==========================================================================\n\n  ", 1);
	print("Judge: ", 65);
	cout << "  -" << g_game.s_name << "!\n  ";
	pause(700, 3);
	print("  -You are charged for the murder of... some dude and hereby sentenced to death!\n", 65);
	cout << g_game.s_name;
	print("'s Mother:\n  -Now why did you go and do that huh?!\n  -Tell your father when you see him he can rott in hell!\n  .. *Mother walks out*...\n", 65);
	print("Prison Manager:\n  -Well luckily for you we have some malfunctions with the chair.\n  Something with the circuits on this old relic and it's all from china\n  or somewhere so it'll take sometime before we get it fixed.\n  So get comfortable, hahahaha.\n", 65);
	pause(700, 3);
	print("  4 years later...", 100);
	locate.fillItems();
}

// Winner winner, we ain't getting thinner.
void Game::victory() {

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


	intro(); // Skickar till introt igen.


}

// Funktion vars uppgift �r att skapa en paus i spelet. Den skriver ut ett antal "." d�r man ocks� kan v�lja hastigheten
void Game::pause(int a, int b) {
	for (int i = 0; i < b; i++)
	{
		cout << ".";
		Sleep(a);
	}
	cout << endl;
}

// Funktion som skriver ut en string eller text en karakt�r i taget med hastighets inst�llning.
void Game::print(string a, int b) {
	for (int i = 0; i < a.length(); i++)
	{
		cout << a[i];
		Sleep(b);
	}
	cout << endl;
}

// Random nummer generator f�r bull eventet
int Game::bulle() {
	bulleOutcome = 0;
	bulleOutcome = rand() % 2 + 1;
	return bulleOutcome;
}

// Random nummer generator f�r dice eventet
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
