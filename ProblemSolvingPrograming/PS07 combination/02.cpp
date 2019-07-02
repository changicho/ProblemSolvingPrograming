#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAXSIZE 100000

int alpha[26];	//
				//
int alpha2[26];
char ori[256];		//this is map
int index;
int sw = 0;
//char beforeOutput[MAXSIZE];
//
char output[MAXSIZE];


string chartemp;
vector <string> outputBox;
int outputBoxCount = 0;

int boxIndex = 0;
int length;
char INPUT[MAXSIZE];

string anagram;
string input;

void DFS(int, int);
void SOLVE();
void CLEAR();
int STRLEN(char[]);
void TREAT();

int main(void) {

	while (cin >> input) {

		TREAT();

		SOLVE();
		//cout<<endl<<"count is "<<outputBoxCount;
		CLEAR();
		cout << endl;

	}

	return 0;
}

void DFS(int idx, int d) {
	int SW = 0;
	if (outputBoxCount>99) {
		return;
	}
	if (d == length) {
		string s;
		for (int i = 0; i < length; i++) {
			s += ori[output[i]];
			//printf("%c", ori[output[i]]);
		}
		chartemp = s;
		for (int i = 0; i<outputBoxCount; i++) {
			if (chartemp == outputBox[i]) {
				SW = 1;
				break;
			}
		}

		if (SW == 0) {
			
			outputBox.push_back(s);
			cout << s << " ";
			
			outputBoxCount++;

			//printf(" ");
			SW = 0;
		}
		s.clear();
		return;
	}
	for (int i = 0; i < 26; i++) {	// using DFS make output

		if (0 < alpha[i]) {
			alpha[i]--;
			output[d] = 'a' + i;
			DFS(i, d + 1);
			alpha[i]++;
		}
	}
}

void SOLVE() {
	length = anagram.length();

	for (int j = 0; j <length; j++) {
		alpha[anagram[j] - 'a']++;
	}

	DFS(0, 0);

}

void CLEAR() {
	for (int j = 0; j < 26; j++) {
		alpha[j] = 0;
	}
	for (int j = 0; j < 26; j++) {
		alpha2[j] = 0;
	}
	anagram.clear();
	outputBoxCount = 0;
	outputBox.clear();
}

int STRLEN(char IN[]) {
	int i = 0;
	for (i = 0; IN[i] != NULL; i++);
	return i;
}

void TREAT() {

	for (int i = 0; i < input.length(); i++) {
		//input[i] use
		//if (alpha2[input[i] - 'a'] != 0) {	//

		//	for (int z = 0; z<26; z++) {
		//		if (input[i] == ori[z + 'a']) {
		//			anagram += 'a' + z;	//
		//			break;
		//		}
		//	}
		//	//printf("%c\n",input[i]);
		//	alpha2[input[i] - 'a']++;

		//	sw = 1;
		//}

		//if (sw == 0) {
			ori[index + 'a'] = input[i];
			alpha2[input[i] - 'a']++;

			anagram += index + 'a';//

			index++;
		//}
		//sw = 0;
	}

	//cout << anagram << endl;
	int tmpindex = 0;

	for (int i = 0; i < 26; i++) {	//clear alpha 2
		alpha2[i] = 0;
		ori[i] = 0;
	}
	index = 0;
	sw = 0;
}