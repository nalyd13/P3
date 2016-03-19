#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "HangmanBoard.h"
#include "HangmanGame.h"

using namespace std;

int main() {//int argc, char *argv[]) {

int num = 0, run = 1, count = 0, i = 0, location = 0, mode = 0;
char yesNo, guess;

cout << "Will player 2 (1) or the computer (2) be the guesser? (3 to exit): ";
cin >> mode;

while(mode != 3) {

HangmanGame board1; 

if(mode == 1) {
	cout << "Player 1: ";
}
cout << "Enter the number of letters in the word: ";
cin >> num;

board1.getPicture( );

board1.setNumLetters(num);

board1.getMissedLetters( );

board1.getDictFile(num);

if(mode == 1) {

while(run == 1) {

	cout << "Player 2: Enter your guess: ";
	cin >> guess;

	cout << "Player 1: Is there a(n) " << guess << " in your word? (Y/N): ";
        cin >> yesNo;

        if(yesNo == 'N') {
                board1.setMissedLetter(guess);
                board1.checkLetterNo(guess);
        }
        else {
                cout << "Player 1: How many times does the letter " << "'" << guess << "'" << " occur?";
                cin >> count;

                for(i=0;i<count;i++) {
                        cout << "Player 1: Location " << i+1 << ": ";
                        cin >> location;
                        board1.setPosition(location, i);
                        board1.setBlanks(guess, location);
                }

                board1.checkLetterYes(guess, count);
	}

        board1.getPicture( );

        board1.getWord( );

        board1.getMissedLetters( );

        run = board1.checkGame(run);

}	
}

else if(mode == 2) {

while(run == 1) {

	guess = board1.getMaxChar( );

	cout << "Is there a(n) " << guess << " in your word? (Y/N): ";
	cin >> yesNo;

	if(yesNo == 'N') {
		board1.setMissedLetter(guess);
		board1.checkLetterNo(guess);
	}
	else {
		cout << "How many times does the letter " << "'" << guess << "'" << " occur?";
		cin >> count;

		for(i=0;i<count;i++) {
			cout << "Location " << i+1 << ": ";
			cin >> location;
			board1.setPosition(location, i);
			board1.setBlanks(guess, location);
		}

		board1.checkLetterYes(guess, count);

		//board1.checkLetterPosition(location, board1.getMaxChar( ));
		//board1.setBlanks(board1.getMaxChar( ), location);
		
	}

	board1.getPicture( );

	board1.getWord( );

	board1.getMissedLetters( );

	run = board1.swapWordList(run);

		
}
}
cout << "Will player 2 (1) or the computer (2) be the guesser? (3 to exit): "; 
cin >> mode;
}
}
