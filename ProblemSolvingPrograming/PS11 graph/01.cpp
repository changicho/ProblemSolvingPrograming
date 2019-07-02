#include<iostream>
#include<vector>

using namespace std;

vector<int> pickMafija;
vector<int> guess;
vector<bool> isChecked;

int numOfMafija = 0;

void solve(int, bool);

int main() {
	int n;
	while (cin >> n) {
		guess.resize(n, 0);
		isChecked.resize(n, false);

		int temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			pickMafija.push_back(temp - 1);

			guess[pickMafija[i]]++;
		}

		for (int i = 0; i < n; i++) { // start doubt person are mafija
			if (guess[i] == 0) {
				solve(i, true);
			}
		}

		for (int i = 0; i < n; i++) { // start no one is mafija
			solve(i, false);
		}

		cout << endl << numOfMafija << endl << endl;

		numOfMafija = 0;
		pickMafija.clear();
		guess.clear();
		pickMafija.clear();
		isChecked.clear();
	}

	return 0;
}

void solve(int x, bool mafija) {
	if (isChecked[x]) { // if x is already checked, return
		return;
	}
	if (mafija) { // if x is mafija case, count
		numOfMafija += 1;
	}

	isChecked[x] = true; // check x case

	int y = pickMafija[x]; // y is man who picked by x
	guess[y]--; // cause y picked by x, y's guess count --

	if (guess[y] == 0) {
		solve(y, !mafija); // calcul that y is mafjia case
	}
	else if (mafija) { // cause x is mafija
		solve(y, false); // calcul that y is not mafjia case
	}
}