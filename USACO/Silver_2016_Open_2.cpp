#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
	//freopen("diamond.in", "r", stdin);
	//freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    sort(d.begin(), d.end());
    vector<pair<int, int> > cases;
    for (int i = 0; i < n; i++) {
		auto upper = upper_bound(d.begin(), d.end(), d[i] + k);
		cases.push_back({i, upper - d.begin()});
	}
	int ans = -1;
	for (int i = 0; i < cases.size(); i++) {
		for (int j = i + 1; j < cases.size(); j++) {
			int firstCase = cases[i].second - cases[i].first;
			int secondCase = cases[j].second - cases[j].first;
			int overlap = 0;
			if (cases[i].second - cases[j].first > 0)
				overlap = cases[i].second - cases[j].first;
			ans = max(ans, firstCase + secondCase - overlap);
		}
	}
	cout << ans << endl;
    return 0;
}
