//�� ���ڿ��� �ֳʱ׷� ���迡 �ֵ��� ����� ���ؼ� �����ؾ� �ϴ� �ּ� ���� ����
//�Ѱ��� ��츸.

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;



string ALLSMALL(string A) {
	for (int i = 0; i < A.length(); i++) {
		if (A[i] >= 'A' && A[i] <= 'Z') {
			A[i] = A[i] + ('a' - 'A');
		}
	}
	return A;
}

int ABS(int NUM) {
	if (NUM < 0) {
		return -NUM;
	}
	return NUM;
}


void SOLVE() {
	string first, second;
	int firstWord[26] = { 0 , }, secondWord[26] = { 0, };
	//vector<string> firstWord;
	//vector<string> secondWord;

	cin >> first;
	cin >> second;

	//cout << first << " & " << second << " are ";

	//first = ALLSMALL(first);
	//second = ALLSMALL(second);

	//if (first.length() != second.length()) {
	//	return false;
	//}

	for (int i = 0; i < first.length(); i++) {
		firstWord[first[i] - 'a']++;
	}
	for (int i = 0; i < second.length(); i++) {
		secondWord[second[i] - 'a']++;
	}

	int result=0;

	for (int i = 0; i < 26; i++) {
		//printf("%c %d %d\n", i + 'a', firstWord[i], secondWord[i]);
		result = result + ABS(firstWord[i] - secondWord[i]);
	}

	cout << result << endl;

}



int main() {

	SOLVE();

	return 0;
}