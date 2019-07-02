
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
	// map�� visted �迭 �ʱ�ȭ
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	// ť�� ����� �ִ��� Ȯ��
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
	// �湮üũ
	visited[r][c] = 1;
	q.push(loc);
	while (!q.empty()) {
		int r = q.front().cr;
		int c = q.front().cc;
		int cnt = q.front().cnt;
		q.pop();
		// ���� ���� Ȯ��
		if (r == desR && c == desC) {
			cout << cnt << endl;
			break;
		}
		// 8 �������� ��ǥ �̵�
		for (int i = 0; i < 8; i++) {
			int nextR = r + dr[i];
			int nextC = c + dc[i];
			// ��ǥ�� �����ȿ� ���� Ȯ��
			if (nextC >= 0 && nextR >= 0 && nextC < I && nextR < I) {
				// �湮���� �ʾҴٸ�
				if (!visited[nextR][nextC]) {
					visited[nextR][nextC] = 1;
					q.push({ nextR, nextC, cnt + 1 });
				}
			}
		}
	}
	return 0;
}