#include <iostream>
#include <vector>
using namespace std;
int n;
int sum0, sum1, nodes0, nodes1;
int clocks[100000];
vector<int> edges[100000];

void dfs(int i, int color, int par) {
	if (color == 0) {
		nodes0++;
		sum0 += clocks[i];
	}
	else {
		nodes1++;
		sum1 += clocks[i];
	}
	for (int j : edges[i])			   
		if (j != par)
			dfs(j, 1 - color, i);
}

int main() {
	//freopen("clocktree.in", "r", stdin);
	//freopen("clocktree.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> clocks[i];
	for (int i = 0; i < n - 1; i++) {	
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0, 0, -1);
	if (sum0 % 12 == sum1 % 12)
		cout << n << endl;
	else if (sum0 % 12 == (sum1 + 1) % 12)
		cout << nodes0 << endl;
	else if ((sum0 + 1) % 12 == sum1 % 12)
		cout << nodes1 << endl;
	else
		cout << 0 << endl;
	return 0;
}
