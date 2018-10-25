#pragma once

class Locations
{
private:
	string answer;
public:
	// Variabler
	string choice1 = "1. Hairpin ";
	string choice2 = "2. Harry Potter book ";
	string choice3 = "3. Nail-file ";
	bool if_choice1 = true;
	bool if_choice2 = true;
	bool if_choice3 = true;
	int coins; // Använd till telefonen


	// Bools till platser
	bool b_cellA;
	bool b_cellCorr;
	bool b_cellB;
	bool b_secroom;
	bool b_mainCorr;
	bool b_farCorr;
	bool b_fikaroom;
	bool b_lockerroom;
	bool b_mainEntr;
	bool b_fikatable;
	bool b_telephone;


	// Bools till items
	bool b_scissors = false; // Denna är false tills spelaren tar sax:en, då blir den true.
	bool b_bloodyUniform = false;
	bool b_cleanUniform = false;

public: // Enum's

	enum locations
	{
		e_cellA = '1', e_cellCorridor, e_cellB, e_securityroom, e_mainCorridor,
		e_farCorridor, e_fikaroom, e_lockerroom, e_mainEntrance
	};
	enum chances
	{
		e_hairpin = '1', e_harryPotter, e_nailfile, e_inventory = '0'
	};
	enum cellBitems
	{
		e_scissor = '1', e_bazooka, e_ak47, e_kpist
	};
	enum fikaroom
	{
		e_fikatable = '1', e_bulle, e_dice, e_telephone
	};
	enum phonenumbers
	{
		e_mother = '1', e_boss, e_developers
	};
	enum yesNo
	{
		yes = '1', no
	};
	enum lockerroomChoice
	{
		wash = '1', open = '2'
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
	void gameover();

public:
	Locations();
	~Locations();
};

