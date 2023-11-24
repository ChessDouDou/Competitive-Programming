#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<pair<int, int> > g[100010];
vector<int> p, component;

void dfs(int v, int label, int minW) {
	component[v] = label;
	for (auto x: g[v]) {
		if (x.second < minW || component[x.first] != -1) 
			continue;
		dfs(x.first, label, minW);
	}
}

bool check(int minW) {
	for (int i = 0; i < component.size(); i++)
		component[i] = -1;
	int label = 0;
	for (int i = 0; i < n; i++) {
		if (component[i] != -1) 
			continue;
		dfs(i, label, minW);
		label++;
	}
	for (int i = 0; i < n; i++)
		if (component[i] != component[p[i]]) 
			return false;
	return true;
}

int main() {
	//freopen("wormsort.in", "r", stdin);
	//freopen("wormsort.out", "w", stdout);
	cin >> n >> m;
	component.resize(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		p.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--; 
		b--;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	int ans = -1;
	int l = 1, r = 1e9 + 1;
	while (l < r) {
		int mid = l + (r - l + 1) / 2;
		if (check(mid)) {
			ans = max(ans, mid);
			l = mid;
		} 
		else
			r = mid - 1;
	}
	if (ans == 1e9 + 1)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}
