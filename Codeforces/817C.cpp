#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n, s;

ll sumDigits(ll x) {
	ll sum = 0;
	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

bool check(ll x) {
	return x - sumDigits(x) >= s;
}

int main() {
	cin >> n >> s;
	ll lo = 1, hi = n;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (check(mid))
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	cout << n - hi << endl;
	return 0;
}
