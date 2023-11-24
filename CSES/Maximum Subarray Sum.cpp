#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long x[n], prefix[n];
	cin >> x[0];
	prefix[0] = x[0];
	long long m = min((long long)0, x[0]), ans = x[0];
	for (long long i = 1; i < n; i++) {
		cin >> x[i];
		prefix[i] = prefix[i - 1] + x[i];
		ans = max(ans, prefix[i] - m);
		m = min(m, prefix[i]);
	}
	cout << max(ans, prefix[n - 1]) << endl;
	return 0;
}