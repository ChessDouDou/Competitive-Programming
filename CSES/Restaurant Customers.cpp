#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	int bi = 0, c = 0, ans = -1;
	for (int ai = 0; ai < n; ai++) {
		c++;
		while (b[bi] <= a[ai]) {
			c--;
			bi++;
		}
		ans = max(c, ans);
	}
	cout << ans << endl;
	return 0;
}