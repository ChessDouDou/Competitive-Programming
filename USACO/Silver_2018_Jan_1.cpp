#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//freopen("lifeguards.in", "r", stdin);
	//freopen("lifeguards.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int> > l(n);
	for (int i = 0; i < n; i++)
		cin >> l[i].first >> l[i].second;
	sort(l.begin(), l.end());
	int tot = 0, left = 0, right = 0;
	for (int i = 0; i < n; i++) {
		if (l[i].second > right) {
			left = max(right, l[i].first);
			tot += l[i].second - left;
			right = l[i].second;
		}
	}
	int res = tot;
	pair<int, int> last;
	last.first = l[n - 1].second;
	l.push_back(last);
	right = 0;
	for (int i = 0; i < n; i++) {
		int curRes = min(l[i + 1].first, l[i].second) - max(l[i].first, right);
		res = min(res, curRes);
		right = max(right, l[i].second);
	}
	res = max(res, 0); 
	cout << tot - res << endl;
	return 0;
}
