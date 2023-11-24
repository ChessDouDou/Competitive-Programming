#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const int& a, const int& b) {
	return a > b;
}

int main() {
	int N, K, L;
	cin >> N >> K >> L;
	int c[N];
	for (int i = 0; i < N; i++)
		cin >> c[i];
	sort(c, c + N, cmp);
	int lo = 0, hi = N;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		long long needed = 0;
		for (int i = 0; i < mid; i++)
			needed += (long long)max(0, mid - c[i]);
		if (needed <= (long long)K * L && c[mid - 1] + K >= mid)
			lo = mid;
		else
			hi = mid - 1;
	}
	cout << hi << endl;
	return 0;
}
