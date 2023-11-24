#include <iostream>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > m(n);
	for (int i = 0; i < n; i++)
		cin >> m[i].first >> m[i].second;
	sort(m.begin(), m.end(), compare);
	int ans = 0, curr = 0;
	for (int i = 0; i < n; i++) {
		if (m[i].first >= curr) {
			ans++;
			curr = m[i].second;
		}
	}
	cout << ans << endl;
	return 0;
}