#include <iostream>
#include <map>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long prefix = 0, ans = 0;
	long long sums[n];
	sums[0] = 1;
	for (int i = 1; i < n; i++)
		sums[i] = 0;
	for (int i = 0; i < n; i++) {
		prefix += a[i];
		prefix = (prefix % n + n) % n;
		ans += sums[prefix];
		sums[prefix]++;
	}
	cout << ans << endl;
	return 0;
}