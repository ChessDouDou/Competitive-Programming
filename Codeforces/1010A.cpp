#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int n, m, itr = 0;
double payload;
vector<pair<int, int> > planets;

bool check(double fuel) {
	//launch Earth
	double used = payload / planets[0].first;
	fuel -= used;
	payload -= used;
	for (int i = 1; i < planets.size(); i++) {
		used = payload / planets[i].second;
		fuel -= used;
		payload -= used;
		used = payload / planets[i].first;
		fuel -= used;
		payload -= used;
		if (fuel < 0)
			return false;
	}
	//land Earth
	used = payload / planets[0].second;
	fuel -= used;
	payload -= used;
	return fuel >= 0;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		planets.push_back({a, b});
	}
	double lo = 1, hi = 1e9 + 1;
	while (itr < 300) {
		double mid = (lo + hi) / 2.0;
		payload = m + mid;
		if (check(mid))
			hi = mid;
		else
			lo = mid;
		itr++;
	}
	if (hi == 1e9 + 1)
		cout << -1 << endl;
	else
		cout << setprecision(7) << lo << endl;
	return 0;
}
