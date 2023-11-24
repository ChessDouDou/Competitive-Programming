#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int n, s;
vector<int> x, v, d;

bool bomb(double pos, int i, double t, int dist) {
	double reach = pos / (double)(s - v[i]);
	if (reach > t)
		return false;
	if (reach * v[i] >= dist)
		return true;
	double total = reach + (dist - reach * v[i]) / (s + v[i]);
	return total <= t;
}

bool check(double t) {
	vector<pair<int, int> > left, right;
	for (int i = 0; i < n; i++) {
		int dist = (d[i] == 0 ? x[i] : (int)1e6 - x[i]);
		if (t * v[i] >= dist) {
			if (d[i] == 0)
				left.push_back({0, (int)1e6});
			else
				right.push_back({0, (int)1e6});
			continue;
		}
		if (t * (v[i] + s) < dist)
			continue;
		int lo = 0, hi = (int)1e6;
		while (lo < hi - 1) {
			int mid = (lo + hi) / 2;
			if (bomb(mid, i, t, dist))
				lo = mid;
			else
				hi = mid;
		}
		if (d[i] == 0)
			left.push_back({x[i], min((int)1e6, x[i] + lo)});
		else
			right.push_back({max(0, x[i] - lo), x[i]});
	}
	int prefix[2][1000002] = {};
	for (auto l : left) {
		prefix[0][l.first]++;
		prefix[0][l.second + 1]--;
	}
	for (auto r : right) {
		prefix[1][r.first]++;
		prefix[1][r.second + 1]--;
	}
	for (int i = 0; i < 2; i++)
		for (int j = 1; j < 1000002; j++)
			prefix[i][j] += prefix[i][j - 1];
	for (int j = 0; j < 1000002; j++)
		if (prefix[0][j] && prefix[1][j])
			return true;
	return false;
}

int main() {
	cin >> n >> s;
	x.resize(n);
	v.resize(n);
	d.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> v[i] >> d[i];
		d[i]--;
	}
	int itr = 50;
	double lo = 0, hi = 1e6;
	while (itr--) {
		double mid = (lo + hi) / 2.0;
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << setprecision(10) << lo << endl;
	return 0;
}
