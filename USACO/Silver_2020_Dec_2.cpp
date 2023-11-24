#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll prefix[2510][2510];

bool cmp(const pair<ll, ll>& a, const pair<ll, ll>& b) {
	return a.second < b.second;
}

ll psum(ll x1, ll y1, ll x2, ll y2) {
	return prefix[x2 + 1][y2 + 1] - prefix[x2 + 1][y1] - prefix[x1][y2 + 1] + prefix[x1][y1];
}

int main() {
	ll N;
	cin >> N;
	vector<pair<ll, ll> > points(N);
	for (ll i = 0; i < N; i++)
		cin >> points[i].first >> points[i].second;
	sort(points.begin(), points.end());
	for (ll i = 0; i < N; i++)
		points[i].first = i + 1;
	sort(points.begin(), points.end(), cmp);
	for (ll i = 0; i < N; i++)
		points[i].second = i + 1;
	for (ll i = 0; i < N; i++)
		prefix[points[i].first][points[i].second] = 1;
	for (ll i = 1; i <= N; i++)
		for (ll j = 1; j <= N; j++)
			prefix[i][j] += prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
	ll ans = 0;
	for (ll i = 0; i < N; i++) {
		for (ll j = i; j < N; j++) {
			ll x1 = min(points[i].first, points[j].first) - 1;
			ll x2 = max(points[i].first, points[j].first) - 1;
			ans += psum(0, i, x1, j) * psum(x2, i, N - 1, j);
		}
	}
	cout << ans + 1 << endl;
	return 0;
}
