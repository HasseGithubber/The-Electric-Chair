#pragma once

class Locations
{
public:
	// Variabler
	char answer;
	string choice1 = "1. Hairpin ";
	string choice2 = "2. Harry Potter book ";
	string choice3 = "3. Nail-file ";
	bool if_choice1 = true;
	bool if_choice2 = true;
	bool if_choice3 = true;
	bool b_scissors = false; // Denna är false tills spelaren tar sax:en, då blir den true.

	enum locations
	{
		e_cellA = '1', e_cellCorridor, e_cellB, e_securityroom, e_mainCorridor,
		e_farCorridor, e_fikaroom, e_lockerroom, e_mainEntrance
	};
	enum chances
	{
		hairpin = '1', harryPotter, nailfile, inventory = '0'
	};
	enum cellBitems
	{
		scissor = '1', bazooka, ak47, kpist
	};



public:
	// Alla platser
	void fillItems();
	void cellA();
	void cellCorridor();
	void cellB();
	void securityroom();
	void mainCorridor();
	void farCorridor();
	void fikaroom();
	void lockerroom();
	void mainEntrance();

public:
	Locations();
	~Locations();
};

