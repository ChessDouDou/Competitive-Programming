#include <iostream>
#include <algorithm>
using namespace std;
int occ[100001], ans[100001];

int main() {
	//freopen("cereal.in","r",stdin);
	//freopen("cereal.out","w",stdout);
	int N, M;
	cin >> N >> M;
	int f[N], s[N];
	for (int i = 0; i < N; i++)
		cin >> f[i] >> s[i];
	int counter = 0;
	for (int i = N - 1; i >= 0; i--) {
		int j = i, pos = f[i];
		while (true) {
			if (occ[pos] == 0) {
				occ[pos] = j;
				counter++;
				break;
			}
			else if (occ[pos] < j)
				break;
			else {
				int k = occ[pos];
				occ[pos] = j;
				if (pos == s[k])
					break;
				j = k;
				pos = s[k];
			}
		}
		ans[i] = counter;
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] << endl;
	return 0;
}
