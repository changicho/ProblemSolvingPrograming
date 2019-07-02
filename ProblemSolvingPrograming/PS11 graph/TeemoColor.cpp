#include<iostream>
#include<vector>

using namespace std;

#define MAX 100

bool matrix[MAX][MAX];

int vertex, colorCount, drawCount;

void draw(int, vector<int>);

int main() {
	char temp;
	cin >> vertex;
	cin >> colorCount;

	drawCount = 0;
	
	//int count = 0;
	for (int i = 0; i < vertex; i++) {
		for (int j = i + 1; j < vertex; j++) {
			//count++;
			cin >> temp;
			if (temp == 'y') {
				matrix[i][j] = true;
				matrix[j][i] = true;
			}
		}
	}
	//cout << count << endl;

	vector<int> color(vertex, 0);
	color[0] = 1;
	draw(1, color);

	cout << endl << drawCount << endl;

	return 0;
}

void draw(int vindex, vector<int> color) {
	if (vindex == vertex) {
		drawCount++;
	}
	else if (vindex < vertex) {
		for (int i = 1; i <= colorCount; i++) {
			bool can = true;
			for (int j = 0; j < vertex; j++) {
				if (matrix[vindex][j] == true && color[j] == i) { // this means can reachable, but already fill same color
					can = false; // so fill is imposibble
					break;
				}
			}

			if (can) {
				vector<int> copy = color;
				copy[vindex] = i;
				draw(vindex + 1, copy);
			}
		}
	}
}