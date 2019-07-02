#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

#define MAX 11

double max = 15; 
// max means single max distance.
// root(200) is 14.142... so define max 15.

int N;
double matrix[MAX][MAX];

double calculDistance(int, int, int, int);
void makingGraph(vector<int>[]);
vector<double> prim();

int main() {
	vector<int> dot[2];

	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		dot[0].push_back(temp);
		cin >> temp;
		dot[1].push_back(temp);
	}
	
	makingGraph(dot);
	vector<double> distance = prim(); // this vector means distance of max in case index
	double max = distance[0];

	for (int i = 1; i < distance.size(); i++) {
		if (max < distance[i]) {
			max = distance[i];
		}
	}
	cout << endl << (int)ceil(max) << endl; // ceil means 4.2 or 4.6 to make 5

	return 0;
}

double calculDistance(int X1, int X2, int Y1, int Y2) { // caclulate distance using dot1, dot2
	int deltaX = X1 - X2;
	int deltaY = Y1 - Y2;
	return sqrt(deltaX * deltaX + deltaY * deltaY);
}

void makingGraph(vector<int> dot[]) { // use dot, making graph which have weight
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				matrix[i][j] = calculDistance(dot[0][i], dot[0][j], dot[1][i], dot[1][j]);
				// make graph using weight. [0][8] means number0 and number 8's distance
			}
		}
	}
}

vector<double> prim() {
	vector<bool> check(N); // it means make check[N], and it automatically fill all false
	vector<double> distance(N, max); // it means make distance[N], and fill all max

	int now = 0, next;
	double weight, shortDistance;
	distance[now] = 0;

	while (check[now] == false) {
		check[now] = true;

		for (int i = 0; i < N; i++) {
			next = i;
			if (now == next) { // don't check now is same with next case
				continue;
			}
			weight = matrix[now][next];
			if (distance[next] > weight && check[next] == false) {
				distance[next] = weight;
			}
		}

		shortDistance = max;
		for (int i = 0; i < check.size(); i++) {
			if (check[i] == false && (shortDistance > distance[i])) {
				shortDistance = distance[i];
				now = i;
			}
		}
	}
	return distance;
}