#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll solve(ll a, ll b) {
	if (a == b)
		return 0;
	if (a > b) {
		if (a % 2 == 0)
			return 1 + solve(a / 2, b);
		else
			return 2 + solve((a + 1) / 2, b);
	}
	else if (a <= b / 2) {
		if (b % 2 == 0)
			return 1 + solve(a, b / 2);
		else
			return 2 + solve(a, (b - 1) / 2);
	}
	else {
		ll d = b - a, extra = 0;
		if (a % 2 == 1) {
			a++;
			extra++;
		}
		if (b % 2 == 1) {
			b--;
			extra++;
		}
		return min(d, 2 + extra + solve(a / 2, b / 2));
	}
}

int main() {
	ll N;
	cin >> N;
	while (N--) {
		ll a, b;
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
	return 0;
}
