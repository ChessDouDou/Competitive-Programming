#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	long long dice[n + 1];
	dice[0] = 1;
	for (int i = 1; i <= n; i++)
		dice[i] = 0;
	for (int i = 1; i <= n; i++)
		for (int d = 1; d <= 6; d++)
			if (i - d >= 0) {
				dice[i] += dice[i - d];
				dice[i] %= MOD;
			}
	cout << dice[n] << endl;
	return 0;
}