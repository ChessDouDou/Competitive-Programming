#include <iostream>
#include <vector>
using namespace std;
vector<int> edges[100010];
int component[100010], C = 1;
string s;

void dfs(int i) {
	if (component[i])
		return;
	component[i] = C;
	for (auto j : edges[i])
		if (s[j] == s[i])
			dfs(j);
}

int main() {
	//freopen("milkvisits.in", "r", stdin);
	//freopen("milkvisits.out", "w", stdout);
	int N, M;
	cin >> N >> M >> s;
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	for (int i = 0; i < N; i++)
		if (!component[i]) {
			dfs(i);
			C++;
		}
	while (M--) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		a--;
		b--;
		bool ans = false;
		if (component[a] != component[b] || s[a] == c)
			ans = true;
		cout << ans;
	}
	cout << endl;
	return 0;
}
