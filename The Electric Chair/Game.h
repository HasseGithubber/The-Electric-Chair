#pragma once
class Game
{
private:
	string answer;

public:
	// string variabler
	string s_name;
	string s_seller;

	// int vairabler
	int diceResult;
	int bulleOutcome;

	// enums
	enum game
	{
		startgame = '1', exitgame = '2'
	};

public:
	// Game funktioner
	void intro();
	void menu();
	void start();
	void victory();

public:
	// Mekaniska spel funktioner
	void pause(int a, int b);
	int bulle();
	int dice();
	int randSeller();

public:
	Game();
	~Game();
};

