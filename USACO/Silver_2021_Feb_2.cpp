#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	set<int> blocks;
	for (int i = 0; i < N; i++) {
		int years;
		cin >> years;
		blocks.insert((years + 11) / 12);
	}
	auto it = blocks.end();
	it--;
	vector<int> gaps;
	int ans = *it, last = 0;
	while (!blocks.empty()) {
		gaps.push_back(*blocks.begin() - last - 1);
		last = *blocks.begin();
		blocks.erase(*blocks.begin());
	}
	sort(gaps.begin(), gaps.end(), greater<int>());
	for (int i = 0; i < K - 1 && i < gaps.size(); i++)
		ans -= gaps[i];
	cout << ans * 12 << endl;
	return 0;
}
