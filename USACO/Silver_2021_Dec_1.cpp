#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	int k, m, n;
	cin >> k >> m >> n;
	vector<pair<int, int> > grass(k);
	for (int i = 0; i < k; i++)
		cin >> grass[i].first >> grass[i].second;
	vector<int> f(m);
	for (int i = 0; i < m; i++)
		cin >> f[i];
	sort(grass.begin(), grass.end());
	sort(f.begin(), f.end());
	vector<pair<int, int> > intervals(k);
	for (int i = 0; i < k; i++) {
		auto lower = lower_bound(f.begin(), f.end(), grass[i].first);
		auto upper = upper_bound(f.begin(), f.end(), grass[i].first);
		if (lower != f.begin())
			lower--;
		int closest;
		if (upper == f.end())
			closest = grass[i].first - *lower;
		else
			closest = abs(min(grass[i].first - *lower, *upper - grass[i].first));
		intervals[i].first = grass[i].first - closest;
		intervals[i].second = grass[i].first + closest;
	}
	for (auto i : intervals)
		cout << i.first << " " << i.second << endl;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		continue;
	}
	cout << ans << endl;
	return 0;
}
