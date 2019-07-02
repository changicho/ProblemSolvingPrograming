#include<iostream>
#include<vector>
//#include<algorithm>

#define MAXSIZE 10
#define MOVE 8

using namespace std;

vector<int> output;

int kightX[MOVE] = { -1, -2, -2, -1, +1, +2, +2, +1 };
int kightY[MOVE] = { -2, -1, +1, +2, +2, +1, -1, -2 };

int board[MAXSIZE][MAXSIZE];
int CNT = 0;
int MAX = 0;

//int SIZEX = MAXSIZE;
//int SIZEY = MAXSIZE;
int SIZEX;
int SIZEY;


void DFS(int, int, int);
void clearBoard();
bool canBite(int, int, int);
void startDFS(int);

int main() {
	int N;

	while (cin >> N) {
		SIZEX = N;
		SIZEY = N;
		if (N > 0 && N <= SIZEX * SIZEY) {
			startDFS(N);
		}

		cout << "MAX is " << MAX << endl;
		CNT = 0;
		MAX = 0;
		clearBoard();
	}

	return 0;
}

void startDFS(int N) {
	for (int i = 0; i < SIZEY; i++) {
		for (int j = 0; j < SIZEX; j++) {
			DFS(i, j, N);
			//cout<<"clear"<<endl;
			clearBoard();
		}
	}

}

void DFS(int y, int x, int N) {
	//cout<<"y : "<<y<<" x : "<<x<<endl;
	int i, possible = 0;

	if (N == 0) {
		MAX++;
		//cout << "#" << MAX << endl;
		//for (int i = 0; i < SIZEY; i++) {
		//	for (int j = 0; j < SIZEX; j++) {
		//		cout << board[i][j];
		//	}
		//	cout << endl;
		//}
		//cout << endl;
		return;
	}

	board[y][x] = 2;
	for (i = 0; i < MOVE; i++) {
		if (canBite(y, x, i)) {
			DFS(y + kightY[i], x + kightX[i], N - 1);
		}
	}
	board[y][x] = 0;

	//if (i == MOVE) {
	//	int tempX = x;
	//	board[y][x] = 2;
	//	if (N - 1 == 0) {
	//		DFS(y, x, 0);
	//	}
	//	else {
	//		for (int i = y; i < SIZEY; i++) {
	//			for (int j = tempX + 1; j < SIZEX; j++) {
	//				DFS(i, j, N - 1);
	//			}
	//			tempX = -1;
	//		}
	//	}
	//	board[y][x] = 0;
	//}

	return;
}

void clearBoard() {
	for (int i = 0; i < SIZEY; i++) {
		for (int j = 0; j < SIZEX; j++) {
			board[i][j] = 0;
		}
	}
}

bool canBite(int axisY, int axisX, int index) {
	if (axisX + kightX[index] < 0 || axisX + kightX[index] >= SIZEX) {
		return false;
	}
	if (axisY + kightY[index] < 0 || axisY + kightY[index] >= SIZEY) {
		return false;
	}

	if (board[axisY + kightY[index]][axisX + kightX[index]] == 0) {
		return true;
	}

	return false;
}