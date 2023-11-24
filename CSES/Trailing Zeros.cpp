#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long ans = 0;
	for (int i = 5; i <= n; i *= 5)
		ans += n / i;
	cout << ans << endl;
	return 0;
}