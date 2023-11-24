#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<pair<int, int> > swaps(K);
	for (int i = 0; i < K; i++) {
		cin >> swaps[i].first >> swaps[i].second;
		swaps[i].first--;
		swaps[i].second--;
	}
	vector<int> cows(N);
	set<int> ans[N];
	for (int i = 0; i < N; i++) {
		cows[i] = i;
		ans[i].insert(i);
	}
	for (int i = 0; i < K; i++) {
		ans[cows[swaps[i].first]].insert(swaps[i].second);
		ans[cows[swaps[i].second]].insert(swaps[i].first);
		swap(cows[swaps[i].first], cows[swaps[i].second]);
	}
	vector<vector<int> > cycles(N);
	int cycle[N], pos[N];
	for (int i = 0; i < N; i++)
		cycle[i] = pos[i] = 0;
	int C = 1;
	for (int i = 0; i < N; i++) {
		if (!cycle[i]) {
			cycle[i] = C;
			cycles[C - 1].push_back(i);
			int j = cows[i];
			if (j != i) 
				pos[j] = 1;
			while (j != i) {
				cycle[j] = C;
				cycles[C - 1].push_back(j);
				if (cows[j] != i)
					pos[cows[j]] = 1 + pos[j];
				j = cows[j];
			}
			C++;
		}
	}
	int finalAns[N];
	for (auto v : cycles) {
		if (v.empty())
			continue;
		set<int> curr;
		for (auto c : v)
			for (auto s : ans[c])
				curr.insert(s);
		for (auto c : v)
			finalAns[c] = curr.size();
	}
	for (int i = 0; i < N; i++)
		cout << finalAns[i] << endl;
	return 0;
}
