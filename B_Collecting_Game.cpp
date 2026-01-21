#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<long long,int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({a[i], i});

    sort(v.begin(), v.end());

    vector<long long> pref(n);
    pref[0] = v[0].first;
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + v[i].first;

    vector<int> reach(n);
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (i > r) r = i;
        while (r + 1 < n && pref[r] >= v[r + 1].first)
            r++;
        reach[i] = r;
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[v[i].second] = reach[i];

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
