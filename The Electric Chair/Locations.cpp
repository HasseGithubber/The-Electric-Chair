#include "pch.h"
#include "Locations.h"

void Locations::cellA() {
	cout << "Nu �r du fast\n";
	char svar;
	cout << "1, n�l 2, fil 3, harrypotter bok";
	cin >> svar;
	switch (svar)
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
	cout << "Du flydde din cell, vad g�r du nu?";
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
