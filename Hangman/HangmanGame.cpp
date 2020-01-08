#include "pch.h"
#include "HangmanGame.h"
#include "RandomWords.h"
#include <algorithm>
#include <iostream>


HangmanGame::HangmanGame()
{
	RandomWords generator;
	
	m_stGivenWord = generator.RandomWord();
	std::cout << "Enter your name: ";
	std::cin >> HANGING_PLAYER_NAME;
	HANGING_CHANCE_MAX_NUM = 6;
	chanceCount = 0;
	isPlaying = true;
	
	SetGivenWrd();
	SetHiddenWrd();
	ShowHiddenWord();
}

void HangmanGame::PlayGame()
{
	while (isPlaying)
	{
		std::cout << "Enter a letter/whole word here: ";
		std::cin >> playerInput;
		std::cout << std::endl;

		ChancesCounter();
		HangmanGraphicDisplay();
		CheckIfGameOverByChances();
		CheckWinIfWholeWord();
		CheckWinLetterByLetter();
	}
}

void HangmanGame::SetGivenWrd()
{
	for (size_t i = 0; i < m_stGivenWord.length(); ++i)
	{
		HANGING_GIVEN_WORD_LIST.push_back(std::string(1, m_stGivenWord[i]));
	}
	std::cout << std::endl;
}

void HangmanGame::SetHiddenWrd()
{
	std::string var(1, m_stGivenWord[0]);
	showHiddenWord.push_back(var);
	
	for (unsigned int i = 1; i < m_stGivenWord.length(); ++i)
	{
		if (m_stGivenWord[i] == ' ')
			showHiddenWord.push_back(" ");
		else
			showHiddenWord.push_back("_");
	}
}

void HangmanGame::ShowHiddenWord()
{
	TakeLowerOrUpperCase();
	if (playerInput == m_stGivenWord) std::cout << playerInput;
	else
	{
		for (unsigned int j = 0; j < showHiddenWord.size(); ++j)
		{
			std::cout << showHiddenWord[j] << " ";
		}
	}
	
	std::cout << std::endl;
}

void HangmanGame::TakeLowerOrUpperCase()
	{
	std::string upperPlayerInput = playerInput;
	std::transform(upperPlayerInput.begin(), upperPlayerInput.end(), upperPlayerInput.begin(), ::toupper);

	for (unsigned int i = 0; i < HANGING_GIVEN_WORD_LIST.size(); i++)
	{
		if (playerInput == HANGING_GIVEN_WORD_LIST[i])
		{
			showHiddenWord[i] = playerInput;
		}
		else if (upperPlayerInput == HANGING_GIVEN_WORD_LIST[i])
		{
			showHiddenWord[i] = upperPlayerInput;
		}
	}
	}

void HangmanGame::ChancesCounter()
{
	int notFound = 0;
	for (unsigned int i = 0; i < HANGING_GIVEN_WORD_LIST.size(); ++i)
	{
		if (playerInput != HANGING_GIVEN_WORD_LIST[i])
			notFound += 1;
	}
	
	if (notFound == HANGING_GIVEN_WORD_LIST.size()) 
		chanceCount += 1;
}

void HangmanGame::CheckWinLetterByLetter()
{
	if (showHiddenWord == HANGING_GIVEN_WORD_LIST)
	{
		isPlaying = false;
		printf("%s won.\n________________\nCongratulations!\n\n", HANGING_PLAYER_NAME.c_str());
	}
	
}

void HangmanGame::CheckWinIfWholeWord()
{
	if (playerInput == m_stGivenWord)
	{
		isPlaying = false;
		printf("%s won.\n________________\nCongratulations!\n\n", HANGING_PLAYER_NAME.c_str());
	}
}

void HangmanGame::CheckIfGameOverByChances()
{
	std::string upperGivenWrd = m_stGivenWord;
	std::transform(upperGivenWrd.begin(), upperGivenWrd.end(), upperGivenWrd.begin(), ::toupper);
	if (chanceCount == HANGING_CHANCE_MAX_NUM)
	{
		printf("%s ran out of chances.\nGame over...\nThe word was: %s\n\n",
				HANGING_PLAYER_NAME.c_str(), upperGivenWrd.c_str());
		isPlaying = false;
	}
}

void HangmanGame::HangmanGraphicDisplay()
{
	if (chanceCount == 0)
	{
		std::cout << "________      " << std::endl;
		std::cout << "|      |      " << std::endl;
		std::cout << "|             " << std::endl;
		std::cout << "|             " << std::endl;
		std::cout << "|             " << std::endl;
		std::cout << "|__________   " << std::endl;
	}


	else if (chanceCount == 1)
	{
		std::cout << "________      " << std::endl;
		std::cout << "|      |      " << std::endl;
		std::cout << "|      O      " << std::endl;
		std::cout << "|             " << std::endl;
		std::cout << "|             " << std::endl;
		std::cout << "|__________   " << std::endl;
	}


	else if (chanceCount == 2)
	{
		std::cout << "________      " << std::endl;
		std::cout << "|      |      " << std::endl;
		std::cout << "|      0      " << std::endl;
		std::cout << "|     /       " << std::endl;
		std::cout << "|             " << std::endl;
		std::cout << "|__________   " << std::endl;
	}


	else if (chanceCount == 3)
	{
		std::cout << "________      " << std::endl;
		std::cout << "|      |      " << std::endl;
		std::cout << "|      O      " << std::endl;
		std::cout << "|     /|      " << std::endl;
		std::cout << "|             " << std::endl;
		std::cout << "|__________   " << std::endl;
	}


	else if (chanceCount == 4)
	{
		std::cout << "________      " << std::endl;
		std::cout << "|      |      " << std::endl;
		std::cout << "|      O      " << std::endl;
		std::cout << "|     /|\\    " << std::endl;
		std::cout << "|             " << std::endl;
		std::cout << "|__________   " << std::endl;
	}


	else if (chanceCount == 5)
	{
		std::cout << "________      " << std::endl;
		std::cout << "|      |      " << std::endl;
		std::cout << "|      O      " << std::endl;
		std::cout << "|     /|\\    " << std::endl;
		std::cout << "|     /       " << std::endl;
		std::cout << "|__________   " << std::endl;
	}


	else if (chanceCount == 6)
	{
		std::cout << "________      " << std::endl;
		std::cout << "|      |      " << std::endl;
		std::cout << "|      O      " << std::endl;
		std::cout << "|     /|\\    " << std::endl;
		std::cout << "|     / \\    " << std::endl;
		std::cout << "|__________   " << std::endl;
	}

	ShowHiddenWord();
}

HangmanGame::~HangmanGame()
{
}
