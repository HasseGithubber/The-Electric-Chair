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
	cout << "What do you want to call your prisoner?" << endl;
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

void Game::pause(int a, int b) { // Tar in ett värde a som bestämmer sleep time; ett värde b som bestämmer antal dots.
	for (int i = 0; i < b; i++)
	{
		Sleep(a);
		cout << ".";
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

int Game::randSeller() {
	return 
}


Game::Game()
{
}

Game::~Game()
{
}
