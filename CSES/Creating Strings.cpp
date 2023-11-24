#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
set<string> S;
int ans = 0;

void generate(string x, string s) {
	if (s.length() == 0) {
		ans += S.find(x) == S.end();
		S.insert(x);
		return;
	}
	for (int i = 0; i < s.length(); i++)
		generate(x + s[i], s.substr(0, i) + s.substr(i + 1, s.length() - i - 1));
}

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	generate("", s);
	cout << ans << endl;
	for (string i : S)
		cout << i << endl;
	return 0;
}