#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long a, b;
        cin >> a >> b;
        long long x = max(a, b);
        long long ans = x * x - x + 1;
        if (x % 2 == 1) {
            ans -= x - b;
            ans += x - a;
        }
        else {
            ans += x - b;
            ans -= x - a;
        }
        cout << ans << endl;
	}
	return 0;
}