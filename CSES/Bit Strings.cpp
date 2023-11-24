#include <iostream>
using namespace std;
const long long MOD = 1e9 + 7;

int main() {
	long long n;
	cin >> n;
	long long ans = 1;
	while (n--) {
		ans *= 2;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}