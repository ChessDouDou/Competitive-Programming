#include <iostream>
using namespace std;
int n, m, ans = 0;
string grid[1010];
bool visited[1010][1010];
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void dfs(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] != '.')
		return;
	visited[i][j] = true;
	for (int d = 0; d < 4; d++)
		dfs(i + dx[d], j + dy[d]);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && grid[i][j] == '.') {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}