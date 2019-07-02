#include<stdio.h>
#include<iostream>

using namespace std;

#define BUFFSIZE 10000

int N;
int ARR[BUFFSIZE];
int ARRORI[BUFFSIZE];
int ANSWER[BUFFSIZE];

void CLEAR() {		// 한 계산을 끝내고 초기화하는 부분
	for (int i = 0; i < N; i++) {
		ARR[i] = 0;
		ARRORI[i] = 0;
		ANSWER[i] = 0;
	}

	N = 0;
}

void SWAP(int first, int last) {	// 정렬하며 SWAP하는 부분
	int temp = 0;
	temp = ARR[first];
	ARR[first] = ARR[last];
	ARR[last] = temp;
}

bool CHECK() {		//ARR[i] + 1 == ARR[i + 1]인지 검사
	for (int i = 0; i < N - 1; i++) {
		if (ARR[i] + 1 == ARR[i + 1])
			return false;
	}

	return true;
}

void PRINT() {	// 정렬중인 ARR의 상태 출력 함수
	for (int i = 0; i < N; i++) {
		cout << ARR[i] << " ";
	}
	cout << endl;
}

void INSERTSWAP(int first, int last) {
	int temp = ARR[last];

	for (int i = last; i > first; i--) {
		ARR[i] = ARR[i - 1];
	}
	ARR[first] = temp;
}

void SOLVE() {
	int index = 0;
	int SW = 0;
	int MIN = 0;
	int MININDEX = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &ARR[i]);
	}

	for (int i = 0; i < N - 1; i++) {    // sort Arr to get upper
		for (int j = 0; j < N - 1 - i; j++) {
			if (ARR[j] > ARR[j + 1]) {
				SWAP(j, j + 1);
			}
		}
	}

	while (!CHECK()) {
		for (int i = 0; i < N-1; i++) {
			if (ARR[i] + 1 == ARR[i + 1]) {		//first = i+1
				
				for (int j = i+1; j < N; j++) {
					if (ARR[j] > ARR[i + 1] && SW==0) {
						MIN = ARR[j];
						SW = j;
					}
					else if (ARR[j] > ARR[i + 1] && SW != 0) {
						if (ARR[j] < MIN) {
							MIN = ARR[j];
							SW = j;
						}
					}
				}

				if (SW != 0) {
					INSERTSWAP(i + 1, SW);
				}
				else {
					SWAP(i, i + 1);
				}
				SW = 0;
				MIN = 0;
			}
		}


	}
	
	PRINT();

}



int main() {

	while (scanf("%d", &N) == 1) {
		SOLVE();

		CLEAR();
	}
	return 0;
}