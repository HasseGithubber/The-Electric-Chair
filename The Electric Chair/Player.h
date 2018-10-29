#pragma once
#include <vector>
class Player
{

public:
	string name;
	vector<string> items;

public:
	void inventory();
	void startInventory();
	int pushBack(int);
	void ItemScissors();
	void ItemBloodyUniform();
	void ItemCleanUniform();
	void changeUniform();
	void clearVector();
	void ItemCoins();
	void changeCoins();
	void ClearExtraItems();

public:
	Player();
	~Player();
};

