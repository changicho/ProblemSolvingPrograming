#pragma warning(disable:4996)

#include<stdio.h>
#include<queue>
#include<iostream>

using namespace std;

#define BUFSIZE 1000

queue<int> QUE_NUM;
queue<char> SIGN;

char ORI_INPUT[BUFSIZE];

void SOLVE() {
	int SUM = 0;
	int TEMP = 0;
	int LENG = 0;

	//fgets(ORI_INPUT, BUFSIZE, stdin);

	for (LENG = 0;; LENG++) {
		if (ORI_INPUT[LENG] == '\0') {
			break;
		}
	}
	for (int index = 0; index < LENG - 1; index++) {

		if (ORI_INPUT[index] > 'J') {
			if (index == LENG - 2) {
				cout << "Error" << endl;
				return;
			}
			else {

				QUE_NUM.push(TEMP);
				TEMP = 0;
				
				//cout << ORI_INPUT[index] << endl;

				switch (ORI_INPUT[index]) {
				case 'P':
					SIGN.push('P');
					break;
				case 'S':
					SIGN.push('S');
					break;
				case 'T':
					SIGN.push('T');
					break;
				case 'V':
					SIGN.push('V');
					break;
				}

			}
		}
		else {
			TEMP = TEMP * 10 + (ORI_INPUT[index] - 65);
			if (TEMP == 0) {
				if (ORI_INPUT[index] = 65) {
					cout << "Error" << endl;
					return;
				}
			}
			if (index == LENG - 2) {
				
				//cout << TEMP << endl;
				
				QUE_NUM.push(TEMP);
			}
		}
	}

	//cout << SIGN.size() << " " << QUE_NUM.size()<<endl;

	if (SIGN.size() != QUE_NUM.size() - 1) {
		cout << "Error" << endl;
		return;
	}

	SUM = QUE_NUM.front();
	QUE_NUM.pop();

	while (!QUE_NUM.empty())
	{
		if (SIGN.front() == 'P') {
			SUM = SUM + QUE_NUM.front();
		}
		else if (SIGN.front() == 'S') {
			SUM = SUM - QUE_NUM.front();
		}
		else if (SIGN.front() == 'T') {
			SUM = SUM * QUE_NUM.front();
		}
		else if (SIGN.front() == 'V') {
			SUM = SUM / QUE_NUM.front();
		}
		QUE_NUM.pop();
		SIGN.pop();
	}
	cout << SUM << endl;

	return;
}

int main() {
	while (fgets(ORI_INPUT, BUFSIZE, stdin) != NULL) {
		SOLVE();
		for (int i = 0; i < BUFSIZE; i++) {
			ORI_INPUT[i] = '\0';
		}
		while (QUE_NUM.empty() != true) {
			QUE_NUM.pop();
		}
		while (SIGN.empty() != true) {
			SIGN.pop();
		}
	}
}