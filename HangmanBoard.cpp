#include <iostream>
#include <vector>
#include "HangmanBoard.h"
#include "HangmanGame.h"

using namespace std;

HangmanBoard::HangmanBoard( ) {
	miss = 0;
	numLetters = 0;
	wordsGuessed = 0;
	check = 0;
}

void HangmanBoard::setNumLetters(int num) {

	int i = 0;

	numLetters = num;
	cout << "Word: ";
	for(i=0;i<numLetters;i++) {
		blanks.push_back('_');
		cout << blanks[i] << " ";
	}
	cout << endl;
}

void HangmanBoard::getPicture( ) {

	switch(miss) {
		case 0:
			cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||            ó\n    ||\n    ||\n    ||\n    ||\n    ||\n    ||\n ==========================\n" << endl;
		break;
		case 1:
			cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||          (ಠ_ಠ)\n    ||\n    ||\n    ||\n    ||\n    ||\n    ||\n ==========================\n" << endl;
		break;
		case 2:
			cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||          (ಥ_ಥ)\n    ||            Y\n    ||            |\n    ||\n    ||\n    ||\n    ||\n ==========================\n" << endl;
		break;
		case 3:
			cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||          (Ͼ˳Ͽ)\n    ||            Y\n    ||            |\n    ||           /\n    ||\n    ||\n    ||\n ==========================\n" << endl;
		break;
		case 4:
			cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||          (◕_◕)\n    ||            Y\n    ||            |\n    ||           / \\\n    ||\n    ||\n    ||\n ==========================\n" << endl;
		break;
		case 5:
			cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||          (Ͼ˳Ͽ)..!!\n    ||           /Y\n    ||            |\n    ||           / \\\n    ||\n    ||\n    ||\n ==========================\n" << endl;
		break;
		case 6:
			cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||          (x_x)\n    ||           /Y\\\n    ||            |\n    ||           / \\\n    ||\n    ||\n    ||\n ==========================\n" << endl;
		break;
		case 7:
			cout << "\n    ===============\n    ||  /         |\n    ||/           |\n    ||            0\n    ||           /Y\\\n    ||            |\n    ||           / \\\n    ||\n    ||\n    ||\n ==========================\n" << endl;
	}
}

void HangmanBoard::setMissedLetter(char c) {

	int i = 0;
	missedLetters[miss] = c;
	miss++;
//	cout << "setmissedLetter: " << miss << endl;
}

void HangmanBoard::setMissedLetter() {

	miss++;
//	cout << "setmissed anonymous: " << miss << endl;
}

void HangmanBoard::getMissedLetters( ) {

	int i = 0;

	cout << "Misses: ";
	for(i=0;i<miss;i++) {
		cout << missedLetters[i] << " ";
	}
	cout << endl;
}

void HangmanBoard::setBlanks(char c, int position) {

	blanks[position-1] = c;
	check++;

}

void HangmanBoard::getWord( ) {

	int i = 0;

	cout << "Word: ";
	for(i=0;i<numLetters;i++) {
		cout << blanks[i] << " ";
	}
	cout << endl;
}
