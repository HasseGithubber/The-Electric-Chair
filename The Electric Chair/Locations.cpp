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

void Locations::CleanItems()
{

	//rensa items
	l_player.ClearExtraItems();
	b_scissors = false;
	b_bloodyUniform = false;
	b_cleanUniform = false;
	b_coins = false;
	i_coins = 0;
	cellA();

}

void Locations::cellA() {


	if (if_choice1 == false && if_choice2 == false && if_choice3 == false) // Så du dör.. inte färdig.
	{
		gameover(); // Skickar till funktionen gameover
		
	}
	else
	{ 
		b_cellA = true;
		l_game.print("You are stuck in your cell, how do you plan to escape?", 35);
		while (b_cellA)
		{
			menu(titleCellA, 9); // skriver ut titeln med färg.
			answer = "";
			cout << s_choice1 << s_choice2 << s_choice3 << "i. Inventory";
			cin >> answer;
			switch (answer[0])
			{
			case e_hairpin:
				b_cellA = false;
				l_player.pushBack(1);
				s_choice1 = "";
				if (if_choice1) {
					if_choice1 = false;
					l_game.print("You escaped from your cell", 35);
					cellCorridor();
				}
				else {
					l_game.print("Your hairpin is broken. Use something else", 15);
				}
				break;

			case e_harryPotter:
				b_cellA = false;
				l_player.pushBack(2);
				s_choice2 = "";
				if (if_choice2) {
					if_choice2 = false;
					l_game.print("You escaped from your cell", 35);
					cellCorridor();
				}
				else {
					l_game.print("Your Harry Potter book has been warped in space&time from the spell. Use something else", 15);
				}
				break;
			case e_nailfile:
				b_cellA = false;
				l_player.pushBack(3);
				s_choice3 = "";
				if (if_choice3) {
					if_choice3 = false;
					l_game.print("You escaped from your cell", 35);
					cellCorridor();
				}
				else {
					l_game.print("Your nail-file is dull after all those years. Use something else", 15);
				}
				break;
			case e_inventory:
				l_player.inventory();
				break;
			default:
				l_game.print(wrongAnsw, 15);
				break;
			}
		} // Slut på while loop
	}
}

void Locations::cellCorridor() {
	b_cellCorr = true;

	menu(titleCellCorridor, 9); // skriver ut titeln med färg.
	
	while (b_cellCorr)
	{
		l_game.print("What do you do now? ", 35);
		cout << " 3. Go to Cell B || 4. Go to securityroom || i. Inventory";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case e_cellB:
			b_cellCorr = false;
			break;
		case e_securityroom:
			b_cellCorr = false;
			break;
		case e_inventory:
			l_player.inventory();
			break;
		default:
			l_game.print(wrongAnsw, 15);
			break;
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
	}
}

void Locations::cellB() {
	b_cellB = true;
	menu(titleCellB, 9); // skriver ut titeln med färg.
	cout << "Cell B you now are in" << endl;  // endl för att tömma buffern
	l_game.print("You are talking to your friendly neighbour, the weapons dealer. What do you want?\n", 35);
	while (b_cellB)
	{
		cout << "1. Take scissors || 2. Take bazooka || 3. Take Ak47 || 4. Take Kpist || i. Inventory";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case e_scissor:
			if (b_scissors == true) // Så att man inte ska kunna ta flera saxar.
			{
				l_game.print("You already have one.. why take two?", 15);
			}
			else
			{ 
			l_player.ItemScissors(); // Ger en sax i inventory
			b_scissors = true;
			l_game.print("Good choice! You now have a scissor in your inventory\n", 35);
			}
			break;
		case e_bazooka:
			l_game.print("I'm sorry its too big, I cant get it through the metal bars.. try something else", 25);
			break;
		case e_ak47:
			l_game.print("It's out of ammo, try something else", 25);
			break;
		case e_kpist:
			l_game.print("It's rusty as hell, it won't work, try something else", 25);
			break;
		case e_inventory:
			l_player.inventory();
			break;
		default:
			l_game.print(wrongAnsw, 15);
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
	menu(titleSecurityRoom, 4); // skriver ut titeln med färg.
	
	if (b_scissors == true)
	{
		l_game.print("You lunge towards the guard and stab him.\n The body lies motionless on the floor, you think to yourself that his uniform might come in handy.", 35);
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
				l_game.print("You found some coins in the uniform.. wohoo", 35);
				l_player.ItemCoins();
				b_coins = true; // Till inventory och valet i lockerrom
				i_coins = 8;  // Spelaren har nu 8 coins.
				break;
			}
			case no:
			{
				b_secroom = false;
				b_coins = false;
				break;
			}
			default:
				l_game.print(wrongAnsw, 15);
				break;
			}
		}
	}
	else
	{
		l_game.print("The security guard quickly notices you and puts you back into your cell!!", 35);
		CleanItems();
	}

	mainCorridor();
}

void Locations::mainCorridor() { // Fixa så att valet till far corridor bara finns första gången
	b_mainCorr = true;
	cout << "The main corridor you are in" << endl;
	l_game.print(s_farCorrIntro, 35);
	menu(titleMainCorridor, 4); // skriver ut titeln med färg.

	cout << "You hear a few voices coming from the main entrance to the right, to the left the corridor just keeps going";
	while (b_mainCorr)
	{
		cout << "Where do you want to go?\n" << s_fikaRoom << s_lockerRoom << s_farCorr << "|| 9. Main entrance || 0. Inventory\n";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case e_fikaroom:
			if (b_fikaRoomReveal)
			{
				b_mainCorr = false;
			}
			else
			{
				l_game.print("I see some doors over in the corridor but I don't know where it's leading.", 25);
			}
			break;
		case e_lockerroom:
			if (b_lockerRoomReveal)
			{
				b_mainCorr = false;
			}
			else
			{
				l_game.print("I see some doors over in the corridor but I don't know where it's leading.", 25);
			}
			break;
		case e_farCorridor:
			if (b_farCorrHide)
			{
				b_mainCorr = false;
				b_farCorrHide = false;
				b_fikaRoomReveal = true;
				b_lockerRoomReveal = true;
				s_farCorr = "";
				s_fikaRoom = "7. Go to fika room ";
				s_lockerRoom = "|| 8. Go to locker room ";
				s_farCorrIntro = "You hear some voices coming from the main entrance to the right, to the left is the fika room and locker room.\n";
			}
			else
			{
				l_game.print("That's the far corridor, but I allready knows what's there.", 25);
			}
			break;
		case e_mainEntrance:
			b_mainCorr = false;
			break;
		case e_inventory:
			l_player.inventory();
			break;
		default:
			l_game.print(wrongAnsw, 15);
			break;
		}
	}
	switch (answer[0])
	{
	case e_farCorridor:
		farCorridor();
		break;
	case e_fikaroom:
		fikaroom();
		break;
	case e_lockerroom:
		lockerroom();
		break;
	case e_mainEntrance:
		mainEntrance();
		break;
	default:
		cout << "**DEBUG - SOMETHING WENT WRONG**";
		break;
	}
}

void Locations::farCorridor() {
	b_farCorr = true; // Kommer inte behövas om vi inte kommer tillbaka hit
	cout << "The corridor you continue to walk." << endl;
	l_game.print("A fika room and locker room you find doors to.", 35);
	while (b_farCorr)
	{
		cout << "Where do you want to go?\n 7. Fika Room || 8. Locker Room || i. Inventory";
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
			l_game.print(wrongAnsw, 15);
			break;
		}
	}
	if (answer[0] == '7') {
		fikaroom();
	}
	else {
		lockerroom();
	}
}

void Locations::fikaroom() {
	b_fikaroom = true;
	l_game.print("You find yourself in the holy fika room. Angels sing and the room table has some strange items and a (pay maybe?)telephone sits on the wall.", 35); // lägg till text som introducerar aspekter ur val nedanför
	menu(titleFikaroom, 10); // skriver ut titeln med färg.
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
			l_game.print(wrongAnsw, 15);
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
	l_game.print("You see a bowl full of bullar and a dice on the table", 35);
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
		l_game.print("You eat a bulle.\n", 35); // LÄgg in funktion
		i_bullen = l_game.bulle();
		l_game.pause(700, 5);
		if (i_bullen == 1)
		{
			cout << "The bulle was delicious and you feel refreshed, mmmm.\n";
		}
		else
		{
			l_game.print("The bulle was moldy on the inside making you grasp your stomach, you lie on the floor while drifting into unconsciousness.", 35);
			l_game.pause(700, 5);
			l_game.print("You wake up feeling a familiar ground, you check your surroundings and notice that you are in a bed and back in your cell", 35);
			l_game.print("Bummer...", 50);
			CleanItems();
		}
		break;
	case e_dice:
		l_game.print("You threw a dice\n", 35); // Lägg in funktion
		i_dice = l_game.dice();
		l_game.pause(700, 5);
		if (i_dice >= 4)
		{
			cout << "You rolled a SUCCES";
		}
		else
		{
			l_game.print("You rolled a critical fail'ish, you feel the air around you starting to push and squeeze in and around you.\n", 35);
			l_game.print("The room makes a humming sound as you see it warp far away from you in every direction. The table you were standing next to draws away and the clock on the wall spins rapidly backwards, but you don't feel like your moving.\n", 45);
			l_game.pause(700, 5);
			l_game.print("Suddenly the walls rush back, the room starts collapsing towards you with a loud noise. You duck down grasping and covering yourself as hard as you can before the inevitable end.\n", 25);
			l_game.pause(1000, 5);
			l_game.print("Everything stops, all you can hear is a familiar clock ticking. You're back in your cell but you've teleported back in time", 45);
			l_game.pause(700, 5);
			l_game.print("You noticed you've lost everything you had on you except what you started with. Bummer...", 35);
			CleanItems();
			
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
				i_coins -= 1;
				if (i_coins == 0)
				{
					b_coins = false;
				}
				answer = "";
				cout << "Who do you want to call?\n 1. Call your mother || 2. Call the developers " << s_teleBoss << "7. Go back to the fika room";
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
						cout << s_bossAway;
					}
					break;
				case e_fikaroom:
					b_telephone = false;
					break;
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
	cout << "Linda & Hasse answer the phone from their office, grupprum 2." << endl;
	while (b_callDevelopers)
	{
		cout << "What do you want to say?\n 1. You guys suck! || 2. Your guys are fantastic! || 3. I need help! || h. Hang up the phone\n";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case e_suck:
			cout << "Wow, you've got some balls. You're the right person for this Electric Chair\n";
			break;
		case e_fantastic:
			cout << "Awwh, thanks.\n";
			break;
		case e_help:
			cout << "Dumbass...\n";
			break;
		case e_hangup:
			b_callDevelopers = false;
			break;
		default:
			cout << "Bullen?\n" << endl;
			break;
		}
	}
	telephone();
}

void Locations::callBoss() {
	b_callBoss = true;
	cout << "Yes?, what is it?... have the donuts arrived?" << endl;
	while (b_callBoss)
	{
		cout << "What do you want to say?\n 1. Hi, its " << l_game.s_name << ". || 2. This is your wifes doctor calling, it's what she's have always feared. || 3. Sell vacuum cleaners. || 4. Yeah!, there's tons of donuts. || h. Hang up the phone\n";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case e_introduce:
			b_callBoss = false;
			cout << "What?! How did you get a phone?!... \"guards!\" *click*\n";
			cout << "Dumbfounded you hear the guards running in the corridor, they jump on you like a pack of hungry wolves.\n";
			break;
		case e_hospital:
			b_callBoss = false;
			cout << "Oh no... I'm coming right away!... *click*\n";
			break;
		case e_seller:
			b_callBoss = false;
			cout << s_seller;
			cout << s_bossSeller;
			break;
		case e_donuts:
			b_callBoss = false;
			cout << "Ahh, finally... \"time for a donut break guys\" *click*.";
			cout << "Oh yeah... I am in the fika room... crap!\n";
			break;
		case e_hangup:
			b_callBoss = false;
			break;
		default:
			cout << "Who is this?, answer or I'll hang up on the phone." << endl;
			break;
		}
	}
	switch (answer[0])
	{
	case e_introduce:
		CleanItems();
		break;
	case e_hospital:
		b_bossAway = true;
		if_teleBoss = false;
		s_bossAway = "**Hi, this is the boss. I'm not available at the moment but leave a message after the bip. ...biiiip.**\n You hang up the phone.";
		break;
	case e_seller:
		if (b_bossSeller)
		{
			b_bossSeller = false;
			s_seller = "Hi! Do you want to buy our magnificent vacuum cleaners? Ofcourse yo...\n";
			s_bossSeller = "I want to buy you a nice cup of shut the fuck up... click..";
		}
		else
		{
			s_seller = "Hi! Do you wan..\n";
			s_bossSeller = "No. click\n";
		}
		telephone();
		break;
	case e_donuts:
		CleanItems();
		break;
	case e_hangup:
		telephone();
		break;
	default:
		break;
	}
}

void Locations::lockerroom() {

	b_lockerroom = true;
	menu(titleLockerroom, 10); // skriver ut titeln med färg.
	cout << " You are now in the lockerroom, you see a washing machine and a bunch of lockers " << endl;
	while (b_lockerroom)
	{
		cout << " 1. use washing machine || 2. open a locker || 3. Go to fikaroom  || 4. Back to main corridor || i. Inventory ";
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case wash:
			washing(); // skickar till funktionen washing.
			break;
		case open:
			b_lockerroom = false;	// avslutar loopen
			break;
		case '3':
			b_lockerroom = false;	// avslutar loopen
			break;
		case '4':
			b_lockerroom = false;	 // avslutar loopen
			break;
		case e_inventory:
			l_player.inventory();
			break;
		default:
			cout << wrongAnsw << endl;
		}
	}
	switch (answer[0])
	{
	case open:
		locker(); // skickar till funktionen locker.
		break;
	case '3':
		fikaroom();		//Skickar tillbaka till fikaroom
		break;
	case '4':
		mainCorridor();		// Skickar tillbaka till korridoren
		break;
	}
}

void Locations::washing()
{
	if (b_bloodyUniform == true || b_cleanUniform == true) // om man har en uniform, ren/blodig
	{
		if (i_coins > 0)
		{
			cout << " That cost you one coin! Mmmmm .. your clothes smell gooood, they are now clean" << endl;
			l_player.changeUniform(); // ändrar uniform till ren
			b_cleanUniform = true;
			i_coins = i_coins - 1;
			if (i_coins <= 0)
			{
				l_player.changeCoins(); // tar bort coins från inventory när dom är slut
				b_coins = false;
			}
		}
		else if (i_coins <= 0)
		{
			cout << " you are out of coins.." << endl;
		}
	}
	else
	{
		if (i_coins > 0)
		{
			cout << " You put a coin in the maschine.. "; //test test
			cout << " Your prisonscrubbs smell like flowers..mmm" << "coins: " << i_coins << endl; // Om man inte har en uniform alls
			i_coins = i_coins - 1;
			if (i_coins <= 0)
			{
				b_coins = false;
				l_player.changeCoins(); // tar bort coins från inventory när dom är slut
			}
		}
		else
			cout << " you are out of coins.." << "coins: " << i_coins << endl;//TEST TEST
	}
}

void Locations::locker()
{
	b_locker = true;
	while (b_locker)
	{ 
		// Kollar om man har en uniform & INGA coins, man får inte ta coins om man inte har en uniform eller om man redan har coins.
		if (b_coins == true || (b_bloodyUniform == false && b_cleanUniform == false)) 
		{
			choiceCoins = " ";
		}
		else if (b_coins == false && (b_bloodyUniform == true || b_cleanUniform == true)) // Har du inga, du får valet
		{
			choiceCoins = "|| 4. some coins";
		}

		cout << " In the locker you see a bunch of things, do you want to take something?\n 1. Back to lockerroom || 2. A clean uniform || 3. stinky banana peel " << choiceCoins;
		answer = "";
		cin >> answer;
		switch (answer[0])
		{
		case '1':
			b_locker = false; // avslutar loopen
			break;
		case '2':
		{
			cout << " Nice choice, are you a guard at this prison?! you sure look like one.. " << endl;
			if (b_bloodyUniform == true) // Om man har en blodig uniform men tar en ren
			{
				l_player.changeUniform();	// byter ut den blodiga mot en ren
				b_cleanUniform = true;		// visar att du har en ren uniform
			}
			else if (b_bloodyUniform == false && b_cleanUniform == false) // Om man inte har någon uniform och tar en ren
			{
				l_player.ItemCleanUniform();  // lägger in en ren uniform i inventory
				b_cleanUniform = true;		  // visar att du har en ren uniform
			}
			break;
		}
		case '3':
			cout << " Uuuhhhaaaa why would you want that?! stop taking junk, idiot." << endl;
			break;
		case '4':
			cout << " coins coins coins.. they always welcome" << endl;
			if (b_coins == false) // man får bara mer coins om man inte redan hade några
			{
				l_player.ItemCoins(); // Ger spelaren "some coins" i inventory OM dom inte redan hade coins.
				i_coins = i_coins + 2; // plussar på int coins.
				b_coins = true;
			}
			break;
		default:
			cout << wrongAnsw << endl;
			break;
		}
	}
	switch (answer[0])
	{
	case '1':
		lockerroom(); // skickar till lockerrom
		break;
	}
}

void Locations::mainEntrance() {
	menu(titleMainEntrance, 4); // skriver ut titeln med färg.

	if (b_bossAway)
	{
		l_game.victory();
	}
	if (b_bloodyUniform) // Placeholder
	{
		s_teleBoss = "|| 3. Call the boss ";
		if_teleBoss = true;
	}
}

void Locations::gameover() { // Inte färdig. flytta till location. Töm inventory..skicka till starta om.

	// nollställ items
	bool b_scissors = false;		// sax
	bool b_bloodyUniform = false;	// blodig uniform
	bool b_cleanUniform = false;	// ren uniform
	bool b_coins = false;			// coins
	l_player.clearVector();			// rensa inventory
	i_coins = 0;						// noll coins
	if_choice1 = true;				// återställer menyn, så man har alla 3 val
	if_choice2 = true;
	if_choice3 = true;
	choice1 = "1. Hairpin ";
	choice2 = "2. Harry Potter book ";
	choice3 = "3. Nail-file ";

	b_gameOver = true;

	while (b_gameOver)
	{ 
	cout << "Game over! You did not escape the electric chair.. start over? y/n";
	answer = "";
	cin >> answer;
	switch (answer[0])
	{
	case 'y':
		b_gameOver = false;
		l_game.intro();
		break;
	case 'n':
		b_gameOver = false;
		cout << "Quitting.. " << endl;
		break;
	}
	}

}


void Locations::menu(string name, int a)
{
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
	cout << " ------------------------------------------" << endl;
	cout << " ##########################################" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << name << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
	cout << " ##########################################" << endl;
	cout << " ------------------------------------------" << endl; // endl för att tömma buffern
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
Locations::Locations()
{
}

Locations::~Locations()
{
}
