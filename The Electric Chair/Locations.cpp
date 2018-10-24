#include "pch.h"
#include "Locations.h"
#include "Game.h"

enum locations
{
	cellA = 'a', cellCorridor = 'b', cellB = 'c', securityroom = 'd', mainCorridor = 'e',
	farCorridor = 'f', fikaroom = 'g', lockerroom = 'h', mainEntrance = 'i'
};

void Locations::cellA() {
	cout << "Nu är du fast\n 1, nål 2, fil 3, harrypotter bok";
	cin >> answer;
	switch (answer)
	{
	case '1':
		cellCorridor();
		break;
	case '2':
		cellCorridor();
		break;
	case '3':
		cellCorridor();
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
