#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	//freopen("helpcross.in","r",stdin);
	//freopen("helpcross.out","w",stdout);
	int c, n;
	cin >> c >> n;
	multiset<int> chicken;
	for (int i = 0; i < c; i++) {
		int t;
		cin >> t;
		chicken.insert(t);
	}
	vector<pair<int, int> > cow(n);
	bool paired[n];
	for (int i = 0; i < n; i++) {
		cin >> cow[i].first >> cow[i].second;
		paired[i] = false;
	}
	sort(cow.begin(), cow.end(), cmp);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		auto c = chicken.lower_bound(cow[i].first);
		if (c != chicken.end() && *c <= cow[i].second) {
			ans++;
			chicken.erase(c);
		}
	}
	cout << ans << endl;
	return 0;
}
