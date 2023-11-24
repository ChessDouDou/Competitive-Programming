#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	//freopen("haybales.in","r",stdin);
	//freopen("haybales.out","w",stdout);
	int n, q;
	cin >> n >> q;
	vector<int> haybales(n);
	for (int i = 0; i < n; i++)
		cin >> haybales[i];
	sort(haybales.begin(), haybales.end());
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << upper_bound(haybales.begin(), haybales.end(), b) - upper_bound(haybales.begin(), haybales.end(), a - 1) << endl;
	}
	return 0;
}
