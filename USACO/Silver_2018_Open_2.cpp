#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//freopen("lemonade.in", "r", stdin);
	//freopen("lemonade.out", "w", stdout);
	int N;
	cin >> N;
	vector<int> w(N);
	for (int i = 0; i < N; i++)
		cin >> w[i];
	sort(w.begin(), w.end(), greater<int>());
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (w[i] >= i)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
