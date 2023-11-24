#include <iostream>
#include <vector>
using namespace std;
int n, m, ans = 0;
vector<int> new_roads;
vector<int> adj[100010];
bool visited[100010];

void dfs(int i) {
	if (visited[i]) return;
	visited[i] = true;
	for (int j : adj[i])
		dfs(j);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i);
			ans++;
			new_roads.push_back(i + 1);
		}
	}
	cout << ans - 1 << endl;
	for (int i = 0; i < ans - 1; i++)
		cout << new_roads[i] << " " << new_roads[i + 1] << endl;
	return 0;
}