#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	//freopen("reststops.in", "r", stdin);
	//freopen("reststops.out", "w", stdout);
	ll L, N, rF, rB;
	cin >> L >> N >> rF >> rB;
	vector<pair<ll, ll> > restStops(N);
	for (int i = 0; i < N; i++)
		cin >> restStops[i].first >> restStops[i].second;
	vector<pair<int, int> > stops;
	stops.push_back(restStops[N - 1]);
	ll curr = stops[0].second;
	for (int i = N - 2; i >= 0; i--) {
		if (restStops[i].second > curr) {
			curr = restStops[i].second;
			stops.push_back(restStops[i]);
		}
	}
	sort(stops.begin(), stops.end());
	ll ans = 0, time = 0;
	for (auto s : stops) {
		ans += (s.first - time) * (rF - rB) * s.second;
		time = s.first;
	}
	cout << ans << endl;
	return 0;
}
