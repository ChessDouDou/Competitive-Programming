#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	long long n, x;
	cin >> n >> x;
	long long a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<long long> prefix(n);
	prefix[0] = a[0];
	for (int i = 1; i < n; i++)
		prefix[i] = prefix[i - 1] + a[i];
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long t = prefix[i] - x;
		auto l = lower_bound(prefix.begin(), prefix.end(), t);
		auto u = upper_bound(prefix.begin(), prefix.end(), t);
		ans += u - l;
		if (t == 0)
			ans++;
	}
	cout << ans << endl;
	return 0;
}