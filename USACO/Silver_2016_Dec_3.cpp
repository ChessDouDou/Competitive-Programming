#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<pair<int, pair<int, int> > > edges;
bool visited[201];

bool check(int x1, int y1, int x2, int y2, int p) {
	int distance = (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
	return p * p >= distance;
}

int dfs(int i) {
	int depth = 0;
	visited[i] = true;
	for (int j = 0; j < n; j++) {
		int x1 = edges[i].second.first, y1 = edges[i].second.second;
		int x2 = edges[j].second.first, y2 = edges[j].second.second;
		int p = edges[i].first;
		if (check(x1, y1, x2, y2, p) && !visited[j]) {
			visited[j] = true;
			depth += dfs(j) + 1;
		}
	}
	return depth;
}

int main() {
	//freopen("moocast.in","r",stdin);
	//freopen("moocast.out","w",stdout);
	cin >> n;
	edges.resize(n);
	for (int i = 0; i < n; i++)
		cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < 201; i++)
			visited[i] = false;
		ans = max(ans, dfs(i) + 1);
	}
	cout << ans << endl;
	return 0;
}
