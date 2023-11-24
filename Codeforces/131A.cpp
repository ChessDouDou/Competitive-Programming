#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	string check = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && i != 0)
			check += s[i] - 32;
		else
			check += s[i];
	}
	if (check == s) {
		string ans = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] <= 'Z')
				ans += s[i] + 32;
			else
				ans += s[i] - 32;
		}
		cout << ans << endl;
	}
	else
		cout << s << endl;
	return 0;
}
