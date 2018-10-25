#include "pch.h"
#include "Locations.h"
#include "Game.h"
#include "Player.h"

Game l_game;
Player l_player;

void Locations::fillItems() // Fyller inventory från början.
{

	l_player.startInventory();
	cellA();

}

void Locations::cellA() {


	if (if_choice1 == false && if_choice2 == false && if_choice3 == false) // Så du dör.. inte färdig.
	{
		l_game.gameover(); // fixa
		bool cellA = false;
	}
	else
	{ 
	bool cellA = true;
	while (cellA)
	{
		answer = NULL;
		cout << "Nu är du fast" << l_game.s_answer << endl << choice1 << choice2 << choice3 << "0. Inventory";  // endl för att tömma buffern
		cin >> answer;
		switch (answer)
		{
		case hairpin:
			cellA = false;
			l_player.pushBack(1);
			choice1 = "";
			if (if_choice1) {
				if_choice1 = false;
				cellCorridor();
			}
			else {
				cout << "Your hairpin is broken. Use something else";
			}
			break;

		case harryPotter:
			cellA = false;
			l_player.pushBack(2);
			choice2 = "";
			if (if_choice2) {
				if_choice2 = false;
				cellCorridor();
			}
			else {
				cout << "Your Harry Potter book has been warped in space&time from the spell. Use something else";
			}
			break;
		case nailfile:
			cellA = false;
			l_player.pushBack(3);
			choice3 = "";
			if (if_choice3) {
				if_choice3 = false;
				cellCorridor();
			}
			else {
				cout << "Your nail-file is dull after all those years. Use something else";
			}
			break;
		case inventory:
			l_player.inventory();
			break;
		default:
			break;
		}
	}
	}
}

void Locations::cellCorridor() {
	bool cellCorridor = true;
	cout << "Cell corridor" << endl; // endl för att tömma buffern
	cout << "Du flydde din cell, vad gör du nu? \n 3. Gå till Cell B || 4. Gå till säkerhetssluss || 0 Inventory";
	while (cellCorridor)
	{
		answer = NULL;
		cin >> answer;
		if (answer == '3' || answer == '4')
		{
			cellCorridor = false;
		}
		else if (answer == '0')
		{
			l_player.inventory();
			cout << endl;
		}
		else
		{
			cout << "Skriv rätt!" << endl;
		}
	}
	switch (answer)
	{
	case e_cellB:
		cellB();
		break;
	case e_securityroom:
		securityroom();
		break;
	default:
		break;
	}
	//l_game.menu(); // **Detta orsakar att man måste i menyn välja exit två gånger**
}

void Locations::cellB() {
	bool cellB = true;
	cout << "Cell B you now are in" << endl;  // endl för att tömma buffern
	cout << "Du pratar med din langare, \n 1. Ta sax || 2. Ta bazooka || 3. Ak47 || 4. Ta Kpist || 0. Inventory";
	while (cellB)
	{
		answer = NULL;
		cin >> answer;
		switch (answer)
		{
		case scissor:
			if (b_scissors == true) // Så att man inte ska kunna ta flera saxar.
			{
				cout << "You already have one.. why take two?" << endl;
			}
			else
			{ 
			l_player.ItemScissors(); // Ger en sax i inventory
			b_scissors = true;
			cout << "Good choice! You now have a scissor in your inventory\n";
			}
			break;
		case bazooka:
			cout << "Its too big, cant get it through the metal bars.. try someting else";
			break;
		case ak47:
			cout << "It's out of ammo, try someting else";
			break;
		case kpist:
			cout << "It's rusty as hell, it wont work, try someting else";
			break;
		case inventory:
			l_player.inventory();
			break;
		default:
			cout << "Skriv rätt!" << endl;
			break;
		}
		if (answer == '1') // valet för att lämna rummet, tadaaaaaaaa
		{
			cellB = false;
		}
	}
	cellCorridor();
}

void Locations::securityroom() {

	// Ta bort denna sen!
	l_game.BackToCell();
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
