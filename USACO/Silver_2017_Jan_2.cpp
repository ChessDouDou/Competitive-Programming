#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//freopen("hps.in","r",stdin);
	//freopen("hps.out","w",stdout);
	int n;
	cin >> n;
	int h[n + 1], p[n + 1], s[n + 1];
	h[0] = p[0] = s[0] = 0;
	for (int i = 1; i <= n; i++) {
		h[i] = h[i - 1];
		p[i] = p[i - 1];
		s[i] = s[i - 1];
		char c;
		cin >> c;
		if (c == 'H')
			h[i]++;
		if (c == 'P')
			p[i]++;
		if (c == 'S')
			s[i]++;
	}
	int ans = -1;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, h[i] + p[n] - p[i]);
		ans = max(ans, h[i] + s[n] - s[i]);
		ans = max(ans, p[i] + h[n] - h[i]);
		ans = max(ans, p[i] + s[n] - s[i]);
		ans = max(ans, s[i] + h[n] - h[i]);
		ans = max(ans, s[i] + p[n] - p[i]);
	}
	cout << ans << endl;
	return 0;
}
