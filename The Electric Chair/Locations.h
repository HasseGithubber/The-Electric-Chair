#pragma once

class Locations
{
private:
	string answer;
	const string wrongAnsw = "That is not an option, try again";
public:
	// String Variabler
	string s_choice1 = "1. Hairpin ";
	string s_choice2 = "2. Harry Potter book ";
	string s_choice3 = "3. Nail-file ";
	string s_farCorrIntro = "You hear some voices coming from the main entrance to the right, to the left the corridor just keeps going.\n";
	string s_farCorr = "6. Continue the corridor ";
	string s_fikaRoom = "";
	string s_lockerRoom = "";
	string s_teleBoss = "";
	string s_bossAway = "Some old guy answered the phone, but you hung up on him.\n";
	string s_choiceCoins = "|| 3. some coins";
	string s_seller = "Hi! Do you want to buy our magnificent vacuum cleaners? Ofcourse you do, and we got a special price for you just TODAY! Just confirm the payment and get an extra pack of vacuum bags for free!\n";
	string s_bossSeller = "Why don't you take those extra bags and shove'em up where the sun don't shine... *click*\n.";
	string choice1 = "1. Hairpin ";
	string choice2 = "2. Harry Potter book ";
	string choice3 = "3. Nail-file ";
	string teleBoss = "";
	string choiceCoins = "|| 4. some coins";
	string seller;

	// till titlar
	string titleCellCorridor = " ||             Cell Corridor            || ";
	string titleCellA = " ||                 Cell A               || ";
	string titleCellB = " ||                 Cell B               || ";
	string titleSecurityRoom = " ||             Security Room            || ";
	string titleMainCorridor = " ||             Main Corridor            || ";
	string titleFikaroom = " ||               Fika Room              || ";
	string titleLockerroom = " ||              Lockerroom              || ";
	string titleMainEntrance = " ||             Main Entrance            || ";
	
	// Int variabler
	int i_bullen;
	int i_dice;
	int i_coins = 0; // Använd till telefonen och washing machine
	
	// Bools till spel funktioner
	bool if_choice1 = true;
	bool if_choice2 = true;
	bool if_choice3 = true;
	bool if_teleBoss = false;

	// Bools till platser
	bool b_cellA = true;
	bool b_cellCorr;
	bool b_cellB;
	bool b_secroom;
	bool b_mainCorr;
	bool b_farCorr;
	bool b_fikaroom;
	bool b_lockerroom;
	bool b_mainEntr;
	bool b_gameOver = true;

	// Bools till händelser i platser
	bool b_farCorrHide = true;
	bool b_fikaRoomReveal = false;
	bool b_lockerRoomReveal = false;
	bool b_fikatable;
	bool b_telephone;
	bool b_callMother;
	bool b_callDevelopers;
	bool b_callBoss;
	bool b_bossSeller;
	bool b_bossAway = false; // Win condition
	bool b_locker;

	// Bools till items
	bool b_scissors = false; // Denna är false tills spelaren tar sax:en, då blir den true.
	bool b_bloodyUniform = false;
	bool b_cleanUniform = false;
	bool b_coins = false; // blir true om spelaren hittar coins


public: // Enum's

	enum yesNo
	{
		yes = 'y', no = 'n'
	};
	enum playeractions
	{
		e_inventory = 'i', e_hangup = 'h'
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
	enum fikaroomChoices
	{
		e_fikatable = '1',  e_telephone
	};
	enum fikatableChoices
	{
		e_bulle = '1', e_dice,
	};
	enum phonenumbers
	{
		e_mother = '1', e_developers, e_boss
	};
	enum talkMother
	{
		e_money = '1', e_pretty, e_birthday
	};
	enum talkDeveloper
	{
		e_suck = '1', e_fantastic, e_help
	};
	enum talkBoss
	{
		e_introduce = '1', e_hospital, e_seller, e_donuts 
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
	//void callBoss();
	void washing();
	void locker();

	void callBoss();
	//void bossSeller();

	// Spel funktioner
	void fillItems();
	void CleanItems();
	void gameover();
	void menu(string, int);

public:
	Locations();
	~Locations();
};

