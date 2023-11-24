#include <iostream>
using namespace std;

int main() {
	//freopen("maxcross.in","r",stdin);
	//freopen("maxcross.out","w",stdout);
	int n, k, b;
	cin >> n >> k >> b;
	bool lights[n];
	for (int i = 0; i < n; i++)
		lights[i] = true;
	for (int i = 0; i < b; i++) {
		int s;
		cin >> s;
		s--;
		lights[s] = false;
	}
	int curr = 0;
	for (int i = 0; i < k; i++)
		if (!lights[i])
			curr++;
	int ans = curr;
	for (int i = k; i < n; i++) {
		if (!lights[i])
			curr++;
		if (!lights[i - k])
			curr--;
		ans = min(ans, curr);
	}
	cout << ans << endl;
	return 0;
}
