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

	enum locations
	{
		e_cellA = '1', e_cellCorridor = '2', e_cellB = '3', e_securityroom = '4', e_mainCorridor = '5',
		e_farCorridor = '6', e_fikaroom = '7', e_lockerroom = '8', e_mainEntrance = '9'
	};
	enum chances
	{
		hairpin = '1', harryPotter = '2', nailfile = '3', inventory = '4'
	};



	enum locations
	{
		cellA1 = 'a', cellCorridor1 = 'b', cellB1 = 'c', securityroom1 = 'd', mainCorridor1 = 'e',
		farCorridor1 = 'f', fikaroom1 = 'g', lockerroom1 = 'h', mainEntrance1 = 'i'
	};

public:
	// Alla platser
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

