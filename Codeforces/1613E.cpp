#include <iostream>
#include <queue>
using namespace std;
int n, m;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		string grid[n];
		for (int i = 0; i < n; i++)
			cin >> grid[i];
		queue<pair<int, int> > q;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (grid[i][j] == 'L')
					q.push({i, j});
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i1 = 0; i1 < 4; i1++) {
				int newX = x + dx[i1], newY = y + dy[i1];
				if (!valid(newX, newY) || grid[newX][newY] != '.')
					continue;
				int counter = 0;
				for (int i2 = 0; i2 < 4; i2++) {
					int newerX = newX + dx[i2], newerY = newY + dy[i2];
					if (valid(newerX, newerY) && grid[newerX][newerY] == '.')
						counter++;
				}
				if (counter <= 1) {
					grid[newX][newY] = '+';
					q.push({newX, newY});
				}
			}
		}
		for (int i = 0; i < n; i++)
			cout << grid[i] << "\n";
	}
	return 0;
}
