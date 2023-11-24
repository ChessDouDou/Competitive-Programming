#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second == b.second)
		return a.first < b.first;
    return a.second < b.second;
}

int area(int x1, int x2, int y1, int y2) {
	return (x2 - x1) * (y2 - y1);
}

int main() {
	//freopen("reduce.in", "r", stdin);
	//freopen("reduce.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int> > cows(n);
	for (int i = 0; i < n; i++)
		cin >> cows[i].first >> cows[i].second;
	pair<int, int> minXCows[4], minYCows[4], maxXCows[4], maxYCows[4];
	sort(cows.begin(), cows.end());
	for (int i = 0; i < 4; i++) {
		minXCows[i] = cows[i];
		maxXCows[i] = cows[n - i - 1];
	}
	sort(cows.begin(), cows.end(), cmp);
	for (int i = 0; i < 4; i++) {
		minYCows[i] = cows[i];
		maxYCows[i] = cows[n - i - 1];
	}
	int ans = INT_MAX;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					set<pair<int, int> > check;
					for (int xi = 0; xi < i; xi++)
						check.insert(minXCows[xi]);
					for (int xj = 0; xj < j; xj++)
						check.insert(minYCows[xj]);
					for (int xk = 0; xk < k; xk++)
						check.insert(maxXCows[xk]);
					for (int xl = 0; xl < l; xl++)
						check.insert(maxYCows[xl]);
					if (check.size() == 3) {
						pair<int, int> c[4] = {minXCows[i], minYCows[j], maxXCows[k], maxYCows[l]};
						int minX = 1e9, maxX = -1, minY = 1e9, maxY = -1;
						for (int a = 0; a < 4; a++) {
							minX = min(minX, c[a].first);
							maxX = max(maxX, c[a].first);
							minY = min(minY, c[a].second);
							maxY = max(maxY, c[a].second);
						}
						ans = min(ans, area(minX, maxX, minY, maxY));
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
