#include "pch.h"
#include "Game.h"
#include "Locations.h"


void Game::intro() {
	menu();
}

void Game::menu() {
	char svar;
	cin >> svar;
	switch (svar)
	{
	case '1':
		cout << endl;

	default:
		break;
	}
	start();
}

void Game::start() {
	Locations locate;
	locate.cellA();

}

void end() {

}


Game::Game()
{
}

Game::~Game()
{
}
