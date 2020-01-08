#pragma once
class RandomWords
{
public:
	RandomWords();
	~RandomWords();
	
	std::vector <std::string> WordList;
	std::string RandomWord();
};

