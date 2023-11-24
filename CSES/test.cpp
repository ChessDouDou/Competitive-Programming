#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool is_square(long long n) {
	return ceil((double)sqrt(n)) == floor((double)sqrt(n));
}

int main() {
	long long a, b;
	cin >> a >> b;
	pair<long long, long long> c[2];
	c[0].first = -1;
	c[1].first = -1;
	for (long long i = 1; i < a; i++) {
		if (is_square(a * a - i * i)) {
			c[0].first = i;
			c[0].second = sqrt(a * a - i * i);
			break;
		}
	}
	for (long long i = 1; i < b; i++) {
		if (is_square(b * b - i * i)) {
			c[1].first = i;
			c[1].second = sqrt(b * b - i * i);
			break;
		}
	}
	if (c[0].second == c[1].first) {
		swap(c[0].first, c[0].second);
		swap(c[1].first, c[1].second);
	}
	if (c[0].first == -1 || c[1].first == -1 || (c[0].first * c[1].second) != (c[1].first * c[0].second)) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	cout << "0 0" << endl;
	cout << -1 * c[0].first << " " << c[0].second << endl;
	cout << c[1].second << " " << c[1].first << endl;
	return 0;
}