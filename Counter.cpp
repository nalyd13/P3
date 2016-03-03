#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<istream>

using namespace std;

int main( ) {

char get;
char alpha[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0,n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0,x=0,y=0,z=0;
int alphaCount[26] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};
int A=0,B=0,C=0,D=0,E=0,F=0,G=0,H=0,I=0,J=0,K=0,L=0,M=0,N=0,O=0,P=0,Q=0,R=0,S=0,T=0,U=0,V=0,W=0,X=0,Y=0,Z=0;
int numLetters = 0, max = 0;
string wordList[33000], wordList1[10000];
string word;
long int Counter = 0, Counter1= 0, count = 0, count1 = 0;

cout << "How many letters? ";
cin >> numLetters;

ifstream in_s;

in_s.open("Dictionary.txt");

while(in_s >> word) {
	if(word.length( ) == numLetters) {
		word[0] = tolower(word[0]);
		
		for(count=0;count<numLetters;count++) {
			get = word[count];

switch(get) {
case 'a':
	a++;
	alphaCount[0]++;
	break;
case 'b':
	b++;
	alphaCount[1]++;
	break; 
case 'c':
	c++;
	alphaCount[2]++;
	break; 
case 'd':
	d++;
	alphaCount[3]++;
	break; 
case 'e':
	e++;
	alphaCount[4]++;
	break; 
case 'f':
	f++;
	alphaCount[5]++;
	break; 
case 'g':
	g++;
	alphaCount[6]++;
	break; 
case 'h':
	h++;
	alphaCount[7]++;
	break; 
case 'i':
	i++;
	alphaCount[8]++;
	break; 
case 'j':
	j++;
	alphaCount[9]++;
	break; 
case 'k':
	k++;
	alphaCount[10]++;
	break; 
case 'l':
	l++;
	alphaCount[11]++;
	break; 
case 'm':
	m++;
	alphaCount[12]++;
	break; 
case 'n':
	n++;
	alphaCount[13]++;
	break; 
case 'o':
	o++;
	alphaCount[14]++;
	break; 
case 'p':
	p++;
	alphaCount[15]++;
	break; 
case 'q':
	q++;
	alphaCount[16]++;
	break; 
case 'r':
	r++;
	alphaCount[17]++;
	break; 
case 's':
	s++;
	alphaCount[18]++;
	break; 
case 't':
	t++;
	alphaCount[19]++;
	break; 
case 'u':
	u++;
	alphaCount[20]++;
	break; 
case 'v':
	v++;
	alphaCount[21]++;
	break; 
case 'w':
	w++;
	alphaCount[22]++;
	break; 
case 'x':
	x++;
	alphaCount[23]++;

	break; 	
case 'y':
	y++;
	alphaCount[24]++;
	break; 
case 'z':
	z++;
	alphaCount[25]++;
	}
}
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
cout << a << endl;
cout << b << endl;
cout << c << endl;
cout << d << endl;
cout << e << endl;
cout << f << endl;
cout << g << endl;
cout << h << endl;
cout << i << endl;
cout << j << endl;
cout << k << endl;
cout << l << endl;
cout << m << endl;
cout << n << endl;
cout << o << endl;
cout << p << endl;
cout << q << endl;
cout << r << endl;
cout << s << endl;
cout << t << endl;
cout << u << endl;
cout << v << endl;
cout << w << endl;
cout << x << endl;
cout << y << endl;
cout << z << endl;

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
