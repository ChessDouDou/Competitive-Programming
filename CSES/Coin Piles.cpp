#include <iostream>
using namespace std;

int main() {
	long long t;
	cin >> t;
	while (t--) {
		long long a, b;
		cin >> a >> b;
		if ((a + b) % 3 != 0)
			cout << "NO" << endl;
		else if (a > b * 2 || b > a * 2)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}