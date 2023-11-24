#include <iostream>
using namespace std;

int main() {
	long long n, q;
	cin >> n >> q;
	long long x[n];
	for (int i = 0; i < n; i++)
		cin >> x[i];
	long long prefix[n + 1];
	prefix[0] = 0;
	for (int i = 0; i < n; i++)
		prefix[i + 1] = prefix[i] + x[i];
	while (q--) {
		long long a, b;
		cin >> a >> b;
		cout << prefix[b] - prefix[a - 1] << endl;
	}
	return 0;
}