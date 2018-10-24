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


public:
	Player();
	~Player();
};

