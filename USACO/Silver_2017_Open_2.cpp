#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int toInt(char c) {
	if (c == 'A')
		return 0;
	else if (c == 'C')
		return 1;
	else if (c == 'G')
		return 2;
	else
		return 3;
}

int encode(char a, char b, char c) {
	return toInt(a) * 16 + toInt(b) * 4 + toInt(c);
}

int main () {
	//freopen("cownomics.in", "r", stdin);
	//freopen("cownomics.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string spotty[n], plain[n];
	for (int i = 0; i < n; i++)
		cin >> spotty[i];
	for (int i = 0; i < n; i++)
		cin >> plain[i];
	int ans = 0;
	for (int a = 0; a < m; a++) {
		for (int b = a + 1; b < m; b++) {
			for (int c = b + 1; c < m; c++) {
				bool s[64], p[64];
				for (int i = 0; i < 64; i++)
					s[i] = p[i] = false;
				for (int i = 0; i < n; i++)
					s[encode(spotty[i][a], spotty[i][b], spotty[i][c])] = true;
				for (int i = 0; i < n; i++)
					p[encode(plain[i][a], plain[i][b], plain[i][c])] = true;
				bool flag = true;
				for (int i = 0; i < 64; i++)
					if (s[i] && p[i])
						flag = false;
				if (flag)
					ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
