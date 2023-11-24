#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Cow {
	int x;
	int y;
	int id;
};

bool cmp1(const Cow& a, const Cow& b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

bool cmp2(const Cow& a, const Cow& b) {
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

int main() {
	int N;
	cin >> N;
	vector<Cow> east, north;
	for (int i = 0; i < N; i++) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		if (c == 'E')
			east.push_back({x, y, i});
		else
			north.push_back({x, y, i});
	}
	sort(north.begin(), north.end(), cmp1);
	sort(east.begin(), east.end(), cmp2);
	bool stopped[N];
	int blame[N];
	for (int i = 0; i < N; i++) {
		stopped[i] = false;
		blame[i] = 0;
	}
	for (Cow eCow : east) {
		for (Cow nCow : north) {
			if (!stopped[eCow.id] && !stopped[nCow.id] && eCow.x < nCow.x && eCow.y > nCow.y) {
				int eT = nCow.x - eCow.x;
				int nT = eCow.y - nCow.y;
				if (eT < nT) {
					stopped[nCow.id] = true;
					blame[eCow.id] += 1 + blame[nCow.id];
				}
				if (eT > nT) {
					stopped[eCow.id] = true;
					blame[nCow.id] += 1 + blame[eCow.id];
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << blame[i] << endl;
	return 0;
}
