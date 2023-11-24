#include <iostream>
using namespace std;
typedef long long ll;

char solve(string s, ll n) {
	if (n <= s.length())
		return s[n - 1];
	ll x = s.length();
	while (2 * x < n)
		x *= 2;
	if (x + 1 == n)
		return solve(s, x);
	else
		return solve(s, n - x - 1);
}

int main() {
	//freopen("cowcode.in","r",stdin);
	//freopen("cowcode.out","w",stdout);
	string s;
	ll n;
	cin >> s >> n;
	cout << solve(s, n) << endl;
	return 0;
}
