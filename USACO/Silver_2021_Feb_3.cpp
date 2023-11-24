#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int pasture[n][n];
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			cin >> pasture[y][x];
	int sumsBelow[n][n + 1], sumsAtMost[n][n + 1];
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			sumsBelow[y][x + 1] = sumsBelow[y][x] + (pasture[y][x] < 100 ? 1 : 0);
			sumsAtMost[y][x + 1] = sumsAtMost[y][x] + (pasture[y][x] <= 100 ? 1 : 0);
		}
	}
	long long ans = 0;
	for (int x1 = 0; x1 < n; x1++) {
		for (int x2 = x1 + 1; x2 <= n; x2++) {
			int y1 = -1, y2 = -1;
			for (int y0 = 0; y0 < n; y0++) {
				while (y1 < n && (y1 < y0 || sumsAtMost[y1][x2] - sumsAtMost[y1][x1] == 0))
					y1++;
				while (y2 < n && (y2 < y0 || sumsBelow[y2][x2] - sumsBelow[y2][x1] == 0))
					y2++;
				ans += y2 - y1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
