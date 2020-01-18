#pragma once

#include <random>
#include <ctime>

class CowsAndBulls
{
public:

	std::string searchedNumber;
	std::string playerInput;
	bool isPlaying;
	int cows_count;
	int bulls_count;
	int number_of_attempts;
	int max_number_of_attempts;
	
	CowsAndBulls();
	~CowsAndBulls();

	void PlayGame();
	int GetRandomNum();
	void PlayerInput(std::string & playerInput);
	void GetBulls();
	bool ScanIfCows(char number, int index);
	void GetCows();
	void CheckWin();
	void CheckIfMAxAttempts();

};