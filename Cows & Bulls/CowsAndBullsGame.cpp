#include "pch.h"
#include "CowsAndBullsGame.h"

CowsAndBulls::CowsAndBulls()
{
	searchedNumber = std::to_string(GetRandomNum());
	cows_count = 0;
	bulls_count = 0;
	isPlaying = true;
	number_of_attempts = 1;
	max_number_of_attempts = 10;
}

int CowsAndBulls::GetRandomNum()
{
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::uniform_int_distribution<int> randNum(1000, 9999);

	return (randNum(mersenne));
}

void CowsAndBulls::PlayGame()
{
	while (isPlaying)
	{
		//std::cout << searchedNumber << std::endl; 
		printf("\n%d. Enter your guess: ", number_of_attempts);
		std::cin >> playerInput;
		PlayerInput(playerInput);
		GetBulls();
		GetCows();
		printf("bulls= %d, cows= %d\n", bulls_count, cows_count);
		CheckIfMAxAttempts();
		CheckWin();
		number_of_attempts += 1;
	}
}

void CowsAndBulls::PlayerInput(std::string & playerInput)
{
	while (playerInput.length() != 4)
	{
		std::cout << "Enter your guess: (4 digits)";
		std::cin >> playerInput;
	}
}

void CowsAndBulls::GetBulls()
{
	for (int i = 0; i < playerInput.length(); i++)
	{
		if (playerInput[i] == searchedNumber[i])
		{
			bulls_count += 1;
			cows_count = 0;
		}
	}
}

bool CowsAndBulls::ScanIfCows(char number, int index)
{
	const size_t pos = searchedNumber.find(number);
	if (pos == -1) 
		return true;

	return pos == index;
}

void CowsAndBulls::GetCows()
{
	for(unsigned int i = 0; i < playerInput.length(); i++)
	{
		const bool result = ScanIfCows(playerInput[i], i);
		if (!result) 
			cows_count += 1;
	}
}

void CowsAndBulls::CheckWin()
{
	if (playerInput == searchedNumber)
	{
		printf("_________________________\nCongratulations! You won!\n");
		printf("You managed to win from %d attempts.\n", number_of_attempts);
		isPlaying = false;
	}
	else if (playerInput != searchedNumber)
	{
		bulls_count = 0;
		cows_count = 0;
	}
}

void CowsAndBulls::CheckIfMAxAttempts()
{
	if (number_of_attempts == max_number_of_attempts)
	{
		printf("You ran out of attempts! You lost the game!\nThe number was %s.\n", searchedNumber.c_str());
		isPlaying = false;
	}
}

CowsAndBulls::~CowsAndBulls()
{
}
