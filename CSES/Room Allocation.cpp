#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int> > c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i].first.first >> c[i].first.second;
		c[i].second = i;
	}
	sort(c.begin(), c.end());
	int rooms[n];
	int ans = 0, r = 0;
	priority_queue<pair<int, int> > pq;
	for (int i = 0; i < n; i++) {
		if (pq.empty()) {
			r++;
			pq.push(make_pair(-c[i].first.second, r));
			rooms[c[i].second] = r;
		}
		else {
			pair<int, int> m = pq.top();
			if (-m.first < c[i].first.first) {
				pq.pop();
				pq.push(make_pair(-c[i].first.second, m.second));
				rooms[c[i].second] = m.second;
			}
			else {
				r++;
				pq.push(make_pair(-c[i].first.second, r));
				rooms[c[i].second] = r;
			}
		}
		ans = max(ans, (int)pq.size());
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << rooms[i] << " ";
	cout << endl;
	return 0;
}