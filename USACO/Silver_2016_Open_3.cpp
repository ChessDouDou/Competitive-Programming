#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> edges[3030];
bool closed[3030], visited[3030];

void dfs(int i) {
	if (visited[i] || closed[i])
		return;
	visited[i] = true;
	for (auto e : edges[i])
		dfs(e);
}

int count_components() {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (!closed[i] && !visited[i]) {
			dfs(i);
			counter++;
		}
	}
	return counter;
}

int main() {
	//freopen("closing.in", "r", stdin);
	//freopen("closing.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		for (int v = 0; v < n; v++)
			visited[v] = false;
		int counter = count_components();
		if (counter == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		int c;
		cin >> c;
		c--;
		closed[c] = true;
	}
	return 0;
}
