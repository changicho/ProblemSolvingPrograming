// BOJ 11404
#include <iostream>

using namespace std;

#define INFINITE INT_MAX
#define ARR_SIZE 100 + 1 

int vertex, edge; // vertex : num of dot, edge : num of line
int arr[ARR_SIZE][ARR_SIZE];
int from, to, weight;

void floyd();
int MIN(int, int);

int main() {
	cin >> vertex >> edge;

	for (int i = 1; i <= vertex; i++) { // set vectex table to INFINITE
		for (int j = 1; j <= vertex; j++) {
			arr[i][j] = INFINITE;
		}
	}

	for (int i = 0; i < edge; i++) { // make graph table, with weight
		cin >> from >> to >> weight;
		if (arr[from][to] > weight) {
			arr[from][to] = weight;
		}
	}

	// start Floyd-Warshall Algorithm
	floyd();

	// print final graph table
	for (int i = 1; i <= vertex; i++) {
		for (int j = 1; j <= vertex; j++) {
			if (i == j || arr[i][j] == INFINITE) {
				cout << 0 << " ";
			} else {
				cout << arr[i][j] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}

void floyd() {
	for (int i = 1; i <= vertex; i++) { // if i go by vertex
		for (int j = 1; j <= vertex; j++) { // from vertex
			for (int k = 1; k <= vertex; k++) { // to vertex
				if (arr[j][i] != INFINITE && arr[i][k] != INFINITE) {
					arr[j][k] = MIN(arr[j][k], arr[j][i] + arr[i][k]);
				}
			}
		}
	}
}

int MIN(int first, int second) {
	if (first > second) {
		return second;
	}
	return first;
}