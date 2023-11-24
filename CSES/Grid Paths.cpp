#include <iostream>
#include <string>
#include <set>
using namespace std;
string s;
bool visited[7][7];
long long ans = 0;

void create(int x, int y, long long counter) {
	if (x < 0 || x >= 7 || y < 0 || y >= 7 || visited[x][y])
		return;
	if (((x + 1 == 7 or (visited[x - 1][y] and visited[x + 1][y])) and y - 1 >= 0 and y + 1 < 7 and !visited[x][y - 1] and !visited[x][y + 1]) or
	    ((y + 1 == 7 or (visited[x][y - 1] and visited[x][y + 1])) and x - 1 >= 0 and x + 1 < 7 and !visited[x - 1][y] and !visited[x + 1][y]) or
	    ((x == 0 or (visited[x + 1][y] and visited[x - 1][y])) and y - 1 >= 0 and y + 1 < 7 and !visited[x][y - 1] and !visited[x][y + 1]) or
	    ((y == 0 or (visited[x][y + 1] and visited[x][y - 1])) and x - 1 >= 0 and x + 1 < 7 and !visited[x - 1][y] and !visited[x + 1][y]))
	    return;
	if (x == 6 && y == 0) {
		if (counter == 48)
			ans++;
		return;
	}
	visited[x][y] = true;
	if (s[counter] == '?') {
		create(x + 1, y, counter + 1);
		create(x - 1, y, counter + 1);
		create(x, y + 1, counter + 1);
		create(x, y - 1, counter + 1);
	}
	else if (s[counter] == 'U') {
		create(x - 1, y, counter + 1);
	}
	else if (s[counter] == 'D') {
		create(x + 1, y, counter + 1);
	}
	else if (s[counter] == 'L') {
		create(x, y - 1, counter + 1);
	}
	else if (s[counter] == 'R') {
		create(x, y + 1, counter + 1);
	}
	visited[x][y] = false;
}

int main() {
	cin >> s;
	create(0, 0, 0);
	cout << ans << endl;
	return 0;
}