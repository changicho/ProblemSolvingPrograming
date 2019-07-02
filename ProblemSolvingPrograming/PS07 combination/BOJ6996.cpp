////두 문자열이 애너그램인지 구하는 프로그램.
////메모리 초기화 없음.
//
//#include<stdio.h>
//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//
//
//
//string ALLSMALL(string A) {
//	for (int i = 0; i < A.length(); i++) {
//		if (A[i] >= 'A' && A[i] <= 'Z') {
//			A[i] = A[i] + ('a' - 'A');
//		}
//	}
//	return A;
//}
//
//
//bool SOLVE() {
//	string first, second;
//	int firstWord[26] = { 0 , }, secondWord[26] = { 0, };
//	//vector<string> firstWord;
//	//vector<string> secondWord;
//
//	cin >> first;
//	cin >> second;
//
//	cout << first << " & " << second << " are ";
//
//	//first = ALLSMALL(first);
//	//second = ALLSMALL(second);
//
//	if (first.length() != second.length()) {
//		return false;
//	}
//
//	for (int i = 0; i < first.length(); i++) {
//		firstWord[first[i] - 'a']++;
//		secondWord[second[i] - 'a']++;
//	}
//
//	int i = 0;
//
//	while (firstWord[i] == secondWord[i]) {
//		i++;
//		if (i > first.length()) {
//			return true;
//		}
//	}
//	return false;
//}
//
//
//
//int main() {
//	int N;
//	cin >> N;
//
//	while (N != 0) {
//		if (SOLVE()) {
//			cout << "anagrams." << endl;
//		}
//		else {
//			cout << "NOT anagrams." << endl;
//		}
//
//		N--;
//	}
//
//	return 0;
//}