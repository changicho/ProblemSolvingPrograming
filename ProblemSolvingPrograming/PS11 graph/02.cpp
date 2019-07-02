// KnightTeemo
#include<iostream>
#include<vector>
#include<queue>

#define MAXSIZE 200
#define MOVEKNIGHT 8
#define MOVE 4

using namespace std;

struct location {
	int y;
	int x;
	int cnt;
	int jump;
};

queue<location> Q;

int kightY[MOVEKNIGHT] = { -1, -2, -2, -1, +1, +2, +2, +1 };
int kightX[MOVEKNIGHT] = { -2, -1, +1, +2, +2, +1, -1, -2 };
int moveY[MOVE] = { +1,-1, +0, +0 };
int moveX[MOVE] = { +0,+0, +1, -1 };

int board[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE][MAXSIZE][32]; // can jump num(0~30) = 31, and plus all last 1

int CNT = 0;
int MAX = 0;

int K; // jump
int W; // garo
int H; // sero

bool isEnd = false;

void BFS();
bool canGo(int, int);

int main() {
	while (cin >> K) {
		cin >> W >> H;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> board[i][j];
			}
		}
		cout << endl;

		Q.push({ 0, 0, 0, 0 }); // input start point, stat
		visited[0][0][0] = 1; // visited first point, check

		while (!Q.empty()) {
			BFS();
		}

		if (!isEnd) { // there is no answer
			cout << "-1" << endl;
		}
		cout << endl;

		for (int i = 0; i < H; i++) { // clear
			for (int j = 0; j < W; j++) {
				for (int z = 0; z < 32; z++) {
					visited[i][j][z] = 0;
				}
			}
		}
		isEnd = false;
	}
	
	return 0;
}

void BFS() {
	if (isEnd) {
		Q.pop(); // without pop, infinite loop
		return;
	}

	int y = Q.front().y;
	int x = Q.front().x;
	int cnt = Q.front().cnt;
	int jump = Q.front().jump;
	Q.pop(); // delete front;

	if (y == H - 1 && x == W - 1) { // if reached goal
		cout << cnt << endl;
		isEnd = true;
		return;
	}

	if (jump < K) {
		for (int i = 0; i < MOVEKNIGHT; i++) { // detect jump
			int nextY = y + kightY[i];
			int nextX = x + kightX[i];

			if (canGo(nextY, nextX)) { // if can jump
				if (!visited[nextY][nextX][jump + 1]) {
					visited[nextY][nextX][jump + 1] = true; // make next point visit
					Q.push({ nextY, nextX, cnt + 1, jump + 1 }); // push it to queue
				}
			}
		}
	}

	for (int i = 0; i < MOVE; i++) { // detect move
		int nextY = y + moveY[i];
		int nextX = x + moveX[i];

		if (canGo(nextY, nextX)) { // if can move
			if (!visited[nextY][nextX][jump]) {
				visited[nextY][nextX][jump] = true; // make next point visit
				Q.push({ nextY, nextX, cnt + 1,  jump }); // push it to queue
			}
		}
	}

	return;
}

bool canGo(int axisY, int axisX) {
	if (axisX < 0 || axisX >= W) {
		return false;
	}
	if (axisY < 0 || axisY >= H) {
		return false;
	}
	if (board[axisY][axisX] == 0) {
		return true;
	}
	return false;
}