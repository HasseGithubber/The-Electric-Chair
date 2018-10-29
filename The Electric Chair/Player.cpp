#include "pch.h"
#include "Player.h"
#include "Locations.h"
#include "Game.h"
#include <iomanip>

// Funktion som skriver ut inventory.
void Player::inventory() {

	cout << "--------------------------------" << "\n Inventory:\n" << "--------------------------------" << endl;
	cout << endl;
	for (unsigned int i = 0; i < items.size(); i++)
	{

		cout << " " << items[i] << endl;

	}

	cout << endl;
	cout << "--------------------------------" << endl << endl;

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

//void Player::ItemScissors()
//{
//	items.push_back("Scissors");
//}
//
//void Player::ItemBloodyUniform() {
//
//	items.push_back("Bloody Uniform");
//}
//
//void Player::ItemCleanUniform() {
//
//	items.push_back("Clean uniform");
//}
//
//void Player::ItemCoins() {
//
//	items.push_back("Some coins ");
//}

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
