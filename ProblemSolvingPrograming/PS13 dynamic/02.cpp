#include<iostream>
#include<vector>

using namespace std;

vector<int> map;
vector<vector<vector<int> > > DP;
int answer;

void solve(vector<int>);
int COUNT(int, int, int);
int ABS(int);

int main() {
	int N;
	int NDP;
	vector<int> high;

	while (cin >> N) {
		high.resize(N);

		NDP = N + 1;
		// resize DP part;
		DP.resize(NDP);
		for (int i = 0; i < NDP; i++) {
			DP[i].resize(NDP);
			for (int j = 0; j < NDP; j++) {
				DP[i][j].resize(NDP);
			}
		}

		for (int i = 0; i < high.size(); i++) {
			cin >> high[i];
		}
		answer = 1;
		solve(high);

		cout << endl << answer << endl << endl;
	}

	return 0;
}


void solve(vector<int> high) {
	// make first & last to 1
	high[0] = 1;
	high[high.size() - 1] = 1;

	int prev = high[0];
	int next;
	int distance = 0;

	for (int i = 1; i < high.size(); i++) {
		if (high[i] == -1) {
			distance++;
		}
		else {
			if (high[i - 1] == -1) {
				//cout << "call COUNT" << endl;
				next = high[i];
				answer *= COUNT(prev, distance, next);
				distance = 0;
				//cout << answer << endl;
				prev = next;
			}
			else {
				prev = high[i];
			}
		}
	}
}

int COUNT(int prev, int distance, int next) {
	if (prev <= 0 || ABS(next - prev) - 1 > distance) {
		return 0;
	}

	if (DP[prev][next][distance] != 0) {
		return DP[prev][next][distance];
	}

	if (distance == 1) {
		if (ABS(next - prev) == 2) {
			DP[prev][next][distance] = 1;
			return 1;
		}
		else if (ABS(next - prev) == 1) {
			DP[prev][next][distance] = 2;
			return 2;
		}
		// this case means distance is 1
		else {
			// but prev, next is 1
			if (prev == 1 && next == 1) {
				DP[prev][next][distance] = 2;
				return 2;
			}
			// prev, next is not 1
			DP[prev][next][distance] = 3;
			return 3;
		}
	}

	int sum = 0;
	int temp = 0;
	for (int step = -1; step <= 1; step++) {
		temp = COUNT(prev + step, distance - 1, next);
		sum += temp;
	}
	DP[prev][next][distance] = sum;
	return sum;
}

int ABS(int input) {
	if (input > 0) {
		return input;
	}
	return -input;
}
