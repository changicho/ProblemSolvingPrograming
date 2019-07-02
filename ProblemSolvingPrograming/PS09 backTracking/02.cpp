#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>

#define element int

using namespace std;

vector<int> cardSet;
vector<int> answer;

vector<int> singleOut;
vector<int> output;

void full(int, int);
void toChange(int);
bool isPrime(int);
int squreRoot(int);

int main() {
	int cardNum, card, count = 0;
	while (cin >> cardNum) {
		for (int i = 0; i < cardNum; i++) {
			cin >> card;
			cardSet.push_back(card);
		}

		for (int i = 0; i < cardSet.size(); i++) {
			full(i, 0);
		}

		std::sort(output.begin(), output.end());

		// "enable way" << endl;

		for (int j = 0; j < output.size(); j++) {
			// output[j] << endl;
			toChange(output[j]);
		}

		std::sort(answer.begin(), answer.end());
		// "// all answer" << endl;
		// endl;
		//for (int j = 0; j < answer.size(); j++) {
		//    // answer[j] << " ";
		//}
		// endl;

		// "// prime answer" << endl;
		for (int j = 0; j < answer.size(); j++) {
			if (isPrime(answer[j])) {
				cout << answer[j] << " ";
				count++;
			}

		}
		cout << endl;
		//cout << "count is "<<count<<endl;

		if (count == 0) {
			cout << "No Prime!" << endl;
		}

		count = 0;
		output.clear();
		answer.clear();
		cardSet.clear();
		singleOut.clear();
	}

	return 0;
}

void full(int depth, int index) {

	if (cardSet.size() == depth) {
		int temp = 0;
		// if means DFS is end
		for (int i = 0; i < singleOut.size(); i++) {
			temp = temp * 10 + singleOut[i] + 1;
		}
		//cout << temp<<endl;
		output.push_back(temp);
		return;
	}

	for (int i = 0; i < cardSet.size(); i++) {
		if (std::find(singleOut.begin(), singleOut.end(), i) != singleOut.end()) {
			continue;
		}
		singleOut.push_back(i);
		full(depth + 1, i + 1);
		singleOut.pop_back();
	}
}

void toChange(int singleout) {
	int temp = 0;
	vector<int> ans;

	while (singleout != 0) {
		ans.push_back(singleout % 10);
		singleout = singleout / 10;
	}

	std::reverse(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		temp = temp * 10 + cardSet[ans[i] - 1];
	}

	if (temp == 0 || temp == 1) {    // 0 or 1 means not prime
		return;
	}

	if (std::find(answer.begin(), answer.end(), temp) != answer.end()) { // answer has temp?
		return;
	}
	answer.push_back(temp);
}

bool isPrime(element num) {
	//int temp = num/2;
	int temp = squreRoot(num);

	//cout << "isPrime?" << endl;
	for (element i = 2; i < temp; i++) { //detect output is prime?
		if (num%i == 0) {
			return false;
		}
	}
	return true;
}

int squreRoot(int num) {
	return (int)sqrt(num) + 1;
}