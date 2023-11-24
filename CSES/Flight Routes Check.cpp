#include <iostream>
#include <vector>
using namespace std;
int n, m, ans = 0;
vector<int> new_roads;
vector<int> adj[100010][2];
bool visited[100010];

void dfs(int i, int x) {
	if (visited[i]) return;
	visited[i] = true;
	for (int j : adj[i][x])
		dfs(j, x);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a - 1][0].push_back(b - 1);
		adj[b - 1][1].push_back(a - 1);
	}
	dfs(0, 0);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			cout << "NO" << endl;
			cout << "1 " << i + 1 << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
		visited[i] = false;
	dfs(0, 1);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			cout << "NO" << endl;
			cout << i + 1 << " 1" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}