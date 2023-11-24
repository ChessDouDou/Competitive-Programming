#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

struct Cow {
	ll a;
	ll t;
	ll index;
};

bool cmp(Cow& a, Cow& b) {
	return a.a < b.a;
}

bool cmp2(Cow& a, Cow& b) {
	return a.index < b.index;
}

int main() {
	//freopen("convention2.in", "r", stdin);
	//freopen("convention2.out", "w", stdout);
	ll N;
	cin >> N;
	vector<Cow> cows(N);
	for (int i = 0; i < N; i++) {
		cin >> cows[i].a >> cows[i].t;
		cows[i].index = i;
	}
	sort(cows.begin(), cows.end(), cmp);
	ll waitingTime[N], time = 0;
	vector<Cow> waiting;
	for (int i = 0; i < N; i++) {
		Cow c = cows[i];
		if (c.a >= time && waiting.empty()) {
			time = c.a + c.t;
			waitingTime[c.index] = 0;
		}
		else if (c.a < time)
			waiting.push_back(c);
		else if (c.a >= time && !waiting.empty()) {
			sort(waiting.begin(), waiting.end(), cmp2);
			Cow removed = waiting[0];
			waitingTime[removed.index] = time - removed.a;
			time += removed.t;
			waiting.erase(waiting.begin());
			i--;
		}
	}
	while (!waiting.empty()) {
		sort(waiting.begin(), waiting.end(), cmp2);
		Cow removed = waiting[0];
		waitingTime[removed.index] = time - removed.a;
		time += removed.t;
		waiting.erase(waiting.begin());
	}
	long long ans = -1;
	for (int i = 0; i < N; i++)
		ans = max(ans, waitingTime[i]);
	cout << ans << endl;
	return 0;
}
