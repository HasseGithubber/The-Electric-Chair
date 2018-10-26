#pragma once
class Game
{
private:
	string answer;

public:
	// Variabler
	string s_answer;
	int diceResult;
	int bulleOutcome;

	enum game
	{
		startgame = '1', exitgame = '2'
	};



public:
	void intro();
	void menu();
	void start();
	void victory();



public:
	// Mekaniska spel funktioner
	void pause(int a, int b);
	int bulle();
	int dice();

public:
	Game();
	~Game();
};

