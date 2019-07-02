#include<iostream>
#include<vector>

using namespace std;

#define MAX 100

bool possible;
bool matrix[MAX][MAX];
int vertex;

bool contain(vector<int>, int);
void hamiltonian_cycle(int, vector<int>, int);

int main() {
	cin >> vertex;
	possible = false;

	int temp;
	for (int i = 0; i < vertex; i++) {
		for (int j = 0; j < vertex; j++) {
			cin >> temp;
			if (temp == 1) {
				matrix[i][j] = true;
			}
		}
	}

	vector<int> pass;
	pass.push_back(1);

	for (int i = 0; i < vertex - 1; i++) {
		pass.push_back(0);
	}

	hamiltonian_cycle(0, pass, 1);
	if (!possible) {
		cout << "none" << endl;
	}

	return 0;
}

bool contain(vector<int> pass, int item) {
	for (int i = 0; i < pass.size(); i++) {
		if (pass[i] == item) {
			return true;
		}
	}
	return false;
}

void hamiltonian_cycle(int v, vector<int> pass, int passIndex) {
	if (passIndex == vertex) {
		if (matrix[v][0] == true) {
			for (int i = 0; i < pass.size(); i++) {
				cout << pass[i] << " ";
			}
			cout << "1" << endl;
			possible = true;
		}
	}
	else if (passIndex < vertex) {
		for (int i = 0; i < vertex; i++) {
			if (matrix[v][i] == true && !contain(pass, i + 1)) {
				vector<int> passClone = pass;
				passClone[passIndex] = i + 1;
				hamiltonian_cycle(i, passClone, passIndex + 1);
			}
		}
	}
}