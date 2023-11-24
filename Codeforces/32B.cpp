#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	string ans = "", curr = "";
	for (int i = 0; i < s.length(); i++) {
		curr += s[i];
		if (curr == ".") {
			ans += '0';
			curr = "";
		}
		if (curr == "-.") {
			ans += '1';
			curr = "";
		}
		if (curr == "--") {
			ans += '2';
			curr = "";
		}
	}
	cout << ans << endl;
	return 0;
}
