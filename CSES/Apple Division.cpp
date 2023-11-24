#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n, total = 0;
ll ans = 1e12;
vector<ll> p;

void solve(ll sum, ll i) {
	if (i == n) {
		ans = min(ans, abs((total - sum) - (sum)));
		return;
	}
	solve(sum + p[i], i + 1);
	solve(sum, i + 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		p.push_back(x);
		total += x;
	}
	sort(p.begin(), p.end());
	solve(0, 0);
	cout << ans << endl;
	return 0;
}