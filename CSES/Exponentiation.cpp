#include <iostream>
using namespace std;
const long long MOD = 1e9 + 7;

long long fast_pow(long long x, long long n) {
	long long res = 1;
	while (n > 0) {
		if (n & 1)
			res = (res * x) % MOD;
		x = (x * x) % MOD;
		n >>= 1;
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		long long a, b;
		cin >> a >> b;
		cout << fast_pow(a, b) << endl;
	}
	return 0;
}