#include <iostream>
#include <set>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, n;
    cin >> x >> n;
    set<int> lights;
    multiset<int> dist;
    lights.insert(0);
    lights.insert(x);
    dist.insert(x);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        auto l1 = lights.upper_bound(p), l2 = l1;
        l2--;
        dist.erase(dist.find(*l1 - *l2));
        dist.insert(p - *l2);
        dist.insert(*l1 - p);
        auto ans = dist.end();
        ans--;
        cout << *ans << " ";
        lights.insert(p);
    }
    return 0;
}