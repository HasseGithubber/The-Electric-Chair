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
	void clearVector();

public:
	Player();
	~Player();
};

