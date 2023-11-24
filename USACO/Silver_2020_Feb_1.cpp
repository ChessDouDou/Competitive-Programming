#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> x[100010];

int main() {
	//freopen("swap.in", "r", stdin);
	//freopen("swap.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int l[m], r[m];
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		l[i]--;
	}
	vector<int> v;
	for (int i = 0; i < n; i++)
		v.push_back(i);
	for (int i = 0; i < m; i++)
		reverse(v.begin() + l[i], v.begin() + r[i]);
	int p[n];
	for (int i = 0; i < n; i++)
		p[v[i]] = i;
	int ans[n], cycle[n], pos[n];
	for (int i = 0; i < n; i++)
		ans[i] = cycle[i] = pos[i] = 0;
	int C = 1;
	for (int i = 0; i < n; i++) {
		if (!cycle[i]) {
			cycle[i] = C;
			x[C].push_back(i);
			int j = p[i];
			if (j != i) 
				pos[j] = 1;
			while (j != i) {
				cycle[j] = C;
				x[C].push_back(j);
				if (p[j] != i)
					pos[p[j]] = 1 + pos[j];
				j = p[j];
			}
			C++;
		}
	}
	for (int i = 0; i < n; i++)
		ans[x[cycle[i]][(pos[i] + k) % x[cycle[i]].size()]] = i;
	for (int i = 0; i < n; i++)
		cout << ans[i] + 1 << endl;
	return 0;
}
