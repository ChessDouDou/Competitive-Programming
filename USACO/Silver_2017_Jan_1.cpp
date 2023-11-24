#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, Tmax;
vector<int> d;

bool check(int K) {
	priority_queue<int, vector<int>, greater<int> > cows;
	for (int i = 0; i < K; i++)
		cows.push(d[i]);
	for (int i = K; i < N; i++) {
		int top = cows.top();
		cows.pop();
		cows.push(d[i] + top);
	}
	while (cows.size() > 1)
		cows.pop();
	return cows.top() <= Tmax;
}

int main() {
	//freopen("cowdance.in","r",stdin);
	//freopen("cowdance.out","w",stdout);
	cin >> N >> Tmax;
	d.resize(N);
	for (int i = 0; i < N; i++)
		cin >> d[i];
	int l = 1, r = N;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << l << endl;
	return 0;
}
