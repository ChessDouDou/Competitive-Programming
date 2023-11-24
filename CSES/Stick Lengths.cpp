#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long p[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p, p + n);
	long long median = p[n / 2], ans = 0;
	for (int i = 0; i < n; i++)
		ans += abs(median - p[i]);
	cout << ans << endl;
	return 0;
}