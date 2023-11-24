#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	long long ans[n + 1];
	ans[0] = 0;
	for (int i = 1; i <= n; i++)
		ans[i] = 1e9;
	for (int i = 1; i <= n; i++) {
		int tmp = i;
		while (tmp != 0) {
			ans[i] = min(ans[i], ans[i - tmp % 10] + 1);
			tmp /= 10;
		}
	}
	cout << ans[n] << endl;
	return 0;
}