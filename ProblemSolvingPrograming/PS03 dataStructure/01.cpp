#include<stdio.h>
#include<iostream>

#include<stack>
#include<queue>

using namespace std;

#define BUFSIZE 101
stack<char> CARD;
stack<char> OUTPUT;

char INPUT[BUFSIZE];

void CLEAR_INPUT();
void SOLVE();
int COUNT_LENG();
int CARD_NUM = 0;


int main() {
	while (fgets(INPUT, BUFSIZE, stdin) != NULL) {
		//printf("%s\n", INPUT);
		SOLVE();
		CLEAR_INPUT();
		CARD_NUM = 0;
	}
}

void SOLVE() {
	//int LENG = COUNT_LENG();
	for (int i = 0; i < BUFSIZE; i++) {
		if (INPUT[i] == '\n') {
			break;
		}
		
		if (CARD_NUM > 10) {
			if (INPUT[i] == '*') {
				if (!CARD.empty()) {
					CARD.pop();
					CARD_NUM--;
				}
			}
			else {
				continue;
			}
		}
		else {
			if (INPUT[i] == '*') {
				if (!CARD.empty()) {
					CARD.pop();
					CARD_NUM--;
				}
			}
			else {
				if (CARD_NUM > 9) {

				}
				else {
					CARD.push(INPUT[i]);
					CARD_NUM++;
				}
				
			}
		}
		
		
		
	}

	while (!CARD.empty()) {
		OUTPUT.push(CARD.top());
		//cout << CARD.top();
		CARD.pop();
	}

	while (!OUTPUT.empty()) {
		cout << OUTPUT.top();
		OUTPUT.pop();
	}
	cout << endl;
}
int COUNT_LENG() {
	int LENG;
	for (LENG = 0;; LENG++) {
		if (INPUT[LENG] == '\0') {
			break;
		}
	}
	return LENG;
}

void CLEAR_INPUT() {
	for (int i = 0; i < BUFSIZE; i++) {
		INPUT[i] = 0;
	}
}