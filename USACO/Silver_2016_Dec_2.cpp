#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int citystate[1000][1000];

int main() {
	//freopen("citystate.in","r",stdin);
	//freopen("citystate.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string city, state;
		cin >> city >> state;
		citystate[26 * (city[0] - 'A') + city[1] - 'A'][26 * (state[0] - 'A') + state[1] - 'A']++;
	}
	int ans = 0;
	for (int i = 0; i < 1000; i++)
		for (int j = i + 1; j < 1000; j++)
			if (citystate[i][j] != 0)
				ans += citystate[i][j] * citystate[j][i];
	cout << ans << endl;
	return 0;
}
