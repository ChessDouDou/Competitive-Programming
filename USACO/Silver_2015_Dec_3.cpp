#include <iostream>
using namespace std;

int main() {
	//freopen("bcount.in", "r", stdin);
	//freopen("bcount.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	int h[n + 1], g[n + 1], j[n + 1];
	h[0] = 0;
	g[0] = 0;
	j[0] = 0;
	for (int i = 1; i <= n; i++) {
		int cow;
		cin >> cow;
		if (i != 0) {
			h[i] = h[i - 1];
			g[i] = g[i - 1];
			j[i] = j[i - 1];
		}
		if (cow == 1)
			h[i]++;
		if (cow == 2)
			g[i]++;
		if (cow == 3)
			j[i]++;
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--;
		cout << h[b] - h[a] << " " << g[b] - g[a] << " " << j[b] - j[a] << endl;
	}
	return 0;
}
