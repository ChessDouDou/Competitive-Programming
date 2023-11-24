#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, r1, c1, r2, c2;
string grid[51];
bool visited[51][51];
vector<pair<int, int> > components[2];

void floodfill(int i, int j, int index) {
	if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] != '0')
		return;
	visited[i][j] = true;
	components[index].push_back({i, j});
	floodfill(i + 1, j, index);
	floodfill(i - 1, j, index);
	floodfill(i, j + 1, index);
	floodfill(i, j - 1, index);
}

int cost(pair<int, int> x, pair<int, int> y) {
	return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

int main() {
	cin >> n >> r1 >> c1 >> r2 >> c2;
	r1--;
	c1--;
	r2--;
	c2--;
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	floodfill(r1, c1, 0);
	if (visited[r2][c2]) {
		cout << 0 << endl;
		return 0;
	}
	floodfill(r2, c2, 1);
	int ans = 1e9;
	for (auto i : components[0])
		for (auto j : components[1])
			ans = min(ans, cost(i, j));
	cout << ans << endl;
	return 0;
}
