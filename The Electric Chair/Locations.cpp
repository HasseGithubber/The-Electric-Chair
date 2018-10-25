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
		b_cellA = false;
	}
	else
	{ 
	b_cellA = true;
	while (b_cellA)
	{
		answer = NULL;
		cout << "Nu är du fast" << l_game.s_answer << endl << choice1 << choice2 << choice3 << "0. Inventory";  // endl för att tömma buffern
		cin >> answer;
		switch (answer)
		{
		case e_hairpin:
			b_cellA = false;
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

		case e_harryPotter:
			b_cellA = false;
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
		case e_nailfile:
			b_cellA = false;
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
		case e_inventory:
			l_player.inventory();
			break;
		default:
			break;
		}
	}
	}
}

void Locations::cellCorridor() {
	b_cellCorr = true;
	cout << "Cell corridor" << endl; // endl för att tömma buffern
	cout << "Du flydde din cell, vad gör du nu? \n 3. Gå till Cell B || 4. Gå till säkerhetssluss || 0 Inventory";
	while (b_cellCorr)
	{
		answer = NULL;
		cin >> answer;
		if (answer == '3' || answer == '4')
		{
			b_cellCorr = false;
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
	b_cellB = true;
	cout << "Cell B you now are in" << endl;  // endl för att tömma buffern
	while (b_cellB)
	{
		cout << "Du pratar med din langare, \n 1. Ta sax || 2. Ta bazooka || 3. Ak47 || 4. Ta Kpist || 0. Inventory";
		answer = NULL;
		cin >> answer;
		switch (answer)
		{
		case e_scissor:
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
		case e_bazooka:
			cout << "Its too big, cant get it through the metal bars.. try someting else";
			break;
		case e_ak47:
			cout << "It's out of ammo, try someting else";
			break;
		case e_kpist:
			cout << "It's rusty as hell, it wont work, try someting else";
			break;
		case e_inventory:
			l_player.inventory();
			break;
		default:
			cout << "Skriv rätt!" << endl;
			break;
		}
		if (answer == '1') // valet för att lämna rummet, tadaaaaaaaa
		{
			b_cellB = false;
		}
	}
	cellCorridor();
}

void Locations::securityroom() {
	b_secroom = true;
	cout << "Security Room - Danger" << endl;
	if (b_scissors == true)
	{
		cout << "You lunge towards the guard and stab him.\n The body lies motionless on the floor, you think to yourself that his uniform might come in handy.\n";
		while (b_secroom)
		{
			cout << "Do you take the unifrom?\n 1. Yes || 2. No";
			answer = NULL;
			cin >> answer;
			switch (answer)
			{
			case yes:
				b_secroom = false;
				// Give item
				b_dirtyUniform = true;
				break;
			case no:
				b_secroom = false;
				break;
			default:
				cout << "That is not an option, try again" << endl; // "endl" Töm buffern efter potientiella mängder fel slag
				break;
			}
		}
	}
	else
	{
		cout << "The security guard quickly notices you and puts you back into your cell!!";
		cellA();
	}
	mainCorridor();

}

void Locations::mainCorridor() { // Fixa så att valet till far corridor bara finns första gången
	b_mainCorr = true;
	cout << "The main corridor you are in" << endl;
	cout << "You hear a few voices coming from the main entrance to the right, to the left the corridor just keeps going";
	while (b_mainCorr)
	{
		cout << "Where do you want to go?\n 6. Continue the corridor || 9. Main entrance";
		answer = NULL;
		cin >> answer;
		switch (answer)
		{
		case e_farCorridor:
			b_mainCorr = false;
		case e_mainEntrance:
			b_mainCorr = false;
		default:
			cout << "That is not an option, try again" << endl;
			break;
		}
	}
	if (answer == '6')
	{
		farCorridor();
	}
	else
	{
		mainEntrance();
	}
}

void Locations::farCorridor() {
	b_farCorr = true; // Kommer inte behövas om vi inte kommer tillbaka hit
	cout << "The corridor you continue to walk." << endl;
	cout << "A fika room and locker room you find doors to.";
	while (b_farCorr)
	{
		cout << "Where do you want to go?\n 7. Fika Room || 8. Locker Room";
		answer = NULL;
		cin >> answer;
		switch (answer)
		{
		case e_fikaroom:
			b_farCorr = false;
			break;
		case e_lockerroom:
			b_farCorr = false;
			break;
		default:
			cout << "That is not an option, try again" << endl;
			break;
		}
	}
	if (answer == '7')
	{
		fikaroom();
	}
	else
	{
		lockerroom();
	}

}

void Locations::fikaroom() {
	b_fikaroom = true;
	cout << "The corridor you continue to walk." << endl;
	cout << "A fika room and locker room you find doors to.";

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
