#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	int children[N];
	for (int i = 0; i < N; i++)
		children[i] = 0;
	vector<int> edges[N];
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
		children[a]++;
		children[b]++;
	}
	for (int i = 1; i < N; i++)
		children[i]--;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int curr = 1;
		while (curr <= children[i]) {
			curr *= 2;
			ans++;
		}
		ans += children[i];
	}
	cout << ans << endl;
	return 0;
}
