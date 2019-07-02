#include <iostream>
#include <cstdio>
#include <memory.h>
#include <vector>

using namespace std;

int g[901][901];
bool finish;
vector<int> relation;    // 模备包拌 历厘
int K;
int N;
void friends(int x)
{
	if (finish) {
		return;
	}
	if (relation.size() == K)
	{
		for (int i = 0; i < relation.size(); i++)
		{
			cout << relation[i] << endl;
		}
		finish = true;
		return;
	}
	if (x > N) return;

	int count = 0;
	for (int i = 0; i < relation.size(); i++)
	{
		if (g[relation[i]][x] == 1)
			count++;
	}
	if (count == relation.size()) {
		relation.push_back(x);
		friends(x + 1);
		relation.pop_back();
	}
	friends(x + 1);
}
int main()
{
	int F, x, y;
	cin >> K >> N >> F;
	for (int i = 0; i < F; i++)
	{
		cin >> x >> y;
		g[x][y] = 1;
		g[y][x] = 1;

	}
	friends(1);
	if (finish == false) cout << -1;
}