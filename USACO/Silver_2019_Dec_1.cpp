#include <iostream>
using namespace std;

int main() {
	//freopen("moobuzz.in", "r", stdin);
	//freopen("moobuzz.out", "w", stdout);
	int N;
	cin >> N;
	int nums[8] = {1, 2, 4, 7, 8, 11, 13, 14};
	cout << ((N - 1) / 8 * 15) + nums[(N - 1) % 8] << endl;
	return 0;
}
