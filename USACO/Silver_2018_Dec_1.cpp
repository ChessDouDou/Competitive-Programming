#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, C;
vector<int> cows;

bool check(int t) {
	int bus = 1, minCow = cows[0], index = 0;
	for (int i = 1; i < N; i++) {
		if (cows[i] - minCow > t || i - index + 1 > C) {
			bus++;
			minCow = cows[i];
			index = i;
		}
	}
	return bus <= M;
}

int main() {
	//freopen("convention.in", "r", stdin);
	//freopen("convention.out", "w", stdout);
	cin >> N >> M >> C;
	cows.resize(N);
	for (int i = 0; i < N; i++)
		cin >> cows[i];
	sort(cows.begin(), cows.end());
	int lo = 1, hi = 1e9;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (check(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << lo << endl;
	return 0;
}
