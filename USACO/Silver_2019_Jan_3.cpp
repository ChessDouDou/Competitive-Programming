#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<pair<int ,int> > mountain;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

bool contains(int i, int j) {
	return mountain[i].first > mountain[j].first && mountain[i].second < mountain[j].second;
}

int main() {
	//freopen("mountains.in", "r", stdin);
	//freopen("mountains.out", "w", stdout);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		mountain.push_back({x - y, x + y});
	}
	sort(mountain.begin(), mountain.end(), cmp);
	int ans = 0, maxEnd = -1;
	for (int i = 0; i < N; i++) {
		if (mountain[i].second > maxEnd) {
			ans++;
			maxEnd = mountain[i].second;
		}
	}
	cout << ans << endl;
	return 0;
}
