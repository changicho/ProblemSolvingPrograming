
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int I, T;
int map[301][301];
int visited[301][301];
int dr[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dc[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

struct location {
	// row
	int cr;
	// column
	int cc;
	// count
	int cnt;
};

queue<location> q;

int main() {
	int desR, desC, r, c;
	// map과 visted 배열 초기화
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	// 큐가 비워져 있는지 확인
	while (!q.empty()) {
		q.pop();
	}
	//cin >> I;
	I = 4;
	r = 0;
	c = 0;
	desR = 3;
	desC = 3;

	//cin >> r >> c >> desR >> desC;
	location loc;
	loc.cr = r;
	loc.cc = c;
	loc.cnt = 0;
	// 방문체크
	visited[r][c] = 1;
	q.push(loc);
	while (!q.empty()) {
		int r = q.front().cr;
		int c = q.front().cc;
		int cnt = q.front().cnt;
		q.pop();
		// 도착 지점 확인
		if (r == desR && c == desC) {
			cout << cnt << endl;
			break;
		}
		// 8 방향으로 좌표 이동
		for (int i = 0; i < 8; i++) {
			int nextR = r + dr[i];
			int nextC = c + dc[i];
			// 좌표가 범위안에 존재 확인
			if (nextC >= 0 && nextR >= 0 && nextC < I && nextR < I) {
				// 방문하지 않았다면
				if (!visited[nextR][nextC]) {
					visited[nextR][nextC] = 1;
					q.push({ nextR, nextC, cnt + 1 });
				}
			}
		}
	}
	return 0;
}