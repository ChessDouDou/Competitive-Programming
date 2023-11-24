#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long n, k;
vector<long long> x;

long long f(long long sum) {
	long long g = 1, curr = 0;
	for (int i = 0; i < n; i++) {
		if (curr + x[i] > sum) {
			g++;
			curr = x[i];
		}
		else
			curr += x[i];
	}
	return g;
}

int main() {
	cin >> n >> k;
	x.resize(n);
	long long lo = -1, hi = 1e18;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		lo = max(lo, x[i]);
	}
	while (lo < hi) {
		long long mid = lo + (hi - lo) / 2;
		long long g = f(mid);
		if (g > k)
			lo = mid + 1;
		else
			hi = mid;
	}
	cout << lo << endl;
	return 0;
}