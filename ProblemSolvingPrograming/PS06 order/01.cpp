#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

#define BUFFSIZE 1000
#define PEOPLE 1000

int N = 0;
int PEOPLENUM = 0;
char NAME[PEOPLE][BUFFSIZE];
int KDA[PEOPLE][3];		//0 : K	// 1 : D // 3 : A
int ZEROCOUNT = 0;
double CALCUL[PEOPLE];


//vector <double> NOTZERO;

void CLEAR() {
	N = 0;
	PEOPLENUM = 0;
	ZEROCOUNT = 0;
}

void SWAPNAME(int first, int last) {
	char TNAME[BUFFSIZE];

	strcpy(TNAME, NAME[first]);
	strcpy(NAME[first], NAME[last]);
	strcpy(NAME[last], TNAME);

}

void SWAP(int first, int last) {
	int temp;
	temp = KDA[first][0];
	KDA[first][0] = KDA[last][0];
	KDA[last][0] = temp;

	temp = KDA[first][1];
	KDA[first][1] = KDA[last][1];
	KDA[last][1] = temp;

	temp = KDA[first][2];
	KDA[first][2] = KDA[last][2];
	KDA[last][2] = temp;

	CALCUL[first] = (double) (KDA[first][0] + KDA[first][2]) / (double) KDA[first][1];
	CALCUL[last] = (double) (KDA[last][0] + KDA[last][2]) / (double) KDA[last][1];

	SWAPNAME(first, last);
}

void SOLVE() {
	vector <double> ZERO;
	int index = 0;
	char tempN[BUFFSIZE] = "aa";
	int tempK = 0, tempD = 0, tempA = 0;
	int i = 0;


	for (i = 0; i < N; i++) {
		scanf("%s %d/%d/%d", NAME[index], &KDA[index][0], &KDA[index][1], &KDA[index][2]);

		if (KDA[index][1] != 0) {
			CALCUL[index] = (double)(KDA[index][0] + KDA[index][2]) / (double)KDA[index][1];
			//cout << CALCUL[index] << endl;
		}
		else {
			CALCUL[index] = 0;
			ZERO.push_back(index);
			ZEROCOUNT++;
		}

		if (KDA[index][1] > (KDA[index][0] + KDA[index][2])) {

		}
		else {
			index++;
		}
		//cout << index << endl;
	}
	PEOPLENUM = index;
	//for (i = 0; i < PEOPLENUM; i++) {
	//	printf("%d : %s %d %d %d\n", i, NAME[i], KDA[i][0], KDA[i][1], KDA[i][2]);
	//}
	//cout << ZEROCOUNT << endl;
	//for (int i = 0; i < ZEROCOUNT; i++) {
	//	cout << ZERO[i] << endl;
	//}


	//cout << "THIS IS ZERO CASE" << endl;
	int ZTEMP = 0, index1 = 0, index2 = 0;
	if (ZEROCOUNT != 0) {
		for (int i = 0; i < ZEROCOUNT - 1; i++) {
			for (int j = i + 1; j < ZEROCOUNT; j++) {
				index1 = ZERO[i]; index2 = ZERO[j];
				if (KDA[index1][0]+ KDA[index1][2] < KDA[index2][0]+ KDA[index2][2]) {
					//cout << "SWAP I, J"<< endl;
					ZTEMP = ZERO[i];
					ZERO[i] = ZERO[j];
					ZERO[j] = ZTEMP;
				}
				else if (KDA[index1][0] + KDA[index1][2] == KDA[index2][0] + KDA[index2][2]) {
					if (strcmp(NAME[index1], NAME[index2]) > 0) {
						ZTEMP = ZERO[i];
						ZERO[i] = ZERO[j];
						ZERO[j] = ZTEMP;
					}
				}
			}
		}
	}
	

	//cout << "D is not 0" << endl;
	//simply D is not 0
	for (int i = 0; i < PEOPLENUM - 1; i++) {
		for (int j = i + 1; j < PEOPLENUM; j++) {
			//cout << NAME[i] << NAME[j] << endl;
			if (CALCUL[i] != 0 && CALCUL[j] != 0) {
				if (CALCUL[i] < CALCUL[j]) {
					//cout << CALCUL[i] << " " << CALCUL[j] << endl;
					SWAP(i, j);
				}
				else if (CALCUL[i] == CALCUL[j]) {	//if same CALCUL, SWAP
					//cout << NAME[i] << " CAL is same " << NAME[j] << endl;
					if (KDA[i][1] > KDA[j][1]) {
						SWAP(i, j);
					}
					//cout << "hello" << endl;
					else if(KDA[i][1]==KDA[j][1]) {
						if (strcmp(NAME[i], NAME[j]) > 0) {
							SWAP(i, j);
						}
					}
				}

			}
			
		}
	}

	cout << endl;
	//cout << "zero capacity : " << ZERO.capacity() << endl;
	for (int i = 0; i < ZEROCOUNT; i++) {
		//cout << "zero hello" << endl;
		index1 = ZERO[i];
		cout << NAME[index1] << " " << KDA[index1][0] << "/" << KDA[index1][1] << "/" << KDA[index1][2] << endl;
	}

	for (int i = 0; i < PEOPLENUM; i++) {
		if (CALCUL[i] == 0) {
			continue;
		}
		cout << NAME[i] << " " << KDA[i][0] << "/" << KDA[i][1] << "/" << KDA[i][2] << endl;
	}
	cout << endl;
}

int main() {

	while (scanf("%d", &N) == 1) {
		SOLVE();

		CLEAR();
	}

	return 0;
}