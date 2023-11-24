#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

struct measurement {
	int day;
	int cow;
	int change;
};

bool cmp(const measurement& a, const measurement& b) {
	return a.day < b.day;
}

int main() {
	//freopen("measurement.in", "r", stdin);
	//freopen("measurement.out", "w", stdout);
	int N, G;
	cin >> N >> G;
	vector<measurement> m(N);
	for (int i = 0; i < N; i++)
		cin >> m[i].day >> m[i].cow >> m[i].change;
	sort(m.begin(), m.end(), cmp);
	map<int, int, greater<int> > cnts;
	cnts[0] = N + 1;
	int result = 0;
	map<int, int> mp;
	for (int i = 0; i < N; i++) {
		int& ref = mp[m[i].cow];
		bool wastop = ref == cnts.begin()->first;
		int wascnt = cnts[ref]--;
		if (wascnt == 1)
			cnts.erase(ref);
		ref += m[i].change;
		int iscnt = ++cnts[ref];
		bool istop = ref == cnts.begin()->first;
		if (wastop) {
			if (!istop || wascnt != 1 || iscnt != 1)
				++result;
		}
		else if (istop)
			++result;
	}
	cout << result << endl;
	return 0;
}
