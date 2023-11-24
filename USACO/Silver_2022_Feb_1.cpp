#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int prefer[N][N], pos[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> prefer[i][j];
			prefer[i][j]--;
			pos[i][prefer[i][j]] = j;
		}
	}
	int order[N];
	for (int i = 0; i < N; i++)
		order[i] = i;
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (pos[i][order[j]] < pos[i][order[i]] && pos[j][order[i]] < pos[j][order[j]]) {
					flag = true;
					swap(order[i], order[j]);
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << order[i] + 1 << endl;
	return 0;
}
