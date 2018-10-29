#include "pch.h"
#include "Game.h"
#include "Locations.h"
#include "Player.h"

Player g_player;
Locations locate;

void Game::intro() {
	menu();
	
}

void Game::menu() {
	bool menuloop = true;
	do
	{
		answer = "";
		cout << "Menu\n 1. Start || 2. Exit" << endl;
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


void Game::start() {
	answer = "";
	s_name = "";
	print("What do you want to call your prisoner?", 15);
	while (getline(cin, s_name))
	{
		if (s_name != "")
		{
			break;
		}
	}
	cout << "Intro, prisoner name " << s_name << ". What happens now? typ\n";
	locate.fillItems();
}

void Game::victory() {
	cout << s_name << " you escaped the electric chair!";
}

// Funktion vars uppgift är att skapa en paus i spelet. Den skriver ut ett antal "." där man också kan välja hastigheten
void Game::pause(int a, int b) {
	for (int i = 0; i < b; i++)
	{
		cout << ".";
		Sleep(a);
	}
	cout << endl;
}

// Funktion som skriver ut en string eller text en karaktär i taget med hastighets inställning.
void Game::print(string a, int b) {
	for (int i = 0; i < a.length(); i++)
	{
		cout << a[i];
		Sleep(b);
	}
	cout << endl;
}

int Game::bulle() {
	bulleOutcome = 0;
	bulleOutcome = rand() % 2 + 1;
	return bulleOutcome;
}

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
