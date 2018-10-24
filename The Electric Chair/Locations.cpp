#include "pch.h"
#include "Locations.h"
#include "Game.h"
#include "Player.h"

void Locations::cellA() {
	Player l_player;
	Game l_game;
	bool l_cellA = true;
	do
	{
		cout << "Nu är du fast" << l_game.s_answer << "\n" << choice1 << choice2 << choice3 << "4. Inventory";
		cin >> answer;
		switch (answer)
		{
		case hairpin:
	
			l_player.pushBack(1);
			choice1 = "";
			if (if_choice1)
			{
				if_choice1 = false;
				cellCorridor();

			}
			else
			{

			}
			break;

		case harryPotter:
			l_player.pushBack(2);
			choice2 = "";
			if (if_choice2)
			{
				if_choice2 = false;
				cellCorridor();
			}
			else
			{

			}
			break;
		case nailfile:
			l_player.pushBack(3);
			choice3 = "";
			if (if_choice3)
			{
				if_choice3 = false;
				cellCorridor();
			}
			else
			{

			}
			break;
		case inventory:
			l_player.inventory();
			break;
		default:
			break;
		}
	} while (l_cellA);
}

void Locations::cellCorridor() {
	cout << "Cell corridor\n";
	cout << "Du flydde din cell, vad gör du nu?";
	Game l_game;
	l_game.menu();
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
