#pragma once

class Locations
{
private:
	string answer;
	const string wrongAnsw = "That is not an option, try again";
public:
	// Variabler
	string choice1 = "1. Hairpin ";
	string choice2 = "2. Harry Potter book ";
	string choice3 = "3. Nail-file ";
	string teleBoss = "";
	int i_bullen;
	int i_dice;
	string choiceCoins = "|| 3. some coins";
	
	// Bools till spel funktioner
	bool if_choice1 = true;
	bool if_choice2 = true;
	bool if_choice3 = true;
	int coins; // Använd till telefonen
	bool if_teleBoss = false;


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

	// Bools till händelser i platser
	bool b_fikatable;
	bool b_telephone;
	bool b_callMother;
	bool b_callDevelopers;
	bool b_callBoss;

	// Bools till items
	bool b_scissors = false; // Denna är false tills spelaren tar sax:en, då blir den true.
	bool b_bloodyUniform = false;
	bool b_cleanUniform = false;
	bool b_coins = false; // blir true om spelaren hittar coins
	bool b_choiseCoins = true; // blir false om du tar uniform + coins

public: // Enum's

	enum yesNo
	{
		yes = '1', no
	};
	enum playeractions
	{
		e_inventory = '0'
	};
	enum locations
	{
		e_cellA = '1', e_cellCorridor, e_cellB, e_securityroom, e_mainCorridor,
		e_farCorridor, e_fikaroom, e_lockerroom, e_mainEntrance
	};
	enum chances
	{
		e_hairpin = '1', e_harryPotter, e_nailfile
	};
	enum cellBitems
	{
		e_scissor = '1', e_bazooka, e_ak47, e_kpist
	};
	enum fikaroom
	{
		e_fikatable = '1',  e_telephone
	};
	enum fikatable
	{
		e_bulle = '1', e_dice,
	};
	enum phonenumbers
	{
		e_mother = '1', e_developers, e_boss
	};
	enum lockerroomChoice
	{
		wash = '1', open = '2'
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

	// Plats specifika händelser
	void fikatable();
	void telephone();
	void callMother();
	void callDevelopers();
	void callBoss();

	// Spel funktioner
	void fillItems();
	void gameover();

public:
	Locations();
	~Locations();
};

