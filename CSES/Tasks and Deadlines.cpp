#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > t(n);
	for (int i = 0; i < n; i++)
		cin >> t[i].first >> t[i].second;
	sort(t.begin(), t.end());
	long long ans = 0, curr = 0;
	for (int i = 0; i < n; i++) {
		curr += t[i].first;
		ans += t[i].second - curr;
	}
	cout << ans << endl;
	return 0;
}