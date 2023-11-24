#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll n;
vector<ll> xSum, ySum;
vector<pair<ll, ll> > xPoints[20020], yPoints[20020];

void findSum(vector<pair<ll, ll> > points, vector<ll> &sum) {
    if (points.empty())
        return;
    sort(points.begin(), points.end());
    ll lastSum = 0;
    for (auto k = points.begin(); k < points.end(); k++)
        lastSum += (*k).first - (*points.begin()).first;
    sum[(*points.begin()).second] = lastSum;
    int counter = 1;
    for (auto j = points.begin() + 1; j < points.end(); j++) {
        lastSum += ((*j).first - (*(j - 1)).first) * (2 * counter - points.size());
        counter++;
        sum[(*j).second] = lastSum;
    }
}

int main() {
	//freopen("triangles.in", "r", stdin);
	//freopen("triangles.out", "w", stdout);
    cin >> n;
    xSum.resize(n);
    ySum.resize(n);
	for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        a += 1e4;
        b += 1e4;
        xPoints[a].push_back({b, i});
        yPoints[b].push_back({a, i});
    }
    for (int i = 0; i < 20020; i++) {
        findSum(xPoints[i], xSum);
        findSum(yPoints[i], ySum);
    }
    ll area = 0;
    for (int i = 0; i < n; i++) {
        area += xSum[i] * ySum[i];
        area %= MOD;
    }
    cout << area % MOD << endl;
    return 0;
}
