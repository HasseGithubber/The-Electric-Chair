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

	l_player.ClearExtraItems();
	if (if_choice1 == false && if_choice2 == false && if_choice3 == false) // Så du dör.. inte färdig.
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
			cout << "You are stuck in your cell " << l_game.s_name << endl << choice1 << choice2 << choice3 << "i. Inventory";  // endl för att tömma buffern
			cin >> answer;
			switch (answer[0])
			{
			case e_hairpin:
				b_cellA = false;
				l_player.pushBack(1);
				choice1 = "";
				if (if_choice1) {
					if_choice1 = false;
					cout << "You escaped from your cell " << endl;
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
					cout << "You escaped from your cell" << endl;
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
					cout << "You escaped from your cell" << endl;
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
	
	while (b_cellCorr)
	{
		cout << " What do you do now? " << endl;
		cout << " 3. Go to Cell B || 4. Go to securityroom || i. Inventory";
		answer = "";
		cin >> answer;
		if (answer[0] == '3' || answer[0] == '4')
		{
			b_cellCorr = false;
		}
		else if (answer[0] == 'i')
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
	cout << "Cell B you now are in" << endl;  // endl för att tömma buffern
	while (b_cellB)
	{
		cout << "You are talkning to your dealer, \n 1. Take scissors || 2. Take bazooka || 3. Take Ak47 || 4. Take Kpist || i. Inventory";
		answer = "";
		cin >> answer;
		switch (answer[0])
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
			cout << wrongAnsw << endl;
			break;
		}
		if (answer[0] == '1') // valet för att lämna rummet, tadaaaaaaaa
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
			cout << "Do you take the unifrom?\n y. Yes || n. No";
			answer = "";
			cin >> answer;
			switch (answer[0])
			{
			case yes:
			{
				b_secroom = false;
				l_player.ItemBloodyUniform();// ger spelaren en blodig uniform
				b_bloodyUniform = true;
				cout << "You found some coins in the uniform.. wohoo" << endl;
				l_player.ItemCoins();
				b_coins = true; // Till inventory och valet i lockerrom
				coins = 8;  // Spelaren har nu 8 coins.
				break;
			}
			case no:
			{
				b_secroom = false;
				b_coins = false;
				break;
			}
			default:
				cout << wrongAnsw << endl; // "endl" Töm buffern efter potientiella mängder fel slag
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
	b_farCorr = true; // Kommer inte behövas om vi inte kommer tillbaka hit
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
	cout << "You find yourself in the holy fika room. Angels sing and the room table has some strange items and a (pay maybe?)telephone sits on the wall." << endl; // lägg till text som introducerar aspekter ur val nedanför
	while (b_fikaroom)
	{
		cout << "What do you want to do?\n 1. Walk to the table || 2. Use the telephone || 8. Locker Room || 5. Main Corridor || i. Check inventory\n";
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
		cout << "What do you do?\n 1. Eat a bulle || 2. Throw the dice || 7. Check the fika room || i. Check inventory\n";
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
		cout << "You eat a bulle.\n"; // LÄgg in funktion
		i_bullen = l_game.bulle();
		if (i_bullen == 1)
		{
			cout << "The bulle was delicious and you feel refreshed, mmmm.\n";
		}
		else
		{
			cout << "The bulle was moldy on the inside making you grasp your stomach, you lie on the floor while drifting into unconsciousness.";
			l_game.pause(700, 5);
			cout << "You wake up feeling a familiar ground, you check your surroundings and notice that you are in a bed and back in your cell";
			l_game.pause(700, 5);
			cout << "Bummer...";
			cellA();
		}
		break;
	case e_dice:
		cout << "You threw a dice\n"; // Lägg in funktion
		i_dice = l_game.dice();
		if (i_dice >= 4)
		{
			cout << "You rolled a SUCCES";
		}
		else
		{
			cout << "You rolled a critical fail'ish, you feel the air around you starting to push and squeeze in and around you.\n";
			l_game.pause(700, 4);
			cout << "The room makes a humming sound as you see it warp far away from you in every direction. The table you were standing next to draws away and the clock on the wall spins rapidly backwards, but you don't feel like your moving.\n";
			Sleep(2000);
			cout << "Suddenly the walls rush back, the room starts collapsing towards you with a loud noise. You duck down grasping and covering yourself as hard as you can before the inevitable end.\n";
			l_game.pause(700, 5);
			cout << "Everything stops, all you can hear is a familiar clock ticking. You're back in your cell but you've teleported back in time";
			Sleep(5000);
			cout << "You noticed you've lost everything you had on you except what you started with. Bummer...";
			cellA();
			
		}
		break;
	case e_fikaroom:
		fikaroom();
		break;
	}
	fikaroom(); // Händer efter bulle eller dice lyckade utkomster.
}

void Locations::telephone() {
	b_telephone = true;
	cout << "You take the telephone to your head and hear the ringtone." << endl;
	if (b_coins == true)
	{
		while (b_telephone)
		{
			if (b_coins == true)
			{
				coins -= 1;
				if (coins == 0)
				{
					b_coins = false;
				}
				answer = "";
				cout << "What do you do?\n 1. Call your mother || 2. Call the developers " << teleBoss << "7. Go back to the fika room"; // "|| i. Check inventory\n";
				cin >> answer;
				switch (answer[0])
				{
				case e_mother:
					b_telephone = false;
					break;
				case e_developers:
					b_telephone = false;
					break;
				case e_boss:
					if (if_teleBoss)
					{
						b_telephone = false;
					}
					else
					{
						cout << "Some old guy answered the phone, but you hung up on him.\n";
					}
					break;
				case e_fikaroom:
					b_telephone = false;
					break;
				//case e_inventory:  // **!! Om inventory ska finnas måste alla telefon val för sig minska coins med 1.
				//	l_player.inventory();
				//	break;
				default:
					cout << "You typed a number, but no one answered. Try again" << endl;
					break;
				}
			}
			else
			{
				b_telephone = false;
				cout << "You are out of coins, you can't make a call.\n";
			}
		} // Slut på while loopen
		switch (answer[0])
		{
		case e_mother:
			callMother();
			break;
		case e_developers:
			callDevelopers();
			break;
		case e_boss:
			callBoss();
			break;
		case e_fikaroom:
			fikaroom();
			break;
		default:
			break;
		}
	}
	else
	{
		cout << "You are out of coins, you can't make a call.\n";
	}
	fikaroom();

}

void Locations::callMother() {
	b_callMother = true;
	cout << "Your mother answers the phone." << endl;
	while (b_callMother)
	{
		cout << "What do you want to say to your mother?\n 1. Ask her for money || 2. Tell her she's pretty || 3. Congratulate her on her birthday || h. Hang up the phone\n";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case e_money:
			cout << "You're not getting any money from me until you've become good man, like that's ever gonna happen.\n";
			break;
		case e_pretty:
			cout << "Well then you're certianly not my child, cause you're but ugly.\n";
			break;
		case e_birthday:
			cout << "You're only 3 years late, dumbass!\n";
			break;
		case e_hangup:
			b_callMother = false;
			break;
		default:
			cout << "Did you wanna say something or are you just wasting my time!?" << endl;
			break;
		}
	}
	telephone();
}

void Locations::callDevelopers() {
	b_callDevelopers = true;
	cout << "Linda & Hasse answer the phone from their office, grupprum 3." << endl;
	while (b_callMother)
	{
		cout << "What do you want to say?\n 1. You guys suck || 2. Your guys are fantastic || 3. I need help! || h. Hang up the phone\n";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case e_suck:
			cout << "Wow, you've got some balls. You're the right person for this electric chair\n";
			break;
		case e_fantastic:
			cout << "Awwh, thanks.\n";
			break;
		case e_help:
			cout << "Dumbass!\n";
			break;
		case e_hangup:
			b_callDevelopers = false;
			break;
		default:
			cout << "Blubb?" << endl;
			break;
		}
	}
	telephone();
}

void Locations::callBoss() {
	b_callBoss = true;
	cout << "Yes?, what is it?" << endl;
	while (b_callBoss)
	{
		seller = l_game.randSeller();
		cout << "What do you want to say?\n 1. Hi this is " << l_game.s_name << ". || 2. This is the hospital calling, it's about your wife. || 3. Hi! || h. Hang up the phone\n";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case :
			cout << "What?! How are you calling from the fika room?!... \"guards!..\"..click.\n";
			break;
		case :
			cout << "\n"; 
			break;
		case :
			cout << "\n";
			break;
		case e_hangup:
			b_callBoss = false;
			break;
		default:
			cout << "" << endl;
			break;
		}
	}
	telephone();
}

void Locations::lockerroom() {

	b_lockerroom = true;
	cout << "You are now in the lockerroom" << endl;
	while (b_lockerroom)
	{
		cout << "You see a washing machine and a bunch of lockers " << endl;
		cout << "1. use washing machine || 2. open a locker || 3. Back to the main corridor || i. Inventory ";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case wash:
		{
			if (b_bloodyUniform == true || b_cleanUniform == true ) // om man har en uniform, ren/blodig
			{ 
				if (coins > 0)
				{
					cout << "That cost you one coin! Mmmmm .. your clothes smell gooood, they are now clean" << endl;
					l_player.changeUniform(); // ändrar uniform till ren
					b_cleanUniform = true;
					coins = coins - 1;
					if (coins = 0)
					{
						b_coins = false;
					}
				}
				else
					cout << "you are out of coins.." << endl;
			}
			else
			{
				if (coins > 0)
				{ 
				cout << "You put a coin in the maschine.. ";
				cout << "Your prisonscrubbs smell like flowers..mmm" << endl; // Om man inte har en uniform alls
				coins = coins - 1;
				if (coins = 0)
				{
					b_coins = false; }
				}
				else
				cout << "you are out of coins.." << endl;
			}
			break;
		}

		case open:
		{
			if (b_coins == true || (b_bloodyUniform == false && b_cleanUniform == false)) // Kollar om du redan har coins, du får inte se coins
			{
				choiceCoins = " ";
			}
			else if (b_coins == false && (b_bloodyUniform == true || b_cleanUniform == true)) // Har du inga, du får valet
			{
				choiceCoins = "|| 3. some coins";
			}
			cout << "In the locker you see a bunch of things, do you want to take something?\n 1. A clean uniform || 2. stinky banana peel "  << choiceCoins;
			answer = "";
			cin >> answer;
			switch (answer[0])
			{
			case '1':
			{
				cout << "Nice choice, are you a guard at this prison?! you sure look like one.. " << endl;
				if (b_bloodyUniform == true) // Om man har en blodig uniform men tar en ren
				{
				l_player.changeUniform(); // byter ut den blodiga mot en ren
				b_cleanUniform = true;
				}
				else if (b_bloodyUniform == false && b_cleanUniform == false) // Om man inte har någon uniform och tar en ren
				{ 
				l_player.ItemCleanUniform();  // lägger in en ren uniform i inventory
				b_cleanUniform = true;
				}
				break;
			}
			case '2':
				cout << "Uuuhhhaaaa why would you want that?! stop taking junk, idiot." << endl;
				break;

			case '3':
				cout << "coins coins coins.. they always welcome" << endl;
				if (b_coins == false)
				{
					l_player.ItemCoins(); // Ger spelaren "some coins" i inventory OM dom inte redan hade coins.
					coins = coins + 2; // plussar på int coins.
					b_coins = true;
				}
				else
				{
					coins = coins + 2; // plussar på int coins.
				}
				break;

			default:
				cout << wrongAnsw << endl;
				break;
			}

			break;
		}
		case '3':
		{
			b_lockerroom = false; // avslutar loopen
			mainCorridor();			//Skickar tillbaka till korridoren
			break;
		}

		case e_inventory:
		{
			l_player.inventory();
			break;
		}

		default:
			cout << wrongAnsw << endl;


		}
	}
}

void Locations::mainEntrance() {
	if (b_bossAway)
	{
		l_game.victory();
	}
	if (b_bloodyUniform) // Placeholder
	{
		teleBoss = "|| 3. Call the boss ";
		if_teleBoss = true;
	}
}

void Locations::gameover() { // Inte färdig. flytta till location. Töm inventory..skicka till starta om.

	cout << "Du har inga fler chanser.. börja om? \n 1. Ja || 2. nej \n";
	l_player.clearVector();
	coins = 0;
}


Locations::Locations()
{
}

Locations::~Locations()
{
}
