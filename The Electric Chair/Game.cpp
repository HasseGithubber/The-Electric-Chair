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
		cout << "Menyn\n 1. start 2. exit\n";
		cin >> answer;
		switch (answer)
		{
		case startgame:
			menuloop = false;
			cout << endl;
			start();
			break;
		case exitgame:
			menuloop = false;
			return;
		default:
			break;
		}
	} while (true);
	return;
}

void Game::start() {
	//bool startloop = true;
	s_answer = "";
	cout << "What do you want to call you prisoner?\n";
	cin >> s_answer;
	//g_player.name = s_answer;
	cout << "Intro, prisoner name " << s_answer << ". What happens now? typ\n";
	locate.cellA();
}

void victory() {
	cout << "Du flydde den elektriska stolen!";
}


Game::Game()
{
}

Game::~Game()
{
}
