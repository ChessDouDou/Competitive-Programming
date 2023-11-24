#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
long long n, t;
vector<long long> machine;

long long produce(long long mid) {
	long long p = 0;
	for (long long i = 0; i < n; i++) {
		p += mid / machine[i];
		if (p >= t)
			return t;
	}
	return p;
}

int main() {
	cin >> n >> t;
	for (long long i = 0; i < n; i++) {
		long long k;
		cin >> k;
		machine.push_back(k);
	}
	long long lo = 0, hi = 1e18;
	while (lo < hi) {
		long long mid = lo + (hi - lo) / 2;
		if (produce(mid) < t)
			lo = mid + 1;
		else
			hi = mid;
	}
	cout << lo << endl;
	return 0;
}