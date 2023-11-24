#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
ll N, ans = 0;

void solve(const vector<ll>& h) {
	vector<ll> with_h(N + 1);
	for (int i = 0; i < N; i++)
		with_h[h[i]] = i;
	set<ll> present;
	for (int cur_h = N; cur_h; cur_h--) {
		auto it = present.insert(with_h[cur_h]).first;
		if (next(it) != end(present))
			ans += *next(it) - *it + 1;
	}
}

int main() {
	cin >> N;
	vector<ll> h(N);
	for (int i = 0; i < N; i++)
		cin >> h[i];
	solve(h);
	reverse(begin(h), end(h));
	solve(h);
	cout << ans << endl;
	return 0;
}
