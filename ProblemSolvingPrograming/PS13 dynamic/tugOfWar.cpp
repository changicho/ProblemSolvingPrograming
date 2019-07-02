#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int sum(vector<int>);
int get_count(vector<int>);
void tug_of_war(vector<int>);
int ABS(int NUM);

int main() {
	int humanCount, TEMP;
	while (cin >> humanCount)
	{
		vector<int> humans;
		for (int i = 0; i < humanCount; i++)
		{
			cin >> TEMP;
			humans.push_back(TEMP);
		}
		cout << endl;
		tug_of_war(humans);
	}

	return 0;
}

int ABS(int NUM) {
	if (NUM < 0) {
		return -NUM;
	}
	return NUM;
}

int sum(vector<int> array) {
	int sum = 0;
	for (int i = 0; i < array.size(); i++)
		sum += array[i];
	return sum;
}

int get_count(vector<int> array) {
	int count = 0;
	for (int i = 0; i < array.size(); i++)
		if (array[i] > 0)
			count++;
	return count;
}

void tug_of_war(vector<int> humans) {
	std::sort(humans.begin(), humans.end());

	vector<int> left;
	vector<int> right;

	int left_index = 0, right_index = 0;

	for (int i = humans.size() - 1; i >= 0; i--)
	{
		if (sum(left) < sum(right)) {
			left.push_back(humans[i]);
			continue;
		}
		else {
			right.push_back(humans[i]);
			continue;
		}
	}

	//this part is make left & right's count similar
	while (get_count(left) - get_count(right) > 1) {
		right.push_back(left.back());
		left.pop_back();
	}
	while (get_count(right) - get_count(left) > 1) {
		left.push_back(right.back());
		right.pop_back();
	}

	int left_sum = sum(left), right_sum = sum(right);
	int difference = ABS(left_sum - right_sum);
	int left_c_index, right_c_index;

	do {
		left_c_index = right_c_index = -1;

		for (int i = 0; i < left.size(); i++) {
			for (int j = 0; j < right.size(); j++) {
				int temp_left_sum = left_sum - left[i] + right[j];
				int temp_right_sum = right_sum + left[i] - right[j];

				if (difference > ABS(temp_left_sum - temp_right_sum)) {
					difference = ABS(temp_left_sum - temp_right_sum);
					left_c_index = i;
					right_c_index = j;
				}
			}
		}

		if (left_c_index >= 0 && right_c_index >= 0) {
			int swap = left[left_c_index];
			left[left_c_index] = right[right_c_index];
			right[right_c_index] = swap;
			left_sum = sum(left);
			right_sum = sum(right);
		}

	} while (left_c_index > -1 && right_c_index > -1);

	if (left_sum > right_sum) {
		cout << right_sum << " " << left_sum << endl << endl;
	}
	else {
		cout << left_sum << " " << right_sum << endl << endl;
	}

}