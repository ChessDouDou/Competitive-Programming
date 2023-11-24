#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <set>
using namespace std;
int n;
int x1, y1, x2, y2;
string grid[20];
bool visited[20][20];

struct pcl {
	int x1, y1, x2, y2;
};

void floodfill(int i, int j, char c) {
	if (i < x1 || i > x2 || j < y1 || j > y2 || visited[i][j] || grid[i][j] != c)
		return;
	visited[i][j] = true;
	floodfill(i + 1, j, c);
	floodfill(i - 1, j, c);
	floodfill(i, j + 1, c);
	floodfill(i, j - 1, c);
}

bool countComponents() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = false;
	set<char> s;
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			s.insert(grid[i][j]);
	if (s.size() != 2)
		return false;
	int counter[2] = {0, 0};
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			if (!visited[i][j]) {
				floodfill(i, j, grid[i][j]);
				if (grid[i][j] == *s.begin())
					counter[0]++;
				else
					counter[1]++;
			}
	if ((counter[0] == 1 && counter[1] >= 2) || (counter[1] == 1 && counter[0] >= 2))
		return true;
	return false;
}

bool contains(pcl a, pcl b) {
	return a.x1 >= b.x1 && a.y1 >= b.y1 && a.x2 <= b.x2 && a.y2 <= b.y2;
}

int main () {
	//freopen("where.in", "r", stdin);
	//freopen("where.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	vector<pcl> PCL;
	for (x1 = 0; x1 < n; x1++)
		for (y1 = 0; y1 < n; y1++)
			for (x2 = x1; x2 < n; x2++)
				for (y2 = y1; y2 < n; y2++)
					if (countComponents())
						PCL.push_back({x1, y1, x2, y2});
	bool isPCL[PCL.size()];
	for (int i = 0; i < PCL.size(); i++)
		isPCL[i] = true;
	for (int i = 0; i < PCL.size(); i++) {
		for (int j = 0; j < PCL.size(); j++) {
			if (i != j && contains(PCL[i], PCL[j])) {
				isPCL[i] = false;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < PCL.size(); i++)
		if (isPCL[i])
			ans++;
	cout << ans << endl;
	return 0;
}
