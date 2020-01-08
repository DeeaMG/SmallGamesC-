#include "pch.h"
#include "RandomWords.h"
#include <random>
#include <ctime>


RandomWords::RandomWords()
{
	WordList = { "acres", "adult", "advice", "arrangement", "attempt", "August", "Autumn" };
}

RandomWords::~RandomWords()
{
}

std::string RandomWords::RandomWord()
{
	int rand_i;
	
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::uniform_int_distribution<int> randNum(0, WordList.size() - 1);
	
	rand_i = randNum(mersenne);
	
	return WordList[rand_i];
}
