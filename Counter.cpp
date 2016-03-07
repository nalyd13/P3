#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <vector>

using namespace std;

// if letter is found in every word (e.g. 10 words left and letter is in every word) - guess a different letter
// if only a few words remain, and missed count is not too high, appropriate to start guessing words instead of letters
// 		(e.g. 2 words left and missed count == 3 :: does not make sense to guess letters at this point)
// sort everything into classes and separate files 
// implement possibility of repeated letters ? (to maximize known positions of word and eliminate maximum possible words)
// better handling of word filtering when word count is < 30

void draw(int miss);

int main() {

int numLetters = 0; // length of word to be guessed
int run = 1; // flag variable to determine if the program should continue
char alpha[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int alphaCount[26] = {0}; // array of letter frequency count (non unique letters per word)
int alphaWordCount[26] = {0}; // array of unique letters per word
int uniqueLetterAppearance[26] = {0}; // array to flag if there is a duplicate letter
int excludeLetters[26] = {0}; // array to flag which letters should not be excluded from consideration
int i, j, k; // index variables
int max_letter_count = 0; // count of max letter frequency
int positions_known = 0; // count of known positions within word
int word_count; // number of possible words in main list 

string word; // variable used to read in words from original dictionary
vector<string> wordList; // main list of possible words
vector<string> tmp_wordList; // tmp list used to clear wordList and repopulate with refined words

long int Counter = 0, Counter1= 0, count = 0, count1 = 0;

char tried[26]; // array of guesses (max 26)
int guess_index = 0; // running number of guesses
int miss = 0; // number of missed guesses

string is_word;
string in_word; // decision variable for whether or not (y/n) the letter is in the word
int correct_letter_count = 0; // position(s) of correctly guessed letters in word
vector<int> position; // list of positions of correctly guessed words

int tmp_position; // used to populate position vector

int add_word_flag = 0, add_word_flag_2 = 0; // flags to indicate if a word should be added to a newly populated wordList
int test=0; // will deleted later


cout << "How many letters? ";
cin >> numLetters;
ifstream in_s;
in_s.open("dictionary.txt");


// create vector of words of length numLetters
while(in_s >> word){
	if(word.length() == numLetters) {
		word[0] = tolower(word[0]);
		wordList.push_back(word); // if correct length, add to wordList
		Counter++;
	}
}

in_s.close();

word_count = wordList.size();

while(run){

// count overall frequency of letters and frequency of unique letters per word
for(i=0;i<word_count;i++) {		
	for(j=0;j<numLetters;j++) {

		// this loop works the same way as the original switch statement
		// count letter occurance frequency of each word
		for(k=0;k<26;k++){
			if(wordList[i][j] == alpha[k]){
				if(excludeLetters[k] != 1){
					alphaCount[k]++;
					uniqueLetterAppearance[k] = 1; // count non-duplicate letters of each word
				}
			} 
		}
	}
	// count number of words each letter appears in
	for(k=0;k<26;k++){
		if(uniqueLetterAppearance[k] == 1){
			alphaWordCount[k]++;
		}
		uniqueLetterAppearance[k] = 0; // reset flag variable
	}
}

for(count1=0;count1<26;count1++) {
	if(alphaCount[count1] > max_letter_count) {
		max_letter_count = alphaCount[count1];
	}
}

cout << "word count: " << word_count << " " << numLetters << " letter words." << endl;
cout << "first word: " << wordList[0] << endl;
cout << "last word: " << wordList[word_count - 1] << endl << endl;


// print all occurances of letters
for(i=0;i<26;i++){
	cout << alpha[i] << " found " << alphaCount[i] << " times in " << alphaWordCount[i] << " words " << endl;
	cout << "Relative probability of duplicate letters: " << (static_cast<float>(alphaCount[i])/static_cast<float>(alphaWordCount[i])) - 1 << endl;
	cout << endl;
}

cout << "max letter count: " << max_letter_count << endl;

for(count1=0;count1<26;count1++) {
	if(alphaCount[count1] == max_letter_count) {
		cout << "Guess X should be the letter " << "'" << alpha[count1] << "'" << endl;
		tried[guess_index] = alpha[count1];
		excludeLetters[count1] = 1; // this letter should not be considered in future guesses
	}
}

cout << "is the letter " << "'" << tried[guess_index] << "'" << " in the word? (y/n)" << endl;
cin >> in_word;

// determine if letter to guess is in word
if(in_word == "y"){

	// if yes, obtain number of occurances and positions of letters - store positions in vector
	cout << "How many times does the letter " << "'" << tried[guess_index] << "'" << " occur?" << endl;
	cin >> correct_letter_count;
	for(i=0; i < correct_letter_count; i++){
		cout << "occurance " << i+1 << " is at position: " << endl;
		cin >> tmp_position;
		position.push_back(tmp_position);

	}

	// for clarity, reiterate letter and positions via console (for testing, might be removed later)
	cout << "The letter " << "'" << tried[guess_index] << "'" << " appears at positions: " << endl;
	for(i=0;i<correct_letter_count;i++){
		cout << position[i+positions_known] << endl;
	}

	// check if the letter(s) being guessed are in the correct positions(s)
	for(i=0;i<word_count;i++) {
		test++;
		for(j=0;j<correct_letter_count;j++){
			if(wordList[i][position[j+positions_known]-1] == tried[guess_index]){
				add_word_flag++;
			}
		}

		// make sure the letter ONLY appears in the correct position(s) 
		for(j=0;j<numLetters;j++){
			if(wordList[i][j] == tried[guess_index]){
				add_word_flag_2++;
			}
		}

		// if the letter is in the correct position(s) - and only the correct positions - add it to wordList
		if(add_word_flag == correct_letter_count && add_word_flag_2 == correct_letter_count){
        	tmp_wordList.push_back(wordList[i]);
        	Counter1++;
        }

	add_word_flag = 0;
	add_word_flag_2 = 0;

	}

} else{
	miss++;
	cout << "missed" << endl;
	for(i=0;i<word_count;i++){
		test++;
		for(j=0;j<numLetters;j++){
			if(wordList[i][j] != tried[guess_index]){
				add_word_flag++;
				// if the incorrectly guessed letter is not in the word, add word to wordList
				if(add_word_flag == numLetters){
        			tmp_wordList.push_back(wordList[i]);
        			Counter1++;
        		}
			}
		}
	add_word_flag = 0;
	}
}


// set wordlist = to list of refined words (swap wordList vectors and reset tmp vector)
// reset letter frequency counters and word counter
// increment count of known letter positions and guess index

wordList.clear();
for(i=0;i<Counter1;i++){
	wordList.push_back(tmp_wordList[i]);
}
tmp_wordList.clear();

// update figure
draw(miss);

cout << endl;
cout << "new wordList count: " << wordList.size() << " words." << endl;
cout << test-Counter1 << " words removed after guessing the letter "  << "'" << tried[guess_index] << "'" << endl;

positions_known += correct_letter_count;
guess_index++;

cout << "Guess count: " << guess_index << endl;
cout << "Miss count: " << miss << endl;

Counter1 = 0;
test = 0;
max_letter_count = 0;

for(i=0;i<26;i++){
	alphaCount[i] = 0;
	alphaWordCount[i] = 0;
	uniqueLetterAppearance[i] = 0;
}

word_count = wordList.size();

if(miss == 6 || word_count == 1){
	run = 0;
}

if(6 - miss >= word_count){
	for(i=0;i<word_count;i++){
		cout << "is your word " << wordList[i] << "?" << endl;
		cin >> is_word;
		if(is_word == "y"){
			i = word_count;
			run = 0;
		} else {
			miss++;
			draw(miss);
		}
	}	
}

}

}


void draw(int miss){

switch(miss){

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
	break;					

	}
}

