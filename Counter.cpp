#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <istream>

using namespace std;

int main() {

char get;
char alpha[27] = {'a','b','c','d','e','f','g','h','i','j','j','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0,n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0,x=0,y=0,z=0;
int alphaCount[26] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};

int alphaWordCount[26] = {0};
int uniqueLetterAppearance[26] = {0};
int ndx;

int A=0,B=0,C=0,D=0,E=0,F=0,G=0,H=0,I=0,J=0,K=0,L=0,M=0,N=0,O=0,P=0,Q=0,R=0,S=0,T=0,U=0,V=0,W=0,X=0,Y=0,Z=0;
int numLetters = 0, max = 0;
string wordList[33000], wordList1[10000];
string word;
long int Counter = 0, Counter1= 0, count = 0, count1 = 0;

cout << "How many letters? ";
cin >> numLetters;

ifstream in_s;

in_s.open("dictionary.txt");

while(in_s >> word) {
	if(word.length() == numLetters) {
		word[0] = tolower(word[0]);
		
		for(count=0;count<numLetters;count++) {
			get = word[count];

			// this loop does the same thing as the switch statement
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
		wordList[Counter] = word;
		Counter++;
	
	}
}

for(count1=0;count1<26;count1++) {
	if(alphaCount[count1] > max) {
		max = alphaCount[count1];
	}
}

cout << Counter << endl;

cout << wordList[0] << endl;
cout << wordList[Counter - 1] << endl;


// print all occurances of letters
for(ndx=0;ndx<26;ndx++){
	cout << alpha[ndx] << " found " << alphaCount[ndx] << " times in " << alphaWordCount[ndx] << " words " << endl;
}

cout << max << endl;

for(count1=0;count1<26;count1++) {
	if(alphaCount[count1] == max) {
		cout << alpha[count1] << endl;
		cout << count1 << endl;
	}
}

for(count1=0;count1<Counter;count1++) {
	wordList[count1] = "?";
}

cout << wordList[100] << endl;

int user = 0;
cin >> user;

in_s.clear();
in_s.seekg(0, ios::beg);

while(in_s >> word) {
        if(word.length( ) == numLetters && word[user-1] == 'a' && word[user] == 'r' && word[user+1] == 'e') {
                wordList[count1] = word;
		Counter1++;
	}
}

cout << Counter1 << endl;
in_s.close( );

}
