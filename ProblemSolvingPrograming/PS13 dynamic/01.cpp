#include<iostream>
#include<math.h>
#include<vector>
#include<string>

using namespace std;

#define DIRECTION_NUM 4

// counter clock wise
int dir_row[DIRECTION_NUM] = { +0, +1, +0, -1 };
int dir_col[DIRECTION_NUM] = { +1, +0, -1, +0 };

int row, col;
int minest;
int start_row, start_col;
int goal_row, goal_col;

vector<vector<int> > map;
vector<vector<int> > map_weight;
vector<vector<int> > visit;

bool can_move(int, int);
void DFS(int, int, int);

int main() {
	string temp;

	cin >> row;

	map.resize(row);
	map_weight.resize(row);
	visit.resize(row);

	cin >> col;
	//this means can take maximum weight
	minest = (row*col - 2) * 25;

	for (int i = 0; i < row; i++) {
		// dynamic assign part
		visit[i].resize(col, 0);
		map_weight[i].resize(col, minest);

		cin >> temp;
		for (int j = 0; j < col; j++) {
			if (temp[j] == '$') {
				start_row = i;
				start_col = j;
				map[i].push_back(0);
			}
			else if (temp[j] == '&') {
				goal_row = i;
				goal_col = j;
				map[i].push_back(0);
			}
			else if (temp[j] == '#') {
				map[i].push_back(-1);
			}
			else {
				map[i].push_back(temp[j] - 'A');
			}
		}
	}


	//// map print part
	//cout << endl;
	//for (int i = 0; i < row; i++) {
	//	for (int j = 0; j < col; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	//// visit print part
	//cout << endl;
	//for (int i = 0; i < row; i++) {
	//	for (int j = 0; j < col; j++) {
	//		cout << visit[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	visit[start_row][start_col] = 1;
	DFS(start_row, start_col, 0);

	cout << minest << endl;

	return 0;
}

bool can_move(int row2, int col2) {
	if (row2 < 0 || row2 > map.size() - 1 || col2 < 0 || col2 > map[0].size() - 1) {
		return false;
	}
	else if (map[row2][col2] == -1) {
		return false;
	}
	else if (visit[row2][col2] == 1) {
		return false;
	}
	return true;
}

void DFS(int i, int j, int weight) {
	// use memoization, so cut imposible case
	if (weight > map_weight[i][j]) {
		return;
	}
	map_weight[i][j] = weight;

	if (i == goal_row && j == goal_col) {
		if (weight < minest) {
			minest = weight;
		}
		visit[i][j] = 0;
		return;
	}

	int next_row;
	int next_col;

	for (int index = 0; index < 4; index++) {
		next_row = i + dir_row[index];
		next_col = j + dir_col[index];
		if (can_move(next_row, next_col)) {
			visit[next_row][next_col] = 1;
			DFS(next_row, next_col, weight + map[next_row][next_col]);
			visit[next_row][next_col] = 0;
		}
	}
}