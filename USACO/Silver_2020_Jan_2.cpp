#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, k, m;

bool check(ll x) {
	ll days = k, g = 0;
	while (g < n && days > 0) {
		ll y = (n - g) / x;
		if (y < m) {
			ll counter = (n - g) / m;
			if ((n - g) % m != 0)
				counter++;
			return counter <= days;
		}
		ll maxDays = (n - g - x * y) / y + 1;
		if (maxDays > days) 
			maxDays = days;
		g += y * maxDays;
		days -= maxDays;
	}
	return g >= n;
}

int main() {
	//freopen("loan.in", "r", stdin);
	//freopen("loan.out", "w", stdout);
	cin >> n >> k >> m;
	ll l = 1, r = 1e12;
	while (l < r) {
		ll mid = l + (r - l + 1) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	cout << l << endl;
	return 0;
}
