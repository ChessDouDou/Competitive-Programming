#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int nums[N];
		for (int i = 0; i < N; i++)
			cin >> nums[i];
		set<int> expanded;
		for (int x : nums) {
			expanded.insert(x);
			for (int y : nums)
				if (x < y)
					expanded.insert(y - x);
		}
		int ans = 0;
		for (int a : expanded) {
			for (int b : expanded) {
				for (int c : expanded) {
					if (a <= b && b <= c) {
						set<int> allNumbers = {a, b, c, a + b, b + c, c + a, a + b + c};
						bool works = true;
						for (int x : nums)
							if (allNumbers.find(x) == allNumbers.end())
								works = false;
						if (works)
							ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
