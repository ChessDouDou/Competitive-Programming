#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int N, Q, prefix[100001], suffix[100001];
string s;

int main() {
	cin >> N >> Q >> s;
	stack<char> colors;
	for (int i = 0; i < N; i++) {
		prefix[i + 1] = prefix[i];
		while (!colors.empty() && colors.top() > s[i])
			colors.pop();
		if (colors.empty() || colors.top() < s[i]) {
			colors.push(s[i]);
			prefix[i + 1]++;
		}
	}
	reverse(s.begin(), s.end());
	colors = stack<char>();
	for (int i = 0; i < N; i++) {
		suffix[i + 1] = suffix[i];
		while (!colors.empty() && colors.top() > s[i])
			colors.pop();
		if (colors.empty() || colors.top() < s[i]) {
			colors.push(s[i]);
			suffix[i + 1]++;
		}
	}
	while (Q--) {
		int a, b;
		cin >> a >> b;
		cout << prefix[a - 1] + suffix[N - b] << endl;
	}
	return 0;
}
