#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string line;

	while (getline(cin, line)) {
		int words = 1, letters = 0;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == ' ') words++;
			else letters++;
		}
		cout << words << " " << letters << endl;
	}
	return 0;
}
