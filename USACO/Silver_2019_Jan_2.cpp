#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
string grid[1000];
bool visited[1000][1000];
vector<int> areas, perimeters;
int area, perimeter, counter = 0;

void findArea(int i, int j, char c) {
	if (i < 0 || i >= N || j < 0 || j >= N || grid[i][j] != '#')
		return;
	grid[i][j] = c;
	area++;
	findArea(i + 1, j, c);
	findArea(i - 1, j, c);
	findArea(i, j + 1, c);
	findArea(i, j - 1, c);
}

void findPerimeter(int i, int j, char c) {
	if (i < 0 || i >= N || j < 0 || j >= N || visited[i][j] || grid[i][j] != c)
		return;
	visited[i][j] = true;
	if (i + 1 < 0 || i + 1 >= N || grid[i + 1][j] == '.')
		perimeter++;
	if (i - 1 < 0 || i - 1 >= N || grid[i - 1][j] == '.')
		perimeter++;
	if (j + 1 < 0 || j + 1 >= N || grid[i][j + 1] == '.')
		perimeter++;
	if (j - 1 < 0 || j - 1 >= N || grid[i][j - 1] == '.')
		perimeter++;
	findPerimeter(i + 1, j, c);
	findPerimeter(i - 1, j, c);
	findPerimeter(i, j + 1, c);
	findPerimeter(i, j - 1, c);
}

int main() {
	//freopen("perimeter.in", "r", stdin);
	//freopen("perimeter.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> grid[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == '#') {
				char c = counter + '0';
				counter++;
				area = 0;
				findArea(i, j, c);
				areas.push_back(area);
				perimeter = 0;
				findPerimeter(i, j, c);
				perimeters.push_back(perimeter);
			}
		}
	}
	int maxArea = -1, minPerimeter;
	for (int i = 0; i < counter; i++) {
		if (areas[i] > maxArea) {
			maxArea = areas[i];
			minPerimeter = perimeters[i];
		}
		if (areas[i] == maxArea)
			minPerimeter = min(minPerimeter, perimeters[i]);
	}
	cout << maxArea << " " << minPerimeter << endl;
	return 0;
}
