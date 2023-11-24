#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> slopechg;

int main() {
	//freopen("teleport.in", "r", stdin);
	//freopen("teleport.out", "w", stdout);
	int N;
	long long current_f = 0, slope_f = 0, current_y = -2e9;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		current_f += abs(a - b);     
		if (abs(a) > abs(a - b))
			continue;
		slopechg[b] += 2;
		if (a < b && a < 0) {
			slopechg[0]--;
			slopechg[2 * b]--;
		}
		if (a < b && a >= 0) {
			slopechg[2 * b - 2 * a]--;
			slopechg[2 * a]--;
		}
		if (a >= b && a < 0) {
			slopechg[2 * b - 2 * a]--;
			slopechg[2 * a]--;
		}
		if (a >= b && a >= 0) {
			slopechg[0]--;
			slopechg[2 * b]--;
		}
	}
	long long ans = current_f;
	for (auto p : slopechg) {
		int new_y = p.first, delta_slope = p.second;
		current_f += slope_f * (new_y - current_y);
		current_y = new_y;
		slope_f += delta_slope;
		ans = min(ans, current_f);
	}
	cout << ans << endl;
	return 0;
}
