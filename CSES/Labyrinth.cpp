#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	bool visited[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = false;
	string grid[n];
	queue<pair<int, int> > q;
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'A') {
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
		}
	}
	int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
	char dc[4] = {'L', 'R', 'U', 'D'};
	int prev[n][m];
	int ci = -1, cj = -1;
	while (!q.empty()) {
		pair<int, int> a = q.front();
		q.pop();
		if (grid[a.first][a.second] == 'B') {
			ci = a.first;
			cj = a.second;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int x = a.first + dx[i];
			int y = a.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] != '#') {
				q.push(make_pair(x, y));
				prev[x][y] = i;
				visited[x][y] = true;
			}
		}
	}
	if (ci == -1 && cj == -1)
		cout << "NO" << endl;
	else {
		string ans = "";
		while (grid[ci][cj] != 'A') {
			int i = prev[ci][cj];
			ans += dc[i];
			ci -= dx[i];
			cj -= dy[i];
		}
		reverse(ans.begin(), ans.end());
		cout << "YES" << endl;
		cout << ans.length() << endl;
		cout << ans << endl;
	}
	return 0;
}