#include<iostream>
#include<string>
using namespace std;
#define MAX_SIZE 1001

int alpha[26];
char output[MAX_SIZE];
int len;
string s;

void DFS(int, int);

int main(void) {

	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < 26; j++) alpha[j] = 0;

		cin >> s;

		len = s.length();
		for (int j = 0; j <len; j++) {
			alpha[s[j] - 'a']++;
		}

		DFS(0, 0);
	}

	return 0;
}

void DFS(int idx, int d) {

	if (d == len) {
		cout << output << '\n';
		return;
	}

	for (int i = 0; i < 26; i++) {	// looping alphabet making tree

		if (0 < alpha[i]) {

			alpha[i]--;
			output[d] = 'a' + i;
			DFS(i, d + 1);
			alpha[i]++;
		}
	}
}