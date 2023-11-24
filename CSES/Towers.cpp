#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	vector<int> t;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		int lo = 0, hi = t.size();
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (t[mid] > k)
				hi = mid;
			else
				lo = mid + 1;
		}
		if (lo == t.size())
			t.push_back(k);
		else
			t[lo] = k;
	}
	cout << t.size() << endl;
	return 0;
}