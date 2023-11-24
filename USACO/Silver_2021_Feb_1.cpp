#include <iostream>
#include <queue>
using namespace std;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool present[3000][3000];
queue<pair<int, int> > cows;

void update(int x, int y) {
	if (!present[x][y])
		return;
	int count = 0;
	for (int i = 0; i < 4; i++)
		if (present[x + dx[i]][y + dy[i]])
			count++;
	if (count == 3)
		for (int i = 0; i < 4; i++)
			if (!present[x + dx[i]][y + dy[i]])
				cows.push({x + dx[i], y + dy[i]});
}

int main() {
	int N;
	cin >> N;
	int total = 0;
	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		x += 1000;
		y += 1000;
		cows.push({x, y});
		while (!cows.empty()) {
			pair<int, int> cow = cows.front();
			cows.pop();
			if (present[cow.first][cow.second])
				continue;
			total++;
			present[cow.first][cow.second] = true;
			update(cow.first, cow.second);
			for (int i = 0; i < 4; i++)
				update(cow.first + dx[i], cow.second + dy[i]);
		}
		cout << total - i << endl;
	}
	return 0;
}
