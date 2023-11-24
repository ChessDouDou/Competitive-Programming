#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, K;
string grid[100];
bool visited[100][10];
bool done = false;
int currSize = 0;

void pop(int i, int j, char c) {
	if (i < 0 || i >= N || j < 0 || j >= 10 || grid[i][j] != c)
		return;
	grid[i][j] = '0';
	pop(i + 1, j, c);
	pop(i - 1, j, c);
	pop(i, j + 1, c);
	pop(i, j - 1, c);
}

void findSize(int i, int j, char c) {
	if (i < 0 || i >= N || j < 0 || j >= 10 || visited[i][j] || grid[i][j] != c)
		return;
	visited[i][j] = true;
	currSize++;
	findSize(i + 1, j, c);
	findSize(i - 1, j, c);
	findSize(i, j + 1, c);
	findSize(i, j - 1, c);
}

void click() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 10; j++)
			visited[i][j] = false;
	bool flag = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			if (grid[i][j] == '0')
				continue;
			currSize = 0;
			if (!visited[i][j])
				findSize(i, j, grid[i][j]);
			if (currSize >= K) {
				pop(i, j, grid[i][j]);
				flag = false;
			}
		}
	}
	done = flag;
}

void gravity() {
	for (int j = 0; j < 10; j++) {
		vector<char> c;
		for (int i = N - 1; i >= 0; i--)
			if (grid[i][j] != '0')
				c.push_back(grid[i][j]);
		for (int i = 0; i < N; i++)
			grid[i][j] = '0';
		for (int i = 0; i < c.size(); i++)
			grid[N - i - 1][j] = c[i];
	}
	return;
}

int main() {
	//freopen("mooyomooyo.in", "r", stdin);
	//freopen("mooyomooyo.out", "w", stdout);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> grid[i];
	while (!done) {
		click();
		gravity();
	}
	for (int i = 0; i < N; i++)
		cout << grid[i] << endl;
	return 0;
}
