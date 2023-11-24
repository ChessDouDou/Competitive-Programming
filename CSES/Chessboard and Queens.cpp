#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> board;
bool col[8], ld[15], rd[15];
int ans = 0;

void solve(int r) {
	if (r >= 8) {
		ans++;
		return;
	}
	for (int c = 0; c < 8; c++) {
		if (board[r][c] == '.' && !col[c] && !ld[7 - r + c] && !rd[r + c]) {
			col[c] = true;
			ld[7 - r + c] = true;
			rd[r + c] = true;
			solve(r + 1);
			col[c] = false;
			ld[7 - r + c] = false;
			rd[r + c] = false;
		}
	}
}

int main() {
	for (int i = 0; i < 8; i++) {
		string s;
		cin >> s;
		board.push_back(s);
	}
	solve(0);
	cout << ans << endl;
	return 0;
}