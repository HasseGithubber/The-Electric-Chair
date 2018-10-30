#pragma once
#include <vector>
class Player
{
public:
	string name;
	vector<string> items;

	//Items
	string s_scissor = "Scissors";
	string s_bloodyUniform = "Bloody Uniform";
	string s_cleanUniform = "Clean uniform";
	string s_coins = "Some coins ";

public:
	void inventory();
	void startInventory();
	int pushBack(int);
	void giveItem(int a);
	void changeUniform();
	void clearVector();
	void changeCoins();
	void ClearExtraItems();

public:
	Player();
	~Player();
};

