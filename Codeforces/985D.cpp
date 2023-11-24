#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, H;

bool check(ll spots) {
	if (spots <= H)
		return (spots * (spots + 1) / 2) >= n;
	ll maxArea = 0;
	if ((spots + H) % 2 == 0) {
		ll height = (spots + H) / 2;
		maxArea += height * (height - 1) / 2;
		maxArea -= H * (H - 1) / 2;
		maxArea += height * (height + 1) / 2;
	}
	else {
		ll height = (spots + H) / 2;
		maxArea += height * (height + 1) / 2;
		maxArea -= H * (H - 1) / 2;
		maxArea += height * (height + 1) / 2;
	}
	return maxArea >= n;
}

int main() {
	cin >> n >> H;
	ll lo = 1, hi = 2e9;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (check(mid))
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	cout << lo << endl;
	return 0;
}
