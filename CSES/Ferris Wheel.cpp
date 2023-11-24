#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int p[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p, p + n);
	int start = 0, end = n - 1, ans = 0;
	while (start <= end) {
		ans++;
		if (p[start] + p[end] <= x) {
			start++;
			end--;
		}
		else
			end--;
	}
	cout << ans << endl;
	return 0;
}