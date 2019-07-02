#include<iostream>
#include<vector>

using namespace std;

int MAX = 100000;

int vertex;
vector<vector<int> > matrix;

int dijkstra(int, int);

int main() {
	cin >> vertex;
	//vector<vector<int> > matrix;
	matrix.resize(vertex);

	int temp;
	for (int i = 0; i < vertex; i++) {
		for (int j = 0; j < vertex; j++) {
			cin >> temp;
			matrix[i].push_back(temp);
		}
	}
	
	//for (int i = 0; i < vertex; i++) {
	//	for (int j = 0; j < vertex; j++) {
	//		cout << matrix[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	int num;
	cin >> num;
	int start;
	int end;
	for (int i = 0; i < num; i++) {
		cin >> start >> end;
		cout << endl << dijkstra(start - 1, end - 1) << endl;
	}

	return 0;
}

int dijkstra(int start, int end) {
	vector<bool> check;
	vector<int> distance;

	check.resize(vertex);
	distance.resize(vertex, MAX);

	int now = start, next, weight, shortDistance;
	distance[now] = 0;

	while (check[now] == false) {
		check[now] = true;
		for (int i = 0; i < matrix[now].size(); i++) {
			next = i;
			weight = matrix[now][next];
			if (distance[next] > distance[now] + weight) {
				distance[next] = distance[now] + weight;
			}
		}

		shortDistance = MAX;
		for (int i = 0; i < check.size(); i++) {
			if (check[i] == false && (shortDistance > distance[i])) {
				shortDistance = distance[i];
				now = i;
			}
		}
	}

	return distance[end];
}