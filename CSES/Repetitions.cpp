#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int ans = -1, curr = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[i - 1])
			curr++;
		else {
			ans = max(ans, curr);
			curr = 1;
		}
	}
	cout << max(ans, curr) << endl;
	return 0;
}