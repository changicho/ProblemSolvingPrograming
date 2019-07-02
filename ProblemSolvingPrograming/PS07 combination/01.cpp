#include <stdio.h>
#include <iostream>

#define ANTMAX 1000
#define ANTLENGTH 5001

using namespace std;

int N;
int antSeries[ANTMAX][ANTLENGTH];
int realAntSeries[ANTMAX][ANTLENGTH];

void calculAnt(int );
void printAnt(int);
void printAntAll(int);

void storeAnt(int a) {
	for (int i = 0; antSeries[a][i] != 0; i++) {
		realAntSeries[a][i] = antSeries[a][i];
	}
}

int main() {

	while (scanf("%d", &N) == 1) {
		calculAnt(N);
		for (int j = 0; antSeries[N-1][j] != 0; j++) {
			printf("%d", antSeries[N-1][j]);
		}
		printf("\n");
	}

	return 0;
}

void printAntAll(int i) {
	for (int k = 0; k < i; k++) {
		for (int j = 0; realAntSeries[k][j] != 0; j++) {
			printf("%d", realAntSeries[i][j]);
		}
		cout << endl;
	}
}

void printAnt(int i) {

		for (int j = 0; antSeries[i][j] != 0; j++) {
			printf("%d", antSeries[i][j]);
		}
		printf("\n");

}

void calculAnt(int UNTIL) {
	

	int arr[ANTLENGTH] = { 1, };
	int arrBefore[ANTLENGTH] = { 0, };
	int count = 1;
	int index = 0;

	for (; index < UNTIL; index++) {
		if (realAntSeries[index][0] != 0) {	// use memoization
			//cout << "skip" << endl;
			for (int clear = 0; realAntSeries[index][clear]!=0; clear++) {
				arr[clear] = realAntSeries[index][clear];
			}
			continue;
		}

		int i = 0;
		int th = 0;

		while (1) {
			realAntSeries[index][th] = arr[i];	//
			antSeries[index][th] = arr[i];
			
			arrBefore[th] = arr[i];
			th++;

			if (index == 0) {
				break;
			}

			while (1) {
				if (arr[i] != arr[i + 1]) {
					
					realAntSeries[index][th] = count;	//
					antSeries[index][th] = count;
					arrBefore[th] = count;
					th++;
					count = 1;
					i++;
					break;
				}
				count++;
				i++;
			}
			if (arr[i] == 0) {
				
				break;
			}
		}
		//cout << "this is ant" << endl;
		//
		/*if (realAntSeries[index][0] == 0) {
			cout << "fill this" << endl;
			storeAnt(index);
		}*/
		//
		//printAnt(index);
		for (int clear = 0; clear < th; clear++) {
			arr[clear] = arrBefore[clear];
		}
	}
}
