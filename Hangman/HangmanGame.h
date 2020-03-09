#pragma once
class HangmanGame
{
public:
	std::string m_stGivenWord;
	std::string HANGING_PLAYER_NAME;
	std::string playerInput;
	int HANGING_CHANCE_MAX_NUM;
	int chanceCount;
	bool isPlaying;

	std::vector<std::string>HANGING_GIVEN_WORD_LIST;
	std::vector<std::string> showHiddenWord;

	HangmanGame();

	void SetGivenWrd();
	void SetHiddenWrd();
	void ShowHiddenWord();

	void PlayGame();
	void ChancesCounter();
	void TakeLowerOrUpperCase();
	void CheckWinLetterByLetter();
	void CheckWinIfWholeWord();
	void CheckIfGameOverByChances();
	void HangmanGraphicDisplay();

	~HangmanGame();
};
