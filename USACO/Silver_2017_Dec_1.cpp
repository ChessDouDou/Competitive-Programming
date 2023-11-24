#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main () {
	//freopen("homework.in", "r", stdin);
	//freopen("homework.out", "w", stdout);
	int n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll prefix[n + 1];
	prefix[0] = 0;
	for (int i = 0; i < n; i++) {
		prefix[i + 1] = prefix[i];
		prefix[i + 1] += a[i];
	}
	ll minimum[n + 1];
	minimum[n] = a[n - 1];
	for (int i = n - 1; i >= 0; i--)
		minimum[i] = min(minimum[i + 1], a[i]);
	ll num = 0, den = 1;
	vector<int> ans;
	for (int i = 1; i <= n - 2; i++) {
		if ((prefix[n] - prefix[i] - minimum[i]) * den > num * (n - i - 1)) {
			num = prefix[n] - prefix[i] - minimum[i];
			den = n - i - 1;
		}
	}
	for (int i = 1; i <= n - 2; i++)
		if ((prefix[n] - prefix[i] - minimum[i]) * den == num * (n - i - 1))
			cout << i << endl;
	return 0;
}
