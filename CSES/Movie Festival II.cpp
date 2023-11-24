#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int> > m(n);
	for (int i = 0; i < n; i++)
		cin >> m[i].second >> m[i].first;
	sort(m.begin(), m.end());
	int ans = 0;
	multiset<int> t;
	for (int i = 0; i < k; i++)
		t.insert(0);
	for (int i = 0; i < n; i++) {
		auto it = t.upper_bound(m[i].second);
		if (it == t.begin())
			continue;
		t.erase(--it);
		t.insert(m[i].first);
		ans++;
	}
	cout << ans << endl;
	return 0;
}