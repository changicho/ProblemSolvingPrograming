#pragma warning(disable:4996)

#include<stdio.h>
#define BUFF 1001

long int ARR[BUFF];
int ARR_CNT[BUFF];
int ARRMANY = 0;
void SWAP(int i, int j) {
	int temp=ARR[j];
	
	ARR[j] = ARR[i];
	ARR[i] = temp;

	temp = ARR_CNT[j];

	ARR_CNT[j] = ARR_CNT[i];
	ARR_CNT[i] = temp;
}

void SOLVE(int NI, int MI) {
	int N = NI;
	int M = MI;
	int TEMP;
	for (int i = 0; i < N; i++) {
		scanf("%d", &TEMP);
		if (TEMP > M) {
			continue;
		}

		//printf("temp : %d\n", TEMP);
		for (int j = 0; j < N; j++) {
			if (ARR[j] == TEMP) {
				ARR_CNT[j]++;
				//printf("\n up\n");

				break;
			}
			else if (ARR[j] == 0) {
				ARR[j] = TEMP;
				ARR_CNT[j]++;
				//printf("\n new up\n");
				ARRMANY++;
				break;
			}
		}
	}

	int max = 0;
	int max_index = 0;
	for (int j = 0; j < ARRMANY; j++) {
		max_index = 0;
		max = 0;
		for (int i = 0; i < ARRMANY; i++) {
			if (ARR_CNT[i] > max) {
				max = ARR_CNT[i];
				max_index = i;
			}
		}
		for (int z = 0; z < ARR_CNT[max_index]; z++) {
			printf("%ld ", ARR[max_index]);
		}
		ARR_CNT[max_index] = 0;

	}
}

int main() {
	int N, M;
	while (scanf("%d %d", &N, &M) == 2) {
		SOLVE(N,M);
		printf("\n");
		for (int i = 0; i < N; i++) {
			ARR[i] = 0;
			ARR_CNT[i] = 0;
		}
	}
	
	return 0;
}