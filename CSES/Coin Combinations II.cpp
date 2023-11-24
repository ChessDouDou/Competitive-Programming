#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
	int n, x;
	cin >> n >> x;
	int c[n];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	int ans[x + 1];
	ans[0] = 1;
	for (int i = 1; i <= x; i++)
		ans[i] = 0;
	for (int j = 0; j < n; j++)
		for (int i = 1; i <= x; i++)
			if (i - c[j] >= 0) {
				ans[i] += ans[i - c[j]];
				ans[i] %= MOD;
			}
	cout << ans[x] << endl;
	return 0;
}