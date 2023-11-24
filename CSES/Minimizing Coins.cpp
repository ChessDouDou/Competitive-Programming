#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int c[n];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	long long ans[x + 1];
	ans[0] = 0;
	for (int i = 1; i <= x; i++)
		ans[i] = 1e9;
	for (int i = 1; i <= x; i++)
		for (int j = 0; j < n; j++)
			if (i - c[j] >= 0)
				ans[i] = min(ans[i], ans[i - c[j]] + 1);
	// for (int i = 0; i < x; i++)
	// 	cout << ans[i] << " ";
	if (ans[x] == 1e9)
		cout << -1 << endl;
	else
		cout << ans[x] << endl;
	return 0;
}