#include "pch.h"
#include "Locations.h"
#include "Game.h"
#include "Player.h"

Game l_game;
Player l_player;

void Locations::fillItems() // Fyller inventory fr�n b�rjan.
{

	l_player.startInventory();
	cellA();

}

void Locations::cellA() {


	if (if_choice1 == false && if_choice2 == false && if_choice3 == false) // S� du d�r.. inte f�rdig.
	{
		gameover(); // fixa
		b_cellA = false;
	}
	else
	{ 
	b_cellA = true;
	while (b_cellA)
	{
		answer = "";
		cout << "Nu �r du fast" << l_game.s_answer << endl << choice1 << choice2 << choice3 << "0. Inventory";  // endl f�r att t�mma buffern
		cin >> answer;
		switch (answer[0])
		{
		case e_hairpin:
			b_cellA = false;
			l_player.pushBack(1);
			choice1 = "";
			if (if_choice1) {
				if_choice1 = false;
				cout << "Du flydde din cell " << endl;
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
				cout << "Du flydde din cell" << endl;
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
				cout << "Du flydde din cell" << endl;
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
	cout << "Cell corridor" << endl; // endl f�r att t�mma buffern
	
	while (b_cellCorr)
	{
		cout << " vad g�r du nu? " << endl;
		cout << " 3. G� till Cell B || 4. G� till s�kerhetssluss || 0 Inventory";
		answer = "";
		cin >> answer;
		if (answer[0] == '3' || answer[0] == '4')
		{
			b_cellCorr = false;
		}
		else if (answer[0] == '0')
		{
			l_player.inventory();
			cout << endl;
		}
		else
		{
			cout << wrongAnsw << endl;
		}
	}
	switch (answer[0])
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
}

void Locations::cellB() {
	b_cellB = true;
	cout << "Cell B you now are in" << endl;  // endl f�r att t�mma buffern
	while (b_cellB)
	{
		cout << "Du pratar med din langare, \n 1. Ta sax || 2. Ta bazooka || 3. Ak47 || 4. Ta Kpist || 0. Inventory";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case e_scissor:
			if (b_scissors == true) // S� att man inte ska kunna ta flera saxar.
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
			cout << "Skriv r�tt!" << endl;
			break;
		}
		if (answer[0] == '1') // valet f�r att l�mna rummet, tadaaaaaaaa
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
			answer = "";
			cin >> answer;
			switch (answer[0])
			{
			case yes:
				b_secroom = false;
				l_player.ItemBloodyUniform();// ger spelaren en blodig uniform
				b_bloodyUniform = true;
				cout << "You found some coins in the uniform.. wohoo" << endl;
				l_player.ItemCoins();
				coins = 5;  // Spelaren har nu 5 coins.
				break;
			case no:
				b_secroom = false;
				break;
			default:
				cout << wrongAnsw << endl; // "endl" T�m buffern efter potientiella m�ngder fel slag
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

void Locations::mainCorridor() { // Fixa s� att valet till far corridor bara finns f�rsta g�ngen
	b_mainCorr = true;
	cout << "The main corridor you are in" << endl;
	cout << "You hear a few voices coming from the main entrance to the right, to the left the corridor just keeps going";
	while (b_mainCorr)
	{
		cout << "Where do you want to go?\n 6. Continue the corridor || 9. Main entrance || 0. Inventory";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case e_farCorridor:
			b_mainCorr = false;
			break;
		case e_mainEntrance:
			b_mainCorr = false;
			break;
		case e_inventory:
			l_player.inventory();
			break;
		default:
			cout << wrongAnsw << endl;
			break;
		}
	}
	if (answer[0] == '6')
	{
		farCorridor();
	}
	else
	{
		mainEntrance();
	}
}

void Locations::farCorridor() {
	b_farCorr = true; // Kommer inte beh�vas om vi inte kommer tillbaka hit
	cout << "The corridor you continue to walk." << endl;
	cout << "A fika room and locker room you find doors to.";
	while (b_farCorr)
	{
		cout << "Where do you want to go?\n 7. Fika Room || 8. Locker Room || 0. Inventory";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case e_fikaroom:
			b_farCorr = false;
			break;
		case e_lockerroom:
			b_farCorr = false;
			break;
		case e_inventory:
			l_player.inventory();
			break;
		default:
			cout << wrongAnsw << endl;
			break;
		}
	}
	if (answer[0] == '7')
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
	cout << "You find yourself in the holy fika room. Angels sing and the room table has some strange items and a (pay maybe?)telephone sits on the wall." << endl;
	while (b_fikaroom)
	{
		cout << "What do you want to do?\n 1. Walk to the table || 2. Use the telephone || 8. Locker Room || 5. Main Corridor || 0. Check inventory\n";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case e_fikatable:
			b_fikaroom = false;
			break;
		case e_telephone:
			b_fikaroom = false;
			break;
		case e_lockerroom:
			b_fikaroom = false;
			break;
		case e_mainCorridor:
			b_fikaroom = false;
			break;
		case e_inventory:
			l_player.inventory();
			break;
		default:
			cout << wrongAnsw << endl;
			break;
		}
	}
	switch (answer[0])
	{
	case e_fikatable:
		fikatable();
		break;
	case e_telephone:
		telephone();
		break;
	case e_lockerroom:
		lockerroom();
		break;
	case e_mainCorridor:
		mainCorridor();
		break;
	}
}

void Locations::fikatable() {
	b_fikatable = true;
	cout << "You see a bowl full of bullar and a dice on the table" << endl;
	while (b_fikatable)
	{
		answer = "";
		cout << "What do you do?\n 1. Eat a bulle || 2. Throw the dice || 7. Fika Room || 0. Check inventory\n";
		cin >> answer;
		switch (answer[0])
		{
		case e_bulle:
			b_fikatable = false;
			break;
		case e_dice:
			b_fikatable = false;
			break;
		case e_fikaroom:
			b_fikatable = false;
			break;
		case e_inventory:
			l_player.inventory();
			break;
		default:
			cout << wrongAnsw << endl;
			break;
		}
	}
	switch (answer[0])
	{
	case e_bulle:
		cout << "You eat a bulle"; // L�gg in funktion
		break;
	case e_dice:
		cout << "You threw a dice"; // L�gg in funktion
		break;
	case e_fikaroom:
		fikaroom();
		break;
	}
	fikaroom();
}

void Locations::telephone() {
	b_telephone = true;
	cout << "You take the telephone to your head and hear the ringtone." << endl;
	while (b_telephone)
	{
		answer = "";
		cout << "What do you do?\n 1. Call your mother || 2. Call the developers " << teleBoss << "|| 0. Check inventory\n";
		cin >> answer;
		switch (answer[0])
		{
		case e_mother:
			b_telephone = false;
			break;
		case e_developers:
			b_telephone = false;
			break;
		case e_boss:	// L�gg till fler val att s�ga till bossen
			if (if_teleBoss)
			{
				b_telephone = false;
				cout << "fhdsjkalfsd";
			}
			else
			{
				"Some old guy answered the phone, but you hung up in him.\n";
			}
			break;
		case e_inventory:
			l_player.inventory();
			break;
		default:
			cout << "You typed a number, but no one answered. Try again" << endl;
			break;
		}
	}
	switch (switch_on)
	{
	default:
		break;
	}
}

void Locations::callBoss() {
	b_callBoss = true;
	cout << "OMG it's the boss, what do you say?"; // you call is going through
	while (b_callBoss)
	{
		answer = "";
	}
}

void Locations::lockerroom() {

	b_lockerroom = true;
	cout << "You are now in the lockerroom" << endl;
	while (b_lockerroom)
	{
		cout << "You see a washing machine and and a bunch of lockers " << endl;
		cout << "1. use washing machine || 2. open a locker || 0. Inventory";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case wash:
		{
			b_lockerroom = false;
			if (b_bloodyUniform == true || b_cleanUniform == true )
			{ 
			cout << "Mmmmm .. your clothes smell gooood, they are now clean" << endl;
			l_player.changeUniform();
			b_cleanUniform = true;
			}
			else
			{
				cout << "Your prisonscrubbs smell like flowers.. mmm" << endl;
			}
			break;
		}

		case open:
		{
			b_lockerroom = false;
			cout << "In the locker you see a bunch of things, do you want to take something?\n 1. A clean uniform || 2. some coins ";
			answer = "";
			cin >> answer;
			switch (answer[0])
			{
			case '1':
				l_player.ItemCleanUniform();
				b_cleanUniform = true;
				break;

			case '2':
				//Plussa p� int coins
				//fler coins i inventory?
				break;

			default:
				cout << "Byt ut mig mot konstant";
				break;
			}

			break;
		}
		case e_inventory:
		{
			l_player.inventory();
			break;
		}

		default:
			cout << "�ndra mig till konstant";


		}
	}
}

void Locations::mainEntrance() {
	if (b_dirtyUniform) // Placeholder
	{
		teleBoss = "|| 3. Call the boss ";
		if_teleBoss = true;
	}
}

void Locations::gameover() { // Inte f�rdig. flytta till location. T�m inventory..skicka till starta om.

	cout << "Du har inga fler chanser.. b�rja om? \n 1. Ja || 2. nej \n";
	l_player.clearVector();
	coins = 0;
}


Locations::Locations()
{
}

Locations::~Locations()
{
}
