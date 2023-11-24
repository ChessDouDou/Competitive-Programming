#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int a[n], b[m];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	int ans = 0, ai = 0, bi = 0;
	while (ai < n && bi < m) {
		if (abs(a[ai] - b[bi]) <= k) {
			ans++;
			ai++;
			bi++;
		}
		else if (a[ai] - k > b[bi])
			bi++;
		else
			ai++;
	}
	cout << ans << endl;
	return 0;
}