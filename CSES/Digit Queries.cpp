#include <iostream>
#include <climits>
#include <string>
using namespace std;

int main() {
	long long pow10[19];
	pow10[0] = 1;
	for (long long i = 1; i <= 18; i++)
		pow10[i] = pow10[i - 1] * 10;
	long long cutoff[19];
	cutoff[0] = 0;
	for (long long i = 1; i <= 18; i++)
		cutoff[i] = cutoff[i - 1] + 9 * i * pow10[i - 1];
	cutoff[18] = LLONG_MAX;
	long long q;
	cin >> q;
	while (q--) {
		long long k;
		cin >> k;
		for (long long i = 1; i <= 18; i++) {
			if (k <= cutoff[i]) {
				k -= cutoff[i - 1];
				long long num = pow10[i - 1] + k / i;
				if (k % i == 0)
					num--;
				string ans = to_string(num);
				cout << ans[(k + i - 1) % i] << endl;
				break;
			}
		}
	}
	return 0;
}