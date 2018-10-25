#pragma once
class Game
{
private:
	string answer;

public:
	// Variabler
	string s_answer;

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
	Game();
	~Game();
};

