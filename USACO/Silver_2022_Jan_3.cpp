#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge {
	int cow;
	int to;
	bool is_first;
	edge() {};
	edge(int cow, int to, bool is_first) : cow(cow), to(to), is_first(is_first) {};
};

int N, M;
vector<edge> adj[100001];
bool visited_cycle[100001];
bool visited[100001];
bool gets_cereal[100001]; 
int hungry_cows = 0;
queue<int> order;
int ignore_edge = -1;
int first_cereal = -1;

void find_cycle(int cur, int prev = -1) {
	visited_cycle[cur] = true; 
	for (edge next : adj[cur]) {
		if (visited_cycle[next.to]) {
			if (first_cereal == -1 && next.to != prev) {
				if (next.is_first)
					first_cereal = next.to; 
				else
					first_cereal = cur;
				ignore_edge = next.cow; 
				order.push(next.cow);
				gets_cereal[next.cow] = true;
			}
		}
		else
			find_cycle(next.to, cur);
	}
}


void dfs(int cur) {
	visited[cur] = true;
	for (edge next : adj[cur]) {
		if (!visited[next.to] && next.cow != ignore_edge) { 
			gets_cereal[next.cow] = true;
			order.push(next.cow);
			dfs(next.to);
		}
	}
}


int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(edge(i, b, false));
		adj[b].push_back(edge(i, a, true));
	}
	for (int i = 1; i <= M; i++) {
		first_cereal = -1;
		ignore_edge = -1;
		if (!visited[i]) {
			find_cycle(i);
			if (first_cereal > 0)
				dfs(first_cereal);
			else
				dfs(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (!gets_cereal[i]) {
			hungry_cows++;
			order.push(i);
		} 
	}
	cout << hungry_cows << endl;
	while (!order.empty()) {
		cout << order.front() << endl; 
		order.pop();
	}
	return 0;
}
