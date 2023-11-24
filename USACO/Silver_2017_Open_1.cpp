#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int main () {
	//freopen("pairup.in", "r", stdin);
	//freopen("pairup.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int> > cow(n);
	for (int i = 0; i < n; i++)
		cin >> cow[i].first >> cow[i].second;
	sort(cow.begin(), cow.end(), cmp);
	int ans = 0, i = 0, j = n - 1;
	while (i <= j) {
		int x = min(cow[i].first, cow[j].first);
		if (i == j) 
			x /= 2;
		ans = max(ans, cow[i].second + cow[j].second);
		cow[i].first -= x;
		cow[j].first -= x;
		if (cow[i].first == 0)
			i++;
		if (cow[j].first == 0)
			j--;
	}
	cout << ans << endl;
	return 0;
}
