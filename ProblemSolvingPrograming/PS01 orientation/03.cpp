#include <iostream>

using namespace std;

int cyclehas(int n, int x)
{
	if (n == x) return 1;
	while (n != 1) {
		if (n % 2 == 0) n /= 2;
		else n = 3 * n + 1;
		if (n == x) return 1;
	}
	return 0;
}

int main(void)
{
	int n, x;

	while (cin >> n >> x) {
		if (cyclehas(n, x)) cout << "Y" << endl;
		else cout << "N" << endl;
	}
	return 0;
}