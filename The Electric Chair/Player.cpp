#include "pch.h"
#include "Player.h"
#include "Locations.h"
#include "Game.h"
#include <iomanip>

// Funktion som skriver ut inventory.
void Player::inventory() {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // gul f�rg
	cout << endl << "  �&�&�&�&�&�&�&�&�&�&�&�&�&�&�&�&�" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // vanlig textf�rg
	cout << "    Inventory:" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // gul f�rg
	cout << "  ---------------------------------" << endl;
	//cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // vanlig textf�rg
	for (unsigned int i = 0; i < items.size(); i++)
	{

		cout << "    " << items[i] << endl;

	}
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // gul f�rg
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // gul f�rg
	cout << "  �&�&�&�&�&�&�&�&�&�&�&�&�&�&�&�&�" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Avsluta med vanlig textf�rg
}

void Player::startInventory()
{
	items.push_back("Hairpin");
	items.push_back("Magic Harry Potter book");
	items.push_back("Nailfile");
}

int Player::pushBack(int x) {
	if (x == 1)
	{
		items[0] = "Broken Hairpin";
	}
	else if (x == 2)
	{
		items[1] = "Broken Harry Potter book";
	}
	else if (x == 3)
	{
		items[2] = "Broken Nailfile";
	}
	return 0;
}

void Player::giveItem(int a) {
	switch (a)
	{
	case 1:
		items.push_back("Scissors");
		break;
	case 2:
		items.push_back("Bloody Uniform");
		break;
	case 3:
		items.push_back("Clean uniform");
		break;
	case 4:
		items.push_back("Some coins ");
		break;
	default:
		break;
	}
}

void Player::changeUniform() {

	items[4] = "Clean uniform";
}

void Player::changeCoins()
{
	items.pop_back();
}

void Player::ClearExtraItems()
{
	int count = items.size();
	if (count > 3)
	{
		for (int i = 0; i < count - 3; i++)
		{
			items.pop_back();

		}
	}
}

void Player::clearVector()
{
	items.clear();
}


Player::Player()
{
}

Player::~Player()
{
}
