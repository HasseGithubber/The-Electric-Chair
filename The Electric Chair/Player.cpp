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


Player::Player()
{
}

Player::~Player()
{
}
