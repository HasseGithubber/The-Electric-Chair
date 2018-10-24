#include "pch.h"
#include "Game.h"
#include "Locations.h"
#include "Player.h"


void Game::intro() {
	menu();
}

void Game::menu() {
	cout << "Menyn\n 1. start 2. exit\n";
	cin >> answer;
	switch (answer)
	{
	case startgame:
		cout << endl;
		start();
		break;
	case exitgame:
		return;
	default:
		break;
	}
}

void Game::start() {
	Player player;
	Locations locate;
	while (true)
	{
		s_answer = "";
		cout << "What do you want to call you prisoner?\n";
		cin >> s_answer;
		player.name = s_answer;
		cout << "Intro, prisoner name " << player.name << ". What happens now? typ\n";
		locate.cellA();
	}
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
