#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp (const pair<int, int>& a, const pair<int, int>& b) {
	return a.first > b.first;
}

int main() {
	//freopen("rental.in", "r", stdin);
	//freopen("rental.out", "w", stdout);
	int n, m, r;
	cin >> n >> m >> r;
	vector<int> production(n);
	for (int i = 0; i < n; i++)
		cin >> production[i];
	vector<pair<int, int> > shops(m);
	for (int i = 0; i < m; i++)
		cin >> shops[i].second >> shops[i].first;
	vector<int> rent(r);
	for (int i = 0; i < r; i++)
		cin >> rent[i];
	sort(rent.begin(), rent.end(), greater<int>());
	sort(shops.begin(), shops.end(), cmp);
	sort(production.begin(), production.end(), greater<int>());
	int iShop = 0, iRent = 0, i = 0;
	long long ans = 0;
	while (i < n) {
		int litres = production[i], moneyT = 0, curI = iShop, last = 0;
		while (curI < m) {
			int rest = min(litres, shops[curI].second);
			moneyT += shops[curI].first * rest;
			litres -= rest;
			if (litres == 0) {
				last = rest;
				break;
			} 
			else
				curI++;
		}
		if (iRent >= r || moneyT > rent[iRent]) {
			ans += moneyT;
			iShop = curI;
			if (iShop < m)
				shops[iShop].second -= last;
			i++;
		}
		else {
			ans += rent[iRent];
			n--;
			iRent++;
		}
	}
	cout << ans << endl;
	return 0;
}
