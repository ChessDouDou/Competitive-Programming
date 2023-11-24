#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll n, m;
	cin >> n >> m;
	ll a[m + 1], b[m + 1];
	for (int i = 0; i <= m; i++)
		a[i] = b[i] = 0;
	for (int i = 0; i < n; i++) {
		int a1, b1;
		cin >> a1 >> b1;
		a[a1]++;
		b[b1]++;
	}
	ll diff[10010] = {};
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= m; j++) {
			diff[i + j] += a[i] * a[j];
			diff[i + j + 1] -= b[i] * b[j];
		}
	ll ans = 0;
	for (int i = 0; i < 2 * m + 1; i++) {
		ans += diff[i];
		cout << ans << endl;
	}
	return 0;
}
