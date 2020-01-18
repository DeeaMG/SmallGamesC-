#include "pch.h"
#include <iostream>
#include "CowsAndBullsGame.h"

int main()
{
	std::string getAnswer = "yes";
	while (getAnswer == "yes")
	{
		CowsAndBulls game;
		game.PlayGame();

		std::cout << "\nDo you want to play again? ";
		std::cin >> getAnswer;
	}
	std::cout << "Thank you for playing!" << std::endl;
}