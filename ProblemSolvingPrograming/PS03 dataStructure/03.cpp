//Ƽ���� ��������
#include<stdio.h>
#include<iostream>

#include<stack>

#define BUFF 1001
using namespace std;

stack<int> MUSH;

long int ARR[BUFF];
int ARR_CNT[BUFF];
int ARRMANY = 0;

void SOLVE(int);
void REVERSE();
void BIG();
void SMALL();

int main() {
	int N;
	while (scanf("%d", &N)==1) {
		SOLVE(N);
		printf("\n");

		for (int i = 0; i < N; i++) {	//�ʱ�ȭ �κ�
			ARR[i] = 0;
			ARR_CNT[i] = 0;
		}
	}

	return 0;
}


void SOLVE(int N) {
	int TEMP;

	for (int i = 0; i < N; i++) {
		scanf("%d", &TEMP);
		MUSH.push(TEMP);
	}

}

void REVERSE() {

}
void BIG();
void SMALL();