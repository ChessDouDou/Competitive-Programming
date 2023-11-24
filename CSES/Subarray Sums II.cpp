#include <iostream>
#include <map>
using namespace std;

int main() {
	long long n, x;
	cin >> n >> x;
	long long a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long prefix = 0, ans = 0;
	map<long long, long long> sums;
	sums[0] = 1;
	for (int i = 0; i < n; i++) {
		prefix += a[i];
		ans += sums[prefix - x];
		sums[prefix]++;
	}
	cout << ans << endl;
	return 0;
}