#pragma once
#include <vector>
class Player
{
public:
	// Variabler
	string name;

public:

	vector<string> items;

	// Till senare
	/*
	items.push_back("Dirty Uniform");
	items.push_back("broken hårnål");
	items.push_back("broken nagelfil");
	items.push_back("broken Harrypotter Bok");
	*/

public:
	void inventory();

public:
	Player();
	~Player();
};

