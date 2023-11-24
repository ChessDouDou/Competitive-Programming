#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool nums[n];
	for (int i = 0; i < n; i++)
		nums[i] = false;
	for (int i = 0; i < n - 1; i++) {
		int x;
		cin >> x;
		nums[x - 1] = true;
	}
	for (int i = 0; i < n; i++)
		if (!nums[i])
			cout << i + 1 << endl;
	return 0;
}