#include "pch.h"
#include "Player.h"
#include <iomanip>


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
	items.push_back("Hårnål");
	items.push_back("Harry Potter bok");
	items.push_back("Nagelfil");

}

int Player::pushBack(int x) {

	if (x == 1)
	{ 
		items[0] = "Broken Hårnål";
	}
	else if (x == 2)
	{
		items[1] = "Broken book";
	}
	else if (x == 3)
	{
		items[2] = "Broken Nail-File";
	}

	return 0;

}





Player::Player()
{
}

Player::~Player()
{
}
