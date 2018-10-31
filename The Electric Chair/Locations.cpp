#include "pch.h"
#include "Locations.h"
#include "Game.h"
#include "Player.h"

Game l_game;
Player l_player;

// Spelet ber om input från användaren att ge ett namn till sin karaktär som sparas i game klassen.
void Locations::start() {
	answer = "";
	s_name = "";
	l_game.print("  What is your name?", 15);
	while (getline(cin, s_name))
	{
		if (s_name != "")
		{
			break;
		}
	}
	l_game.print("\n  ==========================================================================\n  ", 1);
	l_game.print("  Judge: ", 65);
	cout << "    -" << s_name << "!\n  ";
	l_game.pause(700, 3);
	l_game.print("    -You are charged for the murder of... some dude and hereby sentenced to death!\n", 65);
	cout << "  " << s_name;
	l_game.print("'s Mother:\n    -Now why did you go and do that huh?!\n    -Tell your father when you see him he can rott in hell!\n  .. *Mother walks out*...\n", 65);
	l_game.print("  Prison Manager:\n    -Well luckily for you we have some malfunctions with the chair.\n    Something with the circuits on this old relic and it's all from across the globe\n    or somewhere so it'll take sometime before we get it fixed.\n    So get comfortable, hahahaha.\n", 65);
	l_game.pause(700, 3);
	l_game.print("  4 years later...", 100);
	system("pause");
	fillItems();
}

// Fyller inventory från början.
void Locations::fillItems() 
{
	l_player.startInventory(); // fyller med 3 saker som man kan använda i början av spelet.
	cellA();
}

// rensar alla items så att spelaren måste börja om, spelaren har 3 chanser, sedan blir det Gameover.
void Locations::CleanItems() 
{
	
	l_player.ClearExtraItems(); // tar bort alla items i inventory utom de 3 första.

	// rensar alla items bools till false
	b_scissors = false;			
	b_bloodyUniform = false;
	b_cleanUniform = false;
	b_coins = false;
	i_coins = 0;
	b_bossAway = false;			// gör att chefen är kvar i main entrence
	if_teleBoss = false;		// så man inte kan ringa chefen innan man varit i main entrence
	cellA();					// skickar sedan vidare spelaren till cell A
}

// Här startar spelaren, i Cell A.
void Locations::cellA() {

	// clear screen
	system("CLS"); 

	// Om alla 3 chanser är false så har du förlorat.
	if (if_choice1 == false && if_choice2 == false && if_choice3 == false)  
	{
		gameover(); // Skickar till funktionen gameover
	}

	// Om man fortfarande har någon chans kvar.
	else
	{ 
		menu(titleCellA, 9); // skriver ut titeln med färg.
		b_cellA = true;
		while (b_cellA)
		{
			l_game.print("  You are stuck in your cell A, how do you plan to escape?", 35);
			answer = "";
			cout << "  " << s_choice1 << s_choice2 << s_choice3 << "i. Inventory\n";
			cin >> answer;
			cout << endl;
			switch (answer[0]) // switchen tar endast in första "char" som skrivs, spelet kraschar ej.
			{
			case e_hairpin:
				b_cellA = false;
				l_player.pushBack(1); // skickar in en "Broken hairpin" i inventory
				s_choice1 = "";	// man ser inte längre hairpin som ett val
				if (if_choice1) { // Kollar om spelaren får använda "hairpin"
					if_choice1 = false; // spelaren kan inte längre använda hairpin
					l_game.print("  You bend and twist you hairpin into a keylike form.\n  After some tries you succesfully open the lock, unfortunally you hairpin is all but broken.\n", 35);
					l_game.print("  You escaped from your cell", 25);
					system("pause"); // väntar på ett enter innan den går vidare
					cellCorridor(); // spelaren skickas till cell corridor
				}
				else {
					l_game.print("  Your hairpin is broken. Use something else", 15); // om hairpin är "broken", då får den inte längre användas.
				}
				break;
			case e_harryPotter:
				b_cellA = false;
				l_player.pushBack(2);
				s_choice2 = "";
				if (if_choice2) {
					if_choice2 = false;
					l_game.print("  After reading the book you decide to try your luck and pick up the toilet brush...\n  You swish and flick your makeshift wand and recite the words \"Alohomora\"\n  After realising that your cell is now sprayed with toilet water you hear the lock click.", 35);
					l_game.print("  You escaped from your cell", 25);
					system("pause"); 
					cellCorridor();
				}
				else {
					l_game.print("  Your Harry Potter book has been warped in space&time from the spell. Use something else", 15);
				}
				break;
			case e_nailfile:
				b_cellA = false;
				l_player.pushBack(3);
				s_choice3 = "";
				if (if_choice3) {
					if_choice3 = false;
					l_game.print("  You take your nail-file an start working the lock...", 35);
					l_game.pause(700, 5);
					l_game.print("  4 months later you succesfully break the lock.", 35);
					l_game.print("  You escaped from your cell", 25);
					system("pause"); 
					cellCorridor();
				}
				else {
					l_game.print("  Your nail-file is dull after all those years. Use something else", 15);
				}
				break;
			case e_inventory:
				l_player.inventory(); // Visar funktionen "inventory" i consolen.
				break;
			default:
				l_game.print(wrongAnsw, 15); // berättar för spelaren att den skrivit fel och den får en ny chans, en konstant.
				break;
			}
		} // Slut på while loop
	}
}

void Locations::cellCorridor() {

	system("CLS"); // clear screen
	menu(titleCellCorridor, 9); // skriver ut titeln med färg.
	b_cellCorr = true;
	
	while (b_cellCorr)
	{
		l_game.print("  What do you want to do? ", 35);
		cout << "  3. Go to Cell B || 4. Go to securityroom || i. Inventory\n";
		answer = "";
		cin >> answer;
		cout << endl;
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
		l_game.print("  You take a peek into Cell B.", 15);
		system("pause");
		cellB();
		break;
	case e_securityroom:
		l_game.print("  You continue out, into the security room.", 15);
		system("pause");
		securityroom();
		break;
	}
}

void Locations::cellB() {
	system("CLS"); // clear screen
	b_cellB = true;
	menu(titleCellB, 9); // skriver ut titeln med färg.
	l_game.print("  You are talking to your friendly neighbour, the weapons dealer.", 35);
	while (b_cellB)
	{
		l_game.print("  Cell Neighbour:", 35);
		l_game.print("    -What do you want?", 35);
		cout << "  1. Take scissors || 2. Take bazooka || 3. Take Ak47 || 4. Take Kpist || i. Inventory\n";
		answer = "";
		cin >> answer;
		cout << endl;
		switch (answer[0])
		{
		case e_scissor:
			b_cellB = false;
			if (b_scissors == true) // Så att man inte ska kunna ta flera saxar.
			{
				l_game.print("  Cell Neighbour:", 35);
				l_game.print("    -You already have one.. why take two?", 15);
			}
			else
			{ 
			l_player.giveItem(1); // Ger en sax i inventory
			b_scissors = true;
			l_game.print("  Good choice! You now have a scissor in your inventory\n", 35);
			}
			break;
		case e_bazooka:
			l_game.print("  Cell Neighbour:", 35);
			l_game.print("    -I'm sorry its too big, I cant get it through the metal bars.. try something else", 25);
			break;
		case e_ak47:
			l_game.print("  Cell Neighbour:", 35);
			l_game.print("    -It's out of ammo, try something else", 25);
			break;
		case e_kpist:
			l_game.print("  Cell Neighbour:", 35);
			l_game.print("    -It's rusty as hell, it won't work, try something else", 25);
			break;
		case e_inventory:
			l_player.inventory();
			break;
		default:
			l_game.print(wrongAnsw, 15);
			break;
		}
	}
	if (answer[0] == e_scissor)
	{
		l_game.print("  Happy getting something, you turn back.", 15);
		system("pause"); // väntar på ett enter innan den går vidare
		cellCorridor();
	}
}

void Locations::securityroom() {
	system("CLS"); // clear screen
	b_secroom = true;
	menu(titleSecurityRoom, 4); // skriver ut titeln med färg.
	if (b_scissors == true)
	{
		l_game.print("  You lunge towards the guard and stab him.\n  The body lies motionless on the floor, you think to yourself that his uniform might come in handy.", 35);
		while (b_secroom)
		{
			l_game.print("  Do you take the unifrom?\n  y/n", 35);
			answer = "";
			cin >> answer;
			cout << endl;
			switch (answer[0])
			{
			case 'y':
			{
				b_secroom = false;
				l_player.giveItem(2);// ger spelaren en blodig uniform
				b_bloodyUniform = true;
				l_game.print("  You found some coins in the uniform.. wohoo", 35);
				l_player.giveItem(4);
				b_coins = true; // Till inventory och valet i lockerrom
				i_coins = 8;  // Spelaren har nu 8 coins.
				break;
			}
			case 'n':
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
		l_game.print("  After a stumble over the body you go into the main corridor.\n  You notice that the door locks tight behind you, no going back by yourself now.", 15);
		system("pause"); // väntar på ett enter innan den går vidare
		mainCorridor();
	}
	else
	{
		l_game.print("  The security guard quickly notices you and puts you back into your cell!!", 15);
		system("pause"); // väntar på ett enter innan den går vidare
		CleanItems();
	}
}

void Locations::mainCorridor() {

	system("CLS"); // clear screen
	menu(titleMainCorridor, 4); // skriver ut titeln med färg.
	b_mainCorr = true;
	l_game.print(s_farCorrIntro, 35);

	while (b_mainCorr)
	{
		l_game.print("  Where do you want to go?", 35);
		cout << "  " << s_fikaRoom << s_lockerRoom << s_farCorr << "|| 9. Main entrance || i. Inventory\n";
		answer = "";
		cin >> answer;
		cout << endl;
		switch (answer[0])
		{
		case e_fikaroom:
			if (b_fikaRoomReveal)
			{
				b_mainCorr = false;
			}
			else
			{
				l_game.print("  I see some doors over in the corridor but I don't know where it's leading.", 25);
			}
			break;
		case e_lockerroom:
			if (b_lockerRoomReveal)
			{
				b_mainCorr = false;
			}
			else
			{
				l_game.print("  I see some doors over in the corridor but I don't know where it's leading.", 25);
			}
			break;
		case e_farCorridor:
			if (b_farCorrHide)
			{
				b_mainCorr = false;

				// Far Corridor värden som tar bort alternativet efter man har varit dit.
				// Dom återställs i gameover funktionen.
				b_farCorrHide = false;
				b_fikaRoomReveal = true;
				b_lockerRoomReveal = true;
				s_farCorr = "";
				s_fikaRoom = "7. Go to fika room ";
				s_lockerRoom = "|| 8. Go to locker room ";
				s_farCorrIntro = "  You hear some voices coming from the main entrance to the right, to the left is the fika room and locker room.\n";
			}
			else
			{
				l_game.print("  That's the far corridor, but I allready knows what's there.", 25);
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
		l_game.print("  You go to the fika room...", 15);
		fikaroom();
		break;
	case e_lockerroom:
		l_game.print("  You go to the locker room...", 15);
		lockerroom();
		break;
	case e_mainEntrance:
		l_game.print("  You go to the main entrance...", 15);
		mainEntrance();
		break;
	default:
		break;
	}
}

// Far corridor finns bara tillgänglig första gången, alternativet tas bort så fort man har gått dit.
void Locations::farCorridor() {
	l_game.print("  The corridor you continue to walk.\n", 25);
	l_game.print("  A fika room and locker room you find doors to.", 35);
	while (b_farCorr)
	{
		l_game.print("  Where do you want to go?", 35);
		cout << "  7. Fika Room || 8. Locker Room || i. Inventory\n";
		answer = "";
		cin >> answer;
		cout << endl;
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
	system("CLS"); // clear screen
	b_fikaroom = true;
	menu(titleFikaroom, 10); // skriver ut titeln med färg.
	l_game.print("  You find yourself in the holy fika room. Angels sing and the room table has some strange items and a telephone sits on the wall.", 35); // lägg till text som introducerar aspekter ur val nedanför
	while (b_fikaroom)
	{
		l_game.print("  What do you want to do?", 35);
		cout << "  1. Walk to the table || 2. Use the telephone || 8. Locker Room || 5. Main Corridor || i. Inventory\n";
		answer = "";
		cin >> answer;
		cout << endl;
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
		l_game.print("You walk across the corridor to check the other room...", 15);
		system("pause");
		lockerroom();
		break;
	case e_mainCorridor:
		l_game.print("You go back to the main corridor...", 15);
		system("pause");
		mainCorridor();
		break;
	}
}

void Locations::fikatable() {
	b_fikatable = true;
	l_game.print("  You see a bowl full of bullar and a dice on the table", 35);
	while (b_fikatable)
	{
		answer = "";
		l_game.print("  What do you want to do?", 35);
		cout << "  1. Eat a bulle || 2. Throw the dice || 7. Check the fika room || i. Inventory\n";
		cin >> answer;
		cout << endl;
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
		l_game.print("  You eat a bulle.\n", 35);
		i_bullen = l_game.bulle(); // Kallar på bulle funktionen i game klassen och ger tillbaks ett en slumpmässig siffra.
		l_game.pause(700, 5);
		if (i_bullen == 1)
		{
			cout << "  The bulle was delicious and you feel refreshed, mmmm.\n  Also, you found a coin inside the bulle! lucky you!";
			i_coins = i_coins + 1; // plussar på int coins.
			if (b_coins == false)
			{
				l_player.giveItem(4); // Lägger bara till coins i den synliga inventoryn om dom inte redan finns där.
				b_coins = true;
			}
			system("pause"); // väntar på ett enter innan den går vidare
			fikaroom(); // Händer efter bulle eller dice lyckade utkomster. 
		}
		else
		{
			l_game.print("  The bulle was moldy on the inside making you grasp your stomach,\n  you lie on the floor while drifting into unconsciousness.", 35);
			l_game.pause(700, 5);
			l_game.print("  You wake up feeling a familiar ground,\n  you check your surroundings and notice that you are in a bed and back in your cell", 35);
			l_game.print("  Bummer...", 50);
			system("pause"); // väntar på ett enter innan den går vidare
			CleanItems();
		}
		break;
	case e_dice:
		l_game.print("  You threw a dice\n", 35);
		i_dice = l_game.dice(); // Kallar på dice funktionen i game klassen och ger tillabks en slumpmässig siffra.
		l_game.pause(700, 5);
		if (i_dice >= 4)
		{
			cout << "  You rolled a SUCCES and got one coin! ";
			i_coins = i_coins + 1; // plussar på int coins.
			if (b_coins == false)
			{
				l_player.giveItem(4); // Lägger bara till coins i den synliga inventoryn om dom inte redan finns där.
				b_coins = true;
			}
			system("pause"); // väntar på ett enter innan den går vidare
			fikaroom(); // Händer efter bulle eller dice lyckade utkomster. 1/2
		}
		else
		{
			l_game.print("  You rolled a critical fail'ish, you feel the air around you starting to push and squeeze in and around you.\n", 35);
			l_game.print("  The room makes a humming sound as you see it warp far away from you in every direction.\n  The table you were standing next to draws away and the clock on the wall spins rapidly backwards, but you don't feel like your moving.\n", 45);
			l_game.pause(700, 5);
			l_game.print("  Suddenly the walls rush back, the room starts collapsing towards you with a loud noise.\n  You duck down grasping and covering yourself as hard as you can before the inevitable end.\n", 25);
			l_game.pause(1000, 5);
			l_game.print("  Everything stops, all you can hear is a familiar clock ticking.\n  You're back in your cell but you've teleported back in time", 45);
			l_game.pause(700, 5);
			l_game.print("  You notice you've lost everything you had on you except what you started with.\n  Bummer...", 35);
			system("pause"); // väntar på ett enter innan den går vidare
			CleanItems();
		}
		break;
	case e_fikaroom:
		l_game.print("  You leave the table, for now...", 15);
		system("pause"); // väntar på ett enter innan den går vidare
		fikaroom();
		break;
	}
}

void Locations::telephone() {
	b_telephone = true;
	l_game.print("  You take the telephone to your head and hear the ringtone.", 35);
	if (b_coins == true) // Kollar om du har några coins annars går kommer du tillbaks till fikarummet.
	{
		while (b_telephone)
		{
			if (b_coins == true) // Kollar om du har några coins annars går kommer du tillbaks till fikarummet.
			{
				i_coins -= 1; // Kostar en coin att ringa ett samtal
				if (i_coins == 0) // Om du får slut på coins i loopen så stängs den och skickar tillbaka dig till fikarummet.
				{
					b_coins = false;
					l_player.changeCoins(); // tar bort coins från inventory om dom är slut.
				}
				answer = "";
				l_game.print("  Who do you want to call?\n", 35);
				cout << "  1. Call your mother || 2. Call the developers || 3. Call the boss || 7. Go back to the fika room\n";
				cin >> answer;
				cout << endl;
				switch (answer[0])
				{
				case e_mother:
					b_telephone = false;
					break;
				case e_developers:
					b_telephone = false;
					break;
				case e_boss:
					if (if_teleBoss) // Bossen kan bara ringas när man har besökt honom i main entrance
					{
						b_telephone = false;
					}
					else
					{
						l_game.print(s_bossAway, 15);
					}
					break;
				case e_fikaroom:
					b_telephone = false;
					break;
				default:
					l_game.print("  You typed a number, but no one answered. Try again", 15);
					break;
				}
			}
			else
			{
				b_telephone = false;
				l_game.print("  You are out of coins, you can't make a call.", 15);
				system("pause");
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
			fikaroom();
			break;
		}
	}
	else
	{
		l_game.print("  You are out of coins, you can't make a call.", 15);
		system("pause");
		fikaroom();
	}
}

// Ring och prata med mamma.
void Locations::callMother() {
	b_callMother = true;
	l_game.print("  Your mother answers the phone.", 35);
	while (b_callMother)
	{
		l_game.print("  What do you want to say?", 35);
		cout << "  1. Ask her for money || 2. Tell her she's pretty || 3. Congratulate her on her birthday || h. Hang up the phone\n";
		answer = "";
		cin >> answer;
		cout << endl;
		switch (answer[0])
		{
		case e_money:
			l_game.print("  Mother:", 35);
			l_game.print("    -You're not getting any money from me until you've become a god-loving human being, like that's ever gonna happen.", 25);
			break;
		case e_pretty:
			l_game.print("  Mother:", 35);
			l_game.print("    -Well then you're certianly not my child, cause you're but ugly.", 25);
			break;
		case e_birthday:
			l_game.print("  Mother:", 35);
			l_game.print("    -You're only 3 years late, dumbass!", 25);
			break;
		case e_hangup:
			b_callMother = false;
			break;
		default:
			l_game.print("  Mother:", 35);
			l_game.print("    -Did you wanna say something or are you just wasting my time?", 15);
			break;
		}
	}
	l_game.print("  Goodbye mom..", 15);
	telephone();
}

// Ring och prata med oss.
void Locations::callDevelopers() {
	b_callDevelopers = true;
	l_game.print("  Linda & Hasse answer the phone from their office, grupprum 2.", 35);
	while (b_callDevelopers)
	{
		l_game.print("  What do you want to say?", 35);
		cout << "  1. You guys suck! || 2. Your guys are fantastic! || 3. I need help! || h. Hang up the phone\n";
		answer = "";
		cin >> answer;
		cout << endl;
		switch (answer[0])
		{
		case e_suck:
			l_game.print("  Developers:", 35);
			l_game.print("    -Wow, you've got some balls. You're the right person for this Electric Chair.", 25);
			break;
		case e_fantastic:
			l_game.print("  Developers:", 35);
			l_game.print("    -Awwh, thanks.", 25);
			break;
		case e_help:
			l_game.print("  Developers:", 35);
			l_game.print("    -Have you tasted the bulle, or thrown a dice?...", 25);
			break;
		case e_hangup:
			b_callDevelopers = false;
			break;
		default:
			l_game.print("  Developers:", 35);
			l_game.print("    -Bullen?", 15);
			break;
		}
	}
	l_game.print("  Goodbye, thanks for the help...", 15);
	telephone();
}

// Ring och prata med bossen, om du får.
void Locations::callBoss() {
	b_callBoss = true;
	l_game.print("  Security Boss:", 35);
	l_game.print("    -Yes?, what is it?... have the donuts arrived?", 35);
	while (b_callBoss)
	{
		l_game.print("  What do you want to say?", 35);
		cout << "  1. Hi, its " << s_name << ". || 2. This is your wifes doctor calling, it's what she's always feared. || 3. Sell vacuum cleaners. || 4. Yeah!, there's tons of donuts. || h. Hang up the phone\n";
		answer = "";
		cin >> answer;
		cout << endl;
		switch (answer[0])
		{
		case e_introduce:
			b_callBoss = false;
			l_game.print("  Security Boss:", 35);
			l_game.print("    -What?! How did you get a phone?!... \"guards!\" *click*", 25);
			l_game.print("  Dumbfounded you hear the guards running in the corridor, they jump on you like a pack of hungry wolves.", 25);
			break;
		case e_hospital:
			b_callBoss = false;
			l_game.print("  Security Boss:", 35);
			l_game.print("    -Oh no... I'm coming right away!... *click*", 25);
			break;
		case e_seller:
			b_callBoss = false;
			l_game.print("  ", 35);
			cout << s_name << ":\n";

			// En förändrande konversation som säljare med bossen. Återställs i gameover funktionen.
			l_game.print(s_seller, 25);
			l_game.print("  Security Boss:", 35);
			l_game.print(s_bossSeller, 25);
			break;
		case e_donuts:
			b_callBoss = false;
			l_game.print("  Security Boss:", 35);
			l_game.print("    -Ahh, finally... \"time for a donut break guys\" *click*.", 25);
			l_game.print("  Oh yeah... I am in the fika room... crap!", 25);
			break;
		case e_hangup:
			b_callBoss = false;
			break;
		default:
			l_game.print("  Security Boss:", 35);
			l_game.print("    -Who is this?, answer or I'll hang up on the phone.", 15);
			break;
		}
	}
	switch (answer[0])
	{
	case e_introduce:
		system("pause"); // väntar på ett enter innan den går vidare
		CleanItems();
		break;
	case e_hospital: // Efter det här valet så initieras våran win condition i main entrance
		b_bossAway = true;
		if_teleBoss = false;
		s_bossAway = "  **Hi, this is the boss. I'm not available at the moment but leave a message after the bip. ...biiiip.**\n  You hang up the phone.";
		telephone();
		break;
	case e_seller: // Byter ut hur konversationen utspelas
		if (b_bossSeller)
		{
			b_bossSeller = false;
			s_seller = "    -Hi! Do you want to buy our magnificent vacuum cleaners? Ofcourse yo...\n";
			s_bossSeller = "    -I want to buy you a nice cup of shut the fuck up... *click*..\n";
		}
		else
		{
			s_seller = "    -Hi! Do you wan..\n";
			s_bossSeller = "    -No. *click*\n";
		}
		telephone();
		break;
	case e_donuts:
		system("pause"); // väntar på ett enter innan den går vidare
		CleanItems();
		break;
	case e_hangup:
		l_game.print("  .. click...", 15);
		telephone();
		break;
	default:
		break;
	}
}

void Locations::lockerroom() {
	system("CLS"); // clear screen

	b_lockerroom = true;
	menu(titleLockerroom, 10); // skriver ut titeln med färg.
	l_game.print("  You are now in the lockerroom, you see a washing machine and a bunch of lockers ", 35);
	while (b_lockerroom)
	{
		l_game.print("  What do you want to do?", 35);
		cout << "  1. Use washing machine || 2. Open a locker || 7. Go to fikaroom  || 5. Back to main corridor || i. Inventory\n";
		answer = "";
		cin >> answer;
		cout << endl;
		switch (answer[0])
		{
		case e_wash:
			washing(); // skickar till funktionen washing.
			break;
		case e_open:
			b_lockerroom = false;	// avslutar loopen
			break;
		case e_fikaroom:
			b_lockerroom = false;	// avslutar loopen
			break;
		case e_mainCorridor:
			b_lockerroom = false;	 // avslutar loopen
			break;
		case e_inventory:
			l_player.inventory();
			break;
		default:
			l_game.print(wrongAnsw, 15);
		}
	}
	switch (answer[0])
	{
	case e_open:
		locker(); // skickar till funktionen locker.
		break;
	case e_fikaroom:
		l_game.print("  You walk across the corridor to check the other room...", 15);
		fikaroom();		//Skickar tillbaka till fikaroom
		break;
	case e_mainCorridor:
		l_game.print("  You go back to the main corridor...", 15);
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
			l_game.print("  That cost you one coin! Mmmmm .. your clothes smell gooood, they are now clean", 25);
			l_player.changeUniform(); // ändrar uniform till ren
			b_cleanUniform = true;
			b_bloodyUniform = false; // ändrar blodiga uniformen till false eftersom man nu har en ren.
			i_coins = i_coins - 1;
			if (i_coins <= 0)
			{
				l_player.changeCoins(); // tar bort coins från inventory när dom är slut
				b_coins = false;
			}
		}
		else if (i_coins <= 0) // om man har slut på coins.
		{
			l_game.print("  You are out of coins..", 15);
			l_game.pause(500, 3);
		}
	}
	else
	{
		if (i_coins > 0) // om man har några coins.
		{
			l_game.print("  You put a coin in the maschine.. ", 35); 
			l_game.print("  Your prisonscrubbs smell like flowers..mmm", 35); // Om man inte har en uniform alls
			i_coins = i_coins - 1;
			if (i_coins <= 0)
			{
				b_coins = false;
				l_player.changeCoins(); // tar bort coins från inventory när dom är slut
			}
		}
		else
		{
			l_game.print("  You are out of coins..", 15);
			l_game.pause(500, 3);
		}
	}
}

void Locations::locker()
{
	b_locker = true;
	while (b_locker)
	{ 
		l_game.print("  In the locker you see a bunch of things, do you want to take something?", 35);
		cout << "  1. A clean uniform || 2. Stinky banana peel || 3. some coins || 8. Back to lockerroom\n";
		answer = "";
		cin >> answer;
		cout << endl;
		switch (answer[0])
		{
		case e_lockerroom:
			b_locker = false; // avslutar loopen
			break;
		case e_cleanUniform:
		{
			l_game.print("  Nice choice, are you a guard at this prison?! you sure look like one.. ", 25);
			if (b_bloodyUniform == true) // Om man har en blodig uniform men tar en ren
			{
				l_player.changeUniform();	// byter ut den blodiga mot en ren
			}
			else if (b_bloodyUniform == false && b_cleanUniform == false) // Om man inte har någon uniform och tar en ren
			{
				l_player.giveItem(3);  // lägger in en ren uniform i inventory
				l_game.print("  You found some coins in the uniform.. wohoo", 35);
				i_coins = i_coins + 5; // du får coins 
				if (b_coins == false)
				{
					l_player.giveItem(4); // Lägger bara till coins i sden synliga inventoryn om dom inte redan finns där.
					b_coins = true;
				}
			}
			b_cleanUniform = true;		// visar att du har en ren uniform
			b_bloodyUniform = false; // ändrar blodiga uniformen till false eftersom man nu har en ren.
			break;
		}
		case e_banana:
			l_game.print("  Uuuhhhaaaa why would you want that?! Stop taking junk, idiot.", 35);
			break;
		case e_coins:
			if (b_coins == false) // man får bara mer coins om man inte redan hade några
			{
				l_game.print("  Coins coins coins.. they always welcome ", 35);
				l_player.giveItem(4); // Ger spelaren "some coins" i inventory OM dom inte redan hade coins.
				i_coins = i_coins + 4; // plussar på int coins.
				b_coins = true;
			}
			else
			{
				l_game.print("  Your pockets are already full of coins, come back later when you have spent some..", 35);
			}
			break;
		default:
			l_game.print(wrongAnsw, 15);
			break;
		}
	}
	switch (answer[0])
	{
	case e_lockerroom:
		l_game.print("  You close the locker...", 15);
		system("pause");
		lockerroom(); // skickar till lockerrom
		break;
	}
}

void Locations::mainEntrance() { 
	system("CLS"); // clear screen
	
	menu(titleMainEntrance, 4); // skriver ut titeln med färg.
	l_game.print("  You have now entered the main entrence.. be aware of the securityboss! ", 35);

	// Om man har en blodig uniform
	if (b_bloodyUniform == true) 
	{
		l_game.print("  The boss noticed the blood on your uniform, you got caught..", 35);
		l_game.print("  Security Boss:", 35);
		l_game.print("    -Back in your cell YOU BLOODY CRIMINAL!!", 35);
		l_game.print("  You are back in your cell and you noticed you've lost everything you had on you except what you started with. Bummer...", 35);
		system("pause"); // väntar på ett enter innan den går vidare
		CleanItems(); // rensar items och skickar tillbaka till cell A
	}
	else if (b_bloodyUniform == false && b_cleanUniform == false) // Om man inte har någon uniform alls
	{
		l_game.print("  The boss noticed the blood on your uniform, you got caught..", 35);
		l_game.print("  Security Boss:", 35);
		l_game.print("    -Back in your cell YOU BLOODY CRIMINAL!!", 35);
		l_game.print("  You are back in your cell and you noticed you've lost everything you had on you except what you started with. Bummer...", 35);
		system("pause"); // väntar på ett enter innan den går vidare
		CleanItems();  // rensar items och skickar tillbaka till cell A
	}

	// om man har en ren uniform på sig
	else if (b_cleanUniform == true)
	{

		// Om man har ringt chefen, så han är borta.
		if (b_bossAway == true) 
		{
			l_game.print("  It seems like the boss has left, nicely done!", 35);
			l_game.victory(); // spelaren VANN SPELET! skickas till victory funktion.
		}

		// om chefen är kvar.
		else 
		{
			l_game.print("  The securityboss walks towards you, he looks at your uniform an then screams angry...", 35);
			l_game.print("  Security Boss:", 35);
			l_game.print("    -BACK TO WORK!! What the hell are you doing here?", 35);
			l_game.print("  You walk back into the main corridor.", 35);
			l_game.print("  Hmmm... if only I could get him out of there somehow...", 55);
			if_teleBoss = true; // Ger valet att spelaren kan ringa chefen från fikaroom
			system("pause");  // väntar på ett enter innan den går vidare
			mainCorridor();  // du skickas tillbaka til maincorridor
		}
	}
}

// När spelaren inte har några chanser kvar
void Locations::gameover() { 

	// **Nollställer spelet för en nystart**
	if_choice1 = true;				// återställer menyn, så man har alla 3 val
	if_choice2 = true;
	if_choice3 = true;
	
	b_scissors = false;			// sax
	b_bloodyUniform = false;	// blodig uniform
	b_cleanUniform = false;		// ren uniform
	b_coins = false;			// coins
	b_farCorrHide = true;
	b_fikaRoomReveal = false;
	b_lockerRoomReveal = false;
	b_bossSeller = true;
	b_bossAway = false;			// chefen är kvar
	if_teleBoss = false;		// så man inte kan ringa chefen
	
	i_coins = 0;					// noll coins

	s_choice1 = "1. Use Hairpin || ";
	s_choice2 = "2. Use Harry Potter book || ";
	s_choice3 = "3. Use Nail-file || ";
	s_farCorrIntro = "  You hear some voices coming from the main entrance to the right, to the left the corridor just keeps going.\n";
	s_farCorr = "  6. Continue the corridor ";
	s_fikaRoom = "";
	s_lockerRoom = "";
	s_seller = "    -Hi! Do you want to buy our magnificent vacuum cleaners? Ofcourse you do, and we got a special price for you just TODAY! Just confirm the payment and get an extra pack of vacuum bags for free!\n";
	s_bossSeller = "    -Why don't you take those extra bags and shove'em up where the sun don't shine... *click*\n.";

	l_player.clearVector();			// rensa inventory

	// detta visas i consolen
	menu(titleGameOver, 6); // skriver ut titeln med färg.
	l_game.print("  Game over! You did not escape the electric chair..", 35);
	system("pause"); // väntar på ett enter innan den går vidare
	l_game.intro(); // startar om spelet
}

// Färgad titel till alla rum
void Locations::menu(string name, int a)
{
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
	l_game.print("  ------------------------------------------", 2);
	l_game.print("  ##########################################", 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	l_game.print(name, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
	l_game.print("  ##########################################", 4);
	l_game.print("  ------------------------------------------", 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

Locations::Locations()
{
}

Locations::~Locations()
{
}

