// Attention! Header includes; <iostream>, <string>, <cstdlib>, <ctime>, using namespace std,

//                                  #######
//                                  #######
//                                  #
//                                  #
//		            **********************
//		         **** ## ******** ##  ## *****
//		      ******* ## ******** ###### *******
//		   ********** ##### ***** ##  ## **********
//		**********************************************
//		**											**
//		**	Vårt textäventyr version 0.1			**
//		**	ELECTRIC CHAIR							**
//		**	GRUPP Bulle								**
//		**	Linda Lindgren							**
//		**	Hans-Erik Eriksson						**
//		**											**
//		**	0.1 2018-10-24 Linda & Hasse			**
//		**	Påbörjat strukturen						**
//		**											**
//		**	0.2	2018-10-25 Linda & Hasse			**
//		**	Fortsättning följer						**
//		**********************************************
//		**********************************************

#include "pch.h"
#include "Game.h"
#include "Player.h"


int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	Game play;
	play.intro();




	return 0;

}
