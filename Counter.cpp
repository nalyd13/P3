#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <vector>

using namespace std;

int main() {

char get;
char alpha[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int alphaCount[26] = {0};
int alphaWordCount[26] = {0};
int uniqueLetterAppearance[26] = {0};
int excludeLetters[26] = {0};
int ndx, ndx2;
int numLetters = 0, max_letter_count = 0;

vector<string> initial_wordList; 
vector<string> refined_wordList;
vector<string> tmp_wordList;

int numLetters_words;

string word;
long int Counter = 0, Counter1= 0, count = 0, count1 = 0;

char tried[26]; // array of guesses (max 26)
int guess_index = 0; // running number of guesses

string in_word; // decision variable for whether or not (y/n) the letter is in the word
int correct_letter_count; // position(s) of correctly guessed letters in word
vector<int> position;

int tmp_position;

int add_word_flag = 0;
int test=0, test2=0;

cout << "How many letters? ";
cin >> numLetters;

ifstream in_s;

in_s.open("dictionary.txt");


// create initial list of 'numLetters' length words 
while(in_s >> word) {
	if(word.length() == numLetters) {
		word[0] = tolower(word[0]);
		
		for(count=0;count<numLetters;count++) {
			get = word[count];

			// this loop works the same way as the original switch statement
			// count letter occurance frequency of each word
			for(ndx=0;ndx<26;ndx++){
				if(get == alpha[ndx]){
					alphaCount[ndx]++;
					uniqueLetterAppearance[ndx] = 1; // count non-duplicate letters of each word
				} 
			}

		}

		// count number of words each letter appears in
		for(ndx=0;ndx<26;ndx++){
			if(uniqueLetterAppearance[ndx] == 1){
				alphaWordCount[ndx]++;
			}
			uniqueLetterAppearance[ndx] = 0; // reset flag variable
		}

		// if word is of correct length, add to wordList
		initial_wordList.push_back(word);
		Counter++;
	
	}
}



for(count1=0;count1<26;count1++) {
	if(alphaCount[count1] > max_letter_count) {
		max_letter_count = alphaCount[count1];
	}
}

cout << Counter << " " << numLetters << " letter words." << endl;
numLetters_words = initial_wordList.size();
cout << "numLetters words = " << numLetters_words << endl;

cout << "first word: " << initial_wordList[0] << endl;
cout << "last word: " << initial_wordList[Counter - 1] << endl;


// print all occurances of letters
for(ndx=0;ndx<26;ndx++){
	cout << alpha[ndx] << " found " << alphaCount[ndx] << " times in " << alphaWordCount[ndx] << " words " << endl;
	cout << "Relative probability of duplicate letters: " << (static_cast<float>(alphaCount[ndx])/static_cast<float>(alphaWordCount[ndx])) - 1 << endl;
	cout << endl;
}

cout << max_letter_count << endl;

for(count1=0;count1<26;count1++) {
	if(alphaCount[count1] == max_letter_count) {
		cout << "Guess X should be the letter " << "'" << alpha[count1] << "'" << endl;
		tried[guess_index] = alpha[count1];
	}
}


cout << "is the letter " << "'" << tried[guess_index] << "'" << " in the word? (y/n)" << endl;
cin >> in_word;

if(in_word == "y"){
	cout << "How many times does the letter " << "'" << tried[guess_index] << "'" << " occur?" << endl;
	cin >> correct_letter_count;
	for(ndx=0; ndx < correct_letter_count; ndx++){
		cout << "occurance " << ndx+1 << " is at position: " << endl;
		cin >> tmp_position;
		position.push_back(tmp_position);

	}

	cout << "The letter " << "'" << tried[guess_index] << "'" << " appears at positions: " << endl;
	for(ndx=0;ndx<correct_letter_count;ndx++){
		cout << position[ndx] << endl;
	}

} else{
	excludeLetters[count1] = 1; // this letter is a miss
}



for(ndx=0;ndx<numLetters_words;ndx++) {
	test++;
		for(ndx2=0; ndx2 < correct_letter_count; ndx2++){
			if(initial_wordList[ndx][position[ndx2]-1] == tried[guess_index]){
				add_word_flag++;
				if(add_word_flag == correct_letter_count){
        			refined_wordList.push_back(initial_wordList[ndx]);
        			Counter1++;
        		}
			}
		}
	add_word_flag = 0;
}

cout << endl;
cout << test << " " << tried[guess_index] << endl;
cout << test2 << " words of length " << numLetters << endl;
cout << Counter1 << " words after filter "<< guess_index+1 << endl;
for(ndx=0;ndx<Counter1;ndx++){
	cout << refined_wordList[ndx] << endl;
}





in_s.close();

}
