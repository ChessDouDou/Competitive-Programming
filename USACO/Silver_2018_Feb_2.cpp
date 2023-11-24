#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, b;
vector<int> depths;
vector<pair<int, int> > shoes;
bool vis[250][250];
int ans = 1e9;

void dfs(int depth, int boot)  {
	if (vis[depth][boot])
		return;
	vis[depth][boot] = true;
	if (depth == n - 1) {
		ans = min(boot, ans);
		return;
	}
	for (int i = depth + 1; i <= depth + shoes[boot].second && i < n; i++)
		if (depths[i] <= shoes[boot].first)
			dfs(i, boot);
	for (int i = boot; i < b; i++)
		if (depths[depth] <= shoes[i].first)
			dfs(depth, i);
}

int main() {
	//freopen("snowboots.in", "r", stdin);
	//freopen("snowboots.out", "w", stdout);
	cin >> n >> b;
	depths.resize(n);
	for (int i = 0; i < n; i++)
		cin >> depths[i];
	shoes.resize(b);
	for (int i = 0; i < b; i++)
		cin >> shoes[i].first >> shoes[i].second;
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}
