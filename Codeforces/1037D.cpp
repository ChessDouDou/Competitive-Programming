#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<int> edges[200005];
bool visited[200005];
int seq[200005], seqIndex[200005];

bool cmp(const int& a, const int& b) {
	return seqIndex[a] < seqIndex[b];
}

bool check() {
	int index = 0;
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (v != seq[index])
			return false;
		for (auto i : edges[v]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
		index++;
	}
	return true;
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
		seq[i]--;
		seqIndex[seq[i]] = i;
	}
	for (int i = 0; i < n; i++)
		sort(edges[i].begin(), edges[i].end(), cmp);
	if (check())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
