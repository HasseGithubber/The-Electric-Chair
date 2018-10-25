#pragma once
class Game
{
private:
	//regler
public:
	//regel funktioner
public:
	// Variabler
	char answer;
	string s_answer;
	int diceResult;
	int bulleOutcome;

	enum game
	{
		startgame = '1', exitgame = '2'
	};


	// Class objects
	//Player player;
	//Locations locate;

public:
	void intro();
	void menu();
	void start();
	void victory();

	// Ändra dessa, debugg Locations?
	void gameover();

public:
	// Mekaniska spel funktioner
	int bulle();
	int dice();

public:
	Game();
	~Game();
};

