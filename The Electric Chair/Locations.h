#pragma once

class Locations
{
public:
	// Variabler
	char answer;


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

