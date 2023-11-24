#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
vector<pair<ll, ll> > tree;
ll component[100010];
ll C = 1;

void dfs(ll i) {
	if (component[i])
		return;
	component[i] = C;
	dfs(tree[i].first);
}

int main() {
	ll N;
	cin >> N;
	for (ll i = 0; i < N; i++) {
		ll a, v;
		cin >> a >> v;
		a--;
		tree.push_back({a, v});
	}
	for (ll i = 0; i < N; i++) {
		if (!component[i]) {
			dfs(i);
			C++;
		}
	}
	ll ans = 0;
	ll minimum[C - 1];
	for (ll i = 0; i < C - 1; i++)
		minimum[i] = 1e18;
	for (ll i = 0; i < N; i++) {
		ans += tree[i].second;
		minimum[component[i] - 1] = min(minimum[component[i] - 1], tree[i].second);
	}
	for (ll i = 0; i < C - 1; i++)
		ans -= minimum[i];
	cout << ans << endl;
	return 0;
}
