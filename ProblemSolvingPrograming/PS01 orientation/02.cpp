#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(void)
{
	string line;
	int n;

	while (getline(cin, line)) {
		istringstream iss(line);
		if (line[0] == '0') {
			iss >> hex >> n;
			cout << n << endl;
		}
		else {
			iss >> n;
			cout << "0x";
			cout << hex << uppercase << n << endl;
		}
	}
	return 0;
}