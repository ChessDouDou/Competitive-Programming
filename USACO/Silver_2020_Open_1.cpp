#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define INF 2000000000
int n, m;
vector<pair<ll, ll> > intervals;

bool check(ll d) {
	ll prev = -1ll * INF * INF;
	int counter = 0;
	for (auto i : intervals) {
		while (max(prev + d, i.first) <= i.second) {
			prev = max(prev + d, i.first);
			counter++;
			if (counter >= n)
				break;
		}
		if (counter >= n)
			break;
	}
	return counter >= n;
}

int main() {
	//freopen("socdist.in","r",stdin);
	//freopen("socdist.out","w",stdout);
	cin >> n >> m;
	intervals.resize(m);
	for (int i = 0; i < m; i++) 
		cin >> intervals[i].first >> intervals[i].second;
	sort(intervals.begin(), intervals.end());
	ll lo = 1, hi = 1LL * INF * INF, ans = -1;
	while (lo < hi) {
		ll mid = lo + (hi - lo + 1) / 2;
		if (check(mid)) {
			lo = mid;
			ans = mid;
		}
		else
			hi = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
