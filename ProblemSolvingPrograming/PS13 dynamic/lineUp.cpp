#include <iostream>

using namespace std;

long combi(int, int);
long perm(int);
long visit(int, int, int, int, int);

int main(void) {
	int tn, ti, n, p, r, i;
	long t = 0;
	cin >> n >> p >> r;

	for (i = p - 1; i <= n - r; i++) {
		t += visit(i, p - 1, 0, 0, i) *
			visit(n - i - 1, r - 1, 1, i + 1, n) *
			combi(n - 1, i);
	}
	// p - 1 부터 n – r 까지 돌면서 p명과 r명이
	// 보이는 조건을 만족하는 경우의 수에
	// (n-1)C(i)를 곱한다.
	cout << t << endl;

	return 0;
}

// nCr
long combi(int n, int r) {
	int i;
	long t = 1;

	for (i = r + 1; i <= n; i++) {
		t *= i;
	}

	for (i = 1; i <= n - r; i++) {
		t /= i;
	}

	return t;
}

// nPr
long perm(int n) {
	long i, t = 1;

	for (i = 1; i <= n; i++) {
		t *= i;
	}

	return t;
}

// n: 나눠진 부분에 있는 사람 수
// k: 이 부분에서 보여야 하는 사람 수
// s: 왼쪽인지 오른쪽인지 구분
// x, y: 나눠진 부분의 왼쪽 끝과 오른쪽 끝
long visit(int n, int k, int s, int x, int y) {
	int i;
	long t = 0;

	// 이 부분에서 보여야 하는 사람 수가 없으면
	if (k == 0) {
		if (n == 0) { // 남는 사람 수가 0이면 만족
			return 1;
		}
		else {
			return 0;
		}
	}
	if (s == 0) { // left part
		for (i = x + k - 1; i < y; i++)
			t += visit(i - x, k - 1, 0, x, i) *
			combi(n - 1, i - x) * perm(y - i - 1);
	}
	else { // right part
		for (i = x; i < y - k + 1; i++)
			t += visit(n - (i - x) - 1, k - 1, 1, i + 1, y)
			* combi(n - 1, i - x) * perm(i - x);
	}
	return t;
}