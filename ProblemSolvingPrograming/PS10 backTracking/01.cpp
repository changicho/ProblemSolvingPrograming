#include<iostream>
#include<vector>

#define MAXSIZE 10
#define MOVE 8

using namespace std;

//CCR
int kightX[MOVE] = { -2, -1, +1, +2, +2, +1, -1, -2 };
int kightY[MOVE] = { +1, +2, +2, +1, -1, -2, -2, -1 };
//int kightX[MOVE] = { +1, +2, +2, +1, -1, -2, -2, -1 };
//int kightY[MOVE] = { -2, -1, +1, +2, +2, +1, -1, -2 };

int board[MAXSIZE][MAXSIZE];
int CNT = 0;
int SW = 0;
int callDFS = 0;

int SIZEX;
int SIZEY;

vector<int> moveX;
vector<int> moveY;

void DFS(int, int);
void clearBoard();
bool canMove(int, int, int);

int main() {
	int N;
	int firstX;
	int firstY;

	while (cin >> N) {
		SIZEX = N;
		SIZEY = N;
		//cin >> firstX;
		//cin >> firstY;
		cin >> firstX;
		cin >> firstY;

		DFS(firstY, firstX);

		if (CNT != SIZEX * SIZEY) {
			cout << "-1 -1" << endl;
		}
		//cout << "callDFS is " << callDFS << endl;
		//callDFS = 0;
		moveX.clear();
		moveY.clear();
		CNT = 0;
		SW = 0;
		clearBoard();
	}

	return 0;
}

void DFS(int y, int x) {
	//callDFS++;
	moveX.push_back(x);
	moveY.push_back(y);

	board[y][x] = 2;
	CNT++;

	if (CNT == SIZEX * SIZEY) {
		//cout << "all visit" << endl;
		//for (int i = 0; i < SIZEY; i++) {
		//	for (int j = 0; j < SIZEX; j++) {
		//		cout << board[i][j];
		//	}
		//	cout << endl;
		//}
		//cout << endl;
		int cnt = 0;
		cout << endl;
		for (int i = 0; i < moveX.size(); i++) {
			cout << moveX[i] << " " << moveY[i] << endl;
			cnt++;
		}
		//cout << "count is cnt : " << cnt << endl;
		SW = 1;
		return;
	}

	for (int i = 0; i < MOVE; i++) {
		if (canMove(y, x, i)) {
			//cout<<
			DFS(y + kightY[i], x + kightX[i]);
			if (SW == 1) {
				return;
			}
		}
		else {
			//cout << "can't" << endl;
		}
	}

	moveX.pop_back();
	moveY.pop_back();
	board[y][x] = 0;
	CNT--;

	return;
}

void clearBoard() {
	for (int i = 0; i < SIZEY; i++) {
		for (int j = 0; j < SIZEX; j++) {
			board[i][j] = 0;
		}
	}
}

bool canMove(int axisY, int axisX, int index) {
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