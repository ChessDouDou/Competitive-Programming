#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	ll grid[n][n];
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			cin >> grid[y][x];
	ll horizontalAnswer = 0;
	for (int y = 0; y < n; y++) {
		ll sums[2];
		sums[0] = sums[1] = 0;
		for (int x = 0; x < n; x++)
			sums[x % 2] += grid[y][x];
		horizontalAnswer += max(sums[0], sums[1]);
	}
	ll verticalAnswer = 0;
	for (int x = 0; x < n; x++) {
		ll sums[2];
		sums[0] = sums[1] = 0;
		for (int y = 0; y < n; y++)
			sums[y % 2] += grid[y][x];
		verticalAnswer += max(sums[0], sums[1]);
	}
	cout << max(horizontalAnswer, verticalAnswer) << endl;
	return 0;
}
