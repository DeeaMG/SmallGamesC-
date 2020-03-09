#include "pch.h"
#include "HangmanGame.h"
#include <iostream>

int main()
{
	std::string getAnswer = "yes";
	while (getAnswer == "yes")
	{
		HangmanGame game;
		game.PlayGame();

		std::cout << "Do you want to play again? ";
		std::cin >> getAnswer;
		std::cout << std::endl;
	}
	std::cout << "Thank you for playing!" << std::endl;
}
