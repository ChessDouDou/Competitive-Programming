#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int a[n];
	set<int> s;
	map<int, vector<int> > m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]].push_back(i);
		s.insert(a[i]);
	}
	// for (int i = 0; i < n; i++)
	// 	sort(m[a[i]].begin(), m[a[i]].end());
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int c = x - a[i] - a[j];
			if (s.find(c) != s.end()) {
				for (int k = 0; k < m[c].size() && k < 3; k++) {
					if (m[c][k] != i && m[c][k] != j) {
						cout << i + 1 << " " << j + 1 << " " << m[c][k] + 1 << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}