#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int answer;

void solve(vector<int>);
int count(int, int, int);

int main() {

	int N;
	vector<int> high;

	while (cin >> N) {
		high.resize(N);

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
				//cout << "call count" << endl;
				next = high[i];
				answer *= count(prev, distance, next);
				distance = 0;
				prev = next;
			}
			else {
				prev = high[i];
			}
		}
	}
}

int count(int prev, int distance, int next) {
	if (prev < 0 || abs(next - prev) - 1 > distance) {
		return 0;
	}

	if (distance == 1) {
		if (abs(next - prev) == 2) {
			return 1;
		}
		else if (abs(next - prev) == 1 || (prev == 0 && next == 0)) {
			return 2;
		}
		else {
			return 3;
		}
	}

	int sum = 0;
	for (int step = -1; step <= 1; step++) {
		sum += count(prev + step, distance - 1, next);
	}
	return sum;
}