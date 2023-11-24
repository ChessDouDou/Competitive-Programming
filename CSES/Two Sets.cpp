#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long sum = n * (n + 1) / 2;
	if (sum % 2 == 1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	vector<long long> a;
	vector<long long> b;
	long long ans = 0;
	for (int i = n; i >= 1; i--) {
		if (ans < sum / 2 && ans + i <= sum / 2) {
			a.push_back(i);
			ans += i;
		}
		else
			b.push_back(i);
	}
	cout << a.size() << endl;
	for (int i : a)
		cout << i << " ";
	cout << endl;
	cout << b.size() << endl;
	for (int i : b)
		cout << i << " ";
	cout << endl;
	return 0;
}