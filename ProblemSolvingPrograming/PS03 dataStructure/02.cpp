#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

#define BUFF 1001

int BOMBTIME[BUFF];
int DEAD[BUFF];

void SOLVE(int Number) {
	int TEMP;
	int TIME = 0;
	int index = 1;
	int index_temp;
	int count = 0;
	do {
		scanf("%d", &TEMP);
		//cout << TEMP << " ";
		//if (TEMP <= Number) {
		BOMBTIME[count] = TEMP;
		count++;
		//}
	} while (getc(stdin) != '\n');

	int count_temp = 0;
	//for (int time = 1; time < Number + 1; time++) {
	for (int time = 1; count_temp < count; time++) {
		//cout << time << "sec" << endl;

		index++;    //next man
		while (1) {
			//cout << index << " ";
			if (index > Number) {
				index = 1;
			}
			if (DEAD[index] == 0)
				break;
			index++;
		}

		if (BOMBTIME[count_temp] == time) {
			count_temp++;
			index_temp = index;    //index_temp is deadman
			if (time % 2 == 0) {    //even
									//cout << "even" << endl;
				index_temp++;
				while (1) {
					if (index_temp > Number) {
						index_temp = 1;
					}
					if (DEAD[index_temp] == 0)
						break;
					index_temp++;
				}
				//cout << index_temp << "dead" << endl;

				if (index_temp != index) {
					DEAD[index_temp] = 1;
				}
			}
			else {    //odd
					  //cout << "odd" << endl;
				index_temp--;
				while (1) {
					if (index_temp < 1) {
						index_temp = Number;
					}
					if (DEAD[index_temp] == 0)
						break;
					index_temp--;
				}
				//cout << index_temp <<" dead"<< endl;

				if (index_temp != index) {
					DEAD[index_temp] = 1;
				}
			}
		}

	}

	for (int i = 1; i < Number + 1; i++) {
		if (DEAD[i] != 1) {
			printf("%d ", i);
		}
	}
	if (Number == 0) {
		printf("0");
	}
}


void CLEAR(int N) {
	for (int i = 1; i < N + 1; i++) {
		BOMBTIME[i] = 0;
		DEAD[i] = 0;
	}
}

int main() {
	int N;
	while (scanf("%d", &N) == 1) {
		SOLVE(N);
		printf("\n");
		CLEAR(N);
	}

	return 0;
}