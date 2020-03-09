#pragma once
class RandomWords
{
public:
	RandomWords();
	std::vector <std::string> WordList;
	std::string RandomWord();	
	~RandomWords();
};
