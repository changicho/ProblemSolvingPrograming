#include<iostream>
#include<math.h>
#include<vector>
#include<string>

using namespace std;

#define DIRECTION_NUM 8
#define maxInt 10000

int startRowPoint = 0, startColPoint = 0;
int dir_row[DIRECTION_NUM] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dir_col[DIRECTION_NUM] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int row, col, jump, TIME, bestHigh;

vector<vector<int> > map;

bool can_move(int, int, int, int);
int take(int, int, int, int);
void go_floyd();
int back_dijkstra(int, int);
int MIN(int, int);
int ABS(int);

int main() {
	string temp;

	while (cin >> row)
	{
		map.resize(row);

		cin >> col >> jump >> TIME;

		for (int i = 0; i < row; i++) {
			cin >> temp;
			for (int j = 0; j < col; j++) {
				map[i].push_back(temp[j] - 'A');
			}
		}

		//// map print part
		//for (int i = 0; i < row; i++) {
		//	for (int j = 0; j < col; j++) {
		//		cout << map[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		bestHigh = map[startRowPoint][startColPoint];
		go_floyd();

		cout << endl << bestHigh << endl;

		startRowPoint = 0, startColPoint = 0;
		row = 0, col = 0, jump = 0, TIME = 0, bestHigh = 0;
		map.clear();
	}

	return 0;
}

bool can_move(int row1, int col1, int row2, int col2) {
	if (row2 < 0 || row2 > map.size() - 1 || col2 < 0 || col2 > map[0].size() - 1) {
		return false;
	}
	else if (ABS(map[row1][col1] - map[row2][col2]) > jump) {
		return false;
	}
	return true;
}

int take(int row1, int col1, int row2, int col2) {
	if (row1 == row2 && col1 == col2) {
		return 0;
	}
	
	int startHigh = map[row1][col1], endHigh = map[row2][col2];
	
	if (startHigh >= endHigh) {
		return 1;
	}
	else {
		return (endHigh - startHigh) * (endHigh - startHigh);
	}
}

void go_floyd() {
	vector<vector<vector<vector<int> > > > distance;
	distance.resize(row);

	// init
	for (int i = 0; i < row; i++) {
		distance[i].resize(col);
		for (int j = 0; j < col; j++) {
			distance[i][j].resize(row);
			for (int k = 0; k < row; k++) {
				distance[i][j][k].push_back(maxInt);
				for (int z = 1; z < col; z++) {
					distance[i][j][k].push_back(maxInt);
				}
			}
		}
	}

	for (int i_row = 0; i_row < distance.size(); i_row++) {
		for (int i_col = 0; i_col < distance[i_row].size(); i_col++) {
			for (int j_row = 0; j_row < distance[i_row][i_col].size(); j_row++) {
				for (int j_col = 0; j_col < distance[i_row][i_col][j_row].size(); j_col++) {
					if ((i_row - j_row) * (i_row - j_row) + (i_col - j_col) * (i_col - j_col) <= 2) {
						distance[i_row][i_col][j_row][j_col] = take(i_row, i_col, j_row, j_col);
					}
				}
			}
		}
	}

	// floyd
	for (int k_row = 0; k_row < distance.size(); k_row++) {
		for (int k_col = 0; k_col < distance[k_row].size(); k_col++) {
			for (int i_row = 0; i_row < distance[k_row][k_col].size(); i_row++) {
				for (int i_col = 0; i_col < distance[k_row][k_col][i_row].size(); i_col++) {
					for (int j_row = 0; j_row < distance[k_row][k_col].size(); j_row++) {
						for (int j_col = 0; j_col < distance[k_row][k_col][j_row].size(); j_col++) {
							distance[i_row][i_col][j_row][j_col] = MIN(distance[i_row][i_col][j_row][j_col], distance[i_row][i_col][k_row][k_col] + distance[k_row][k_col][j_row][j_col]);
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int goTIME = distance[startRowPoint][startColPoint][i][j];
			if (map[i][j] > bestHigh && goTIME <= TIME) {
				int backTIME = back_dijkstra(i, j);
				//cout << backTIME << endl;
				//cout << goTIME << endl;
				if (goTIME + backTIME <= TIME) {
					
					bestHigh = map[i][j];
				}
			}
		}
	}
}

int back_dijkstra(int row, int col) {
	vector<vector<bool> > check;
	check.resize(map.size());
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++) {
			check[i].push_back(false);
		}
	}

	vector<vector<int> > distance;
	distance.resize(map.size());
	//
	for (int i = 0; i < map.size(); i++) {
		//distance[i].push_back(maxInt);
		for (int j = 0; j < map[0].size(); j++) {
			//distance[i].push_back(0);
			distance[i].push_back(maxInt);
		}
	}

	int nowRow = row, nowCol = col, nextRow, nextCol, takeTIME, shortDistance;
	
	distance[nowRow][nowCol] = 0;
	while (!check[nowRow][nowCol]) {
		check[nowRow][nowCol] = true;
		for (int i = 0; i < DIRECTION_NUM; i++)
		{
			nextRow = nowRow + dir_row[i];
			nextCol = nowCol + dir_col[i];
			if (can_move(nowRow, nowCol, nextRow, nextCol)) {
				takeTIME = take(nowRow, nowCol, nextRow, nextCol);
				if (distance[nextRow][nextCol] > distance[nowRow][nowCol] + takeTIME) {
					distance[nextRow][nextCol] = distance[nowRow][nowCol] + takeTIME;
				}
			}
		}

		shortDistance = maxInt;
		for (int i = 0; i < check.size(); i++) {
			for (int j = 0; j < check[i].size(); j++) {
				if (!check[i][j] && shortDistance > distance[i][j]) {
					//cout << "match!" << endl;
					shortDistance = distance[i][j];

					nowRow = i;
					nowCol = j;
				}
			}
		}
	}

	return distance[startRowPoint][startColPoint];
}

int MIN(int first, int second) {
	if (first > second) {
		return second;
	}
	return first;
}
//abs(map[row1][col1] - map[row2][col2])
int ABS(int a) {
	if (a > 0) {
		return a;
	}
	else {
		return -a;
	}
}