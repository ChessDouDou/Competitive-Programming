#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int mod;

bool cmp(const int& a, const int& b) {
	return (a % mod) > (b % mod);
}

int main() {
	//freopen("berries.in", "r", stdin);
	//freopen("berries.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> b(n);
	int maxB = -1;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		maxB = max(maxB, b[i]);
	}
	int ans = -1;
	for (int i = 1; i <= maxB; i++) {
		int baskets = 0;
		for (int j = 0; j < n; j++)
			baskets += b[j] / i;
		if (baskets < k / 2)
			continue;
		if (baskets >= k) {
			ans = max(ans, i * k / 2);
			continue;
		}
		mod = i;
		sort(b.begin(), b.end(), cmp);
		int curr = i * (baskets - k / 2);
		for (int j = 0; j < n && baskets + j < k; j++)
			curr += b[j] % i;
		ans = max(ans, curr);
	}
	cout << ans << endl;
	return 0;
}
