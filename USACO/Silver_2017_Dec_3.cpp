#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main(){
	//freopen("shuffle.in", "r", stdin);
	//freopen("shuffle.out", "w", stdout);
	ll n;
	cin >> n;
	vector<ll> cnt(n), a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		cnt[a[i]]++;
	}
	ll ans = n;
	queue<ll> q;
	for (ll i = 0; i < n; i++) {
		if (cnt[i] == 0){
			q.push(i);
			ans--;
		}
	}
	while(!q.empty()){
		ll cur = q.front();
		q.pop();
		if(--cnt[a[cur]] == 0){
			q.push(a[cur]);
			ans--;
		}
	}
	cout << ans << endl;
	return 0;
}
