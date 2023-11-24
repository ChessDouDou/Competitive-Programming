#include <iostream>
#include <vector>
#include <set>
#include <tuple>
using namespace std;
bool vis[100][100];
int cows[100][100], di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1}, nCows, n, k, r;
set<tuple<int, int, int, int> > roads;

void ff(int i, int j, int i1, int j1) {
	if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || roads.count(tie(i, j, i1, j1)))
		return;
	vis[i][j] = true;
	nCows += cows[i][j];
	for (int k = 0; k < 4; k++)
		ff (i + di[k], j + dj[k], i, j);
}

int main () {
	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);
	cin >> n >> k >> r;
	for (int i = 0; i < r; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; 
		y1--; 
		x2--; 
		y2--;
		roads.insert(tie(y1, x1, y2, x2));
		roads.insert(tie(y2, x2, y1, x1));
	}
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		cows[y][x]++;
	}
	vector<int> cowsComponent;
	int totalCows = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j]) 
				continue;
			nCows = 0;
			ff (i, j, -1, -1);
			totalCows += nCows;
			if (nCows) 
				cowsComponent.push_back(nCows);
		}
	}
	int ans = 0;
	for (int i = 0; i < cowsComponent.size(); i++)
		for (int j = i + 1; j < cowsComponent.size(); j++)
			ans += cowsComponent[i] * cowsComponent[j];
	cout << ans << endl;
	return 0;
}
