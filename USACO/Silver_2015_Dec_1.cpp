#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<pair<int, int> > switches[101][101];
bool visited[101][101];
bool on[101][101];

bool check(int i, int j) {
	bool left = (i - 1 >= 0 && visited[i - 1][j]);
	bool right = (i + 1 < n && visited[i + 1][j]);
	bool up = (j - 1 >= 0 && visited[i][j - 1]);
	bool down = (j + 1 < n && visited[i][j + 1]);
	return left || right || up || down;
}

void floodfill(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || !on[i][j])
		return;
	visited[i][j] = true;
	if (switches[i][j].size() != 0) {
		for (auto s : switches[i][j]) {
			int a = s.first, b = s.second;
			on[a][b] = true;
			if (check(a, b))
				floodfill(a, b);
		}
	}
	floodfill(i + 1, j);
	floodfill(i - 1, j);
	floodfill(i, j + 1);
	floodfill(i, j - 1);
}

int main() {
	//freopen("lightson.in", "r", stdin);
	//freopen("lightson.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		x--;
		y--;
		a--;
		b--;
		switches[x][y].push_back({a, b});
	}
	on[0][0] = true;
	floodfill(0, 0);
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (on[i][j])
				ans++;
	cout << ans << endl;
	return 0;
}
