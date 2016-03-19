#ifndef HANGMANBOARD_H
#define HANGMANBOARD_H

#include <iostream>
#include <vector>

using namespace std;

class HangmanBoard {
	private:
	vector<char> blanks;
	char missedLetters[6];
	protected:
	int numLetters;
	int miss;
	int wordsGuessed;
	int check;
	public:
	HangmanBoard( );
	void setNumLetters(int);
	void getPicture( );
	void setMissedLetter(char);
	void setMissedLetter();
	void getMissedLetters( );
	void setBlanks(char, int);
	void getWord( );

};

#endif
