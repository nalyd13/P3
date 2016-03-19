#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "HangmanBoard.h"
#include "HangmanGame.h"

using namespace std;

HangmanGame::HangmanGame( ) {

	int i = 0;

	alpha = "abcdefghijklmnopqrstuvwxyz";
	for(i=0;i<26;i++) {
		alphaCount[i] = 0;
		exclude[i] = 0;
	}
}

void HangmanGame::getDictFile(int num) {

	numLetters = num;

	fstream in_s;
	in_s.open("Dictionary.txt");

	while(in_s >> word){
		if(word.length( ) == numLetters) {
			word[0] = tolower(word[0]);
			/*
			if(word != wordList[wordList.size()-1] || wordList.size() == 0){
			}
			*/

		wordList.push_back(word); // if correct length, add to wordList
		}
	}

	in_s.close( );
}

//this isnt really needed
//void HangmanGame::getWordList( ) {

//	cout << wordList.size( ) << " words left" << endl;
//}

char HangmanGame::getMaxChar( ) {

	int i = 0, j = 0, k = 0, max = 0, maxChar = 0;

	for(i=0;i<wordList.size( );i++) {
		for(j=0;j<numLetters;j++) {
			for(k=0;k<26;k++) {
				if(wordList[i][j] == alpha[k]) {
					if(exclude[k] == 0){
						alphaCount[k]++;
					}
				}
			}
		}
	}

	for(i=0;i<26;i++) {
		if(alphaCount[i] > max) {
			max = alphaCount[i];
			maxChar = i;
		}

//		cout << alpha[i] << " " << alphaCount[i] << endl;
	}

	exclude[maxChar] = 1;

	for(i=0;i<26;i++) {
		alphaCount[i] = 0;
	}

	if(max == 0){
		cout << "This word does not exist." << endl;
		//run = 0; run undefined ?
	}

	return alpha[maxChar];
}

void HangmanGame::setPosition(int location, int i){
	position.push_back(location);
	cout << position[i] << endl;
}

void HangmanGame::checkLetterYes(char c, int count) {

	int i = 0, j=0, k=0;
	string word;
	int flag1 = 0;
	int flag2 = 0;

	for(i=0;i<wordList.size( );i++) {
		word = wordList[i];
		for(j=0;j<numLetters;j++){
			if(word[j] == c) {
				flag1++;
			}	
		}	

		for(k=0;k<count;k++){
			if(word[position[k]-1] != c){
				flag2 = 1;
			}
		}

		if (flag1 == count && flag2 == 0){
			tempList.push_back(word);
		}

		flag1 = 0;
		flag2 = 0;
	}

	//cout << "new word list: " << tempList.size() << endl;
}


void HangmanGame::checkLetterNo(char c) {

	int i = 0, j=0;
	string word;
	int flag1 = 0;

	for(i=0;i<wordList.size( );i++) {
		word = wordList[i];
		for(j=0;j<numLetters;j++){
			if(word[j] == c) {
				flag1++;
			}	
		}	

		if (flag1 == 0){
			tempList.push_back(word);
		}

		flag1 = 0;
	}

	//cout << "new word list: " << tempList.size() << endl;
}

int HangmanGame::swapWordList(int run){
	wordList.clear();
	int i = 0;
	string is_word;

	for(i=0;i<tempList.size();i++){
		wordList.push_back(tempList[i]);
	}
	tempList.clear();
//	cout << "new word list: " << wordList.size() << endl;

//	cout << "miss count: " << miss << endl;

	position.clear();

	cout << check << endl;

	if(miss == 6 || wordList.size() == 1 || check == numLetters){
		run = 0;
	}

	else if(6 - miss >= wordList.size()){
		for(i=0;i<wordList.size();i++){
			cout << "is your word " << wordList[i] << "? (y/n)" << endl;
			cin >> is_word;
			if(is_word == "y"){
				i = wordList.size();
				run = 0;
			} else {
				wordsGuessed++;
				if(wordsGuessed == wordList.size()){
					cout << "This is not a valid word." << endl;
					run = 0;
				}
				HangmanBoard::setMissedLetter( );
				HangmanBoard::getPicture( );
			}
		}	
	}

	return run;

}

int HangmanGame::checkGame(int run){

        if(miss == 6 || check == numLetters){
                run = 0;
        }

 /*       else if(6 - miss >= wordList.size()){
                for(i=0;i<wordList.size();i++){
                        cout << "is your word " << wordList[i] << "? (y/n)" << endl;
                        cin >> is_word;
                        if(is_word == "y"){
                                i = wordList.size();
                                run = 0;
                        } else {
                                wordsGuessed++;
                                if(wordsGuessed == wordList.size()){
                                        cout << "This is not a valid word." << endl;
                                        run = 0;
                                }
                                HangmanBoard::setMissedLetter( );
                                HangmanBoard::getPicture( );
                        }
                }
        }
*/
        return run;

}
