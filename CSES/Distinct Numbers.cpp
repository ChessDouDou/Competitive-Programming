#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	set<int> ans;
	while (n--) {
		int x;
		cin >> x;
		ans.insert(x);
	}
	cout << ans.size() << endl;
	return 0;
}