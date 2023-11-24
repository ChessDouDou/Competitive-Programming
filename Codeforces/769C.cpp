#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, k;
string grid[1001];
int dist[1001][1001];
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, -1, 1, 0};
char c[4] = {'D', 'L', 'R', 'U'};
string path = "";

bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '*';
}

void calcDistance(int x, int y) {
	queue<pair<int, int> > q;
	q.push({x, y});
	dist[x][y] = 0;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int i = p.first, j = p.second, d = dist[i][j];
		for (int index = 0; index < 4; index++) {
			int newI = i + dx[index];
			int newJ = j + dy[index];
			if (valid(newI, newJ) && dist[newI][newJ] == -1) {
				q.push({newI, newJ});
				dist[newI][newJ] = d + 1;
			}
		}
	}
}

void dfs(int i, int j) {
	if (!k)
		return;
	for (int index = 0; index < 4; index++) {
		int newI = i + dx[index];
		int newJ = j + dy[index];
		if (valid(newI, newJ) && dist[newI][newJ] < k) {
			k--;
			path += c[index];
			dfs(newI, newJ);
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	if (k % 2 == 1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dist[i][j] = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == 'X') {
				calcDistance(i, j);
				dfs(i, j);
			}
	if (path == "")
		cout << "IMPOSSIBLE" << endl;
	else
		cout << path << endl;
	return 0;
}
