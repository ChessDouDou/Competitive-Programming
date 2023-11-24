#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	int prev[n];
	bool visited[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
	queue<int> q;
	q.push(0);
	visited[0] = true;
	prev[0] = -1;
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		for (auto j : adj[i]) {
			if (!visited[j]) {
				q.push(j);
				visited[j] = true;
				prev[j] = i;
			}
		}
	}
	if (!visited[n - 1])
		cout << "IMPOSSIBLE" << endl;
	else {
		vector<int> path;
		int p = n - 1;
		while (p != -1) {
			path.push_back(p);
			p = prev[p]; 
		}
		reverse(path.begin(), path.end());
		cout << path.size() << endl;
		for (int i = 0; i < (int)path.size(); i++)
			cout << path[i] + 1 << " ";
		cout << endl;
	}
	return 0;
}