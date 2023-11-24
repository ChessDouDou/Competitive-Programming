#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	string grid[n];
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	int ans[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans[i][j] = 0;
	int a = 1, b = 1;
	for (int i = 0; i < n; i++) {
		if (grid[i][0] == '*')
			a = 0;
		if (grid[0][i] == '*')
			b = 0;
		ans[i][0] = a;
		ans[0][i] = b;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (grid[i][j] == '*')
				ans[i][j] = 0;
			else
				ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
			ans[i][j] %= MOD;
		}
	}
	cout << ans[n - 1][n - 1] << endl;
	return 0;
}