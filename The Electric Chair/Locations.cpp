#include "pch.h"
#include "Locations.h"
#include "Game.h"



void Locations::cellA() {
	cout << "Nu är du fast\n 1, nål 2, fil 3, harrypotter bok";
	cin >> answer;
	switch (answer)
	{
	case '1':
		cellCorridor(); //l_player.pushBack(1);
		break;
	case '2':
		cellCorridor();//l_player.pushBack(2);
		break;
	case '3':
		cellCorridor(); //l_player.pushBack(3);
		break;
	default:
		break;
	}
}

void Locations::cellCorridor() {
	cout << "Cell corridor\n";
	cout << "Du flydde din cell, vad gör du nu?";
	Game l_game;
	l_game.menu();
	cin.get();
}

void Locations::cellB() {

}

void Locations::securityroom() {

}

void Locations::mainCorridor() {

}

void Locations::farCorridor() {

}

void Locations::fikaroom() {

}

void Locations::lockerroom() {

}

void Locations::mainEntrance() {

}


Locations::Locations()
{
}

Locations::~Locations()
{
}
