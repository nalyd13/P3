#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <iostream>
#include <vector>
#include <string>
#include "HangmanGame.h"

using namespace std;

class HangmanGame : public HangmanBoard{
	private:
	string alpha;
	vector<string> wordList;
	vector<string> tempList;
	string word;
	int numLetters;
	int alphaCount[26];
	int exclude[26];
	vector<int> position;
	public:
	HangmanGame( );
	void getDictFile(int);
//	void getWordList( );
	char getMaxChar( );
	void checkLetterYes(char, int);
	void checkLetterNo(char);
	void setPosition(int, int);
	int swapWordList(int);
	int checkGame(int);
};

#endif
