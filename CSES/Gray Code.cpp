#include <iostream>
#include <cmath>
using namespace std;

void print_string(int num, int n) {
	if (n == 0)
		return;
	cout << num % 2;
	print_string(num / 2, n - 1);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < pow(2, n); i++) {
		int num = (i ^ (i >> 1));
		print_string(num, n);
		cout << endl;
	}
	return 0;
}