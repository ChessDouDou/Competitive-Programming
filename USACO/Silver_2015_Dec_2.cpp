#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main() {
	//freopen("highcard.in", "r", stdin);
	//freopen("highcard.out", "w", stdout);
	int n;
	cin >> n;
	set<int> b, e;
	for (int i = 1; i <= 2 * n; i++)
		b.insert(i);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		e.insert(x);
		b.erase(x);
	}
	int ans = 0;
	auto x = b.begin(), y = e.begin();
	for (int i = 0; i < n; i++) {
		int currB = *x, currE = *y;
		if (currB > currE) {
			x++;
			y++;
			ans++;
		}
		else {
			x++;
		}
		if (x == b.end() || y == e.end())
			break;
	}
	cout << ans << endl;
	return 0;
}
