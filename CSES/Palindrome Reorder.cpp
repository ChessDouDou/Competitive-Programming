#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int c[26];
	for (int i = 0; i < 26; i++)
		c[i] = 0;
	for (int i = 0; i < s.length(); i++)
		c[s[i] - 'A']++;
	string ans = "";
	int odd = 0;
	for (int i = 0; i < 26; i++)
		if (c[i] % 2 == 1)
			odd++;
	if (odd > 1) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < c[i] / 2; j++)
			cout << (char)(i + 'A');
	for (int i = 0; i < 26; i++)
		if (c[i] % 2 == 1)
			cout << (char)(i + 'A');
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < c[25 - i] / 2; j++)
			cout << (char)(25 - i + 'A');
	cout << endl;
	return 0;
}