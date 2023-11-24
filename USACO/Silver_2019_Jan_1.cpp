#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//freopen("planting.in", "r", stdin);
	//freopen("planting.out", "w", stdout);
	int N;
	cin >> N;
	vector<int> edges[N];
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	int ans = -1;
	for (int i = 0; i < N; i++)
		ans = max(ans, (int)edges[i].size());
	cout << ans + 1 << endl;
	return 0;
}
