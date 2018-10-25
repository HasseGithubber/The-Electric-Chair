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
			break;
		default:
			break;
		}
	} while (menuloop);
}

void Game::start() {
	//bool startloop = true;
	s_answer = "";
	cout << "What do you want to call your prisoner?\n";
	cin >> s_answer;
	//g_player.name = s_answer;
	cout << "Intro, prisoner name " << s_answer << ". What happens now? typ\n";
	locate.fillItems();
}

void Game::victory() {
	cout << "Du flydde den elektriska stolen!";
}

void Game::gameover() { // Inte färdig. flytta till location. Töm inventory..skicka till starta om.
	
	cout << "Du har inga fler chanser.. börja om? \n 1. Ja || 2. nej \n";
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
