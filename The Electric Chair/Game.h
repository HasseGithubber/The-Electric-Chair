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

	// Class objects
	//Player player;
	//Locations locate;

public:
	void intro();
	void menu();
	void start();
	void victory();
	
public:
	Game();
	~Game();
};

