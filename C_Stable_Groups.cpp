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
#include<numeric>
using namespace std;
#define int long long 
const int mod = 1e9 + 7;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vector<int> gaps;

    for (int i = 0; i < n - 1; i++) {
        int d = a[i + 1] - a[i];
        if (d > x) {
            gaps.push_back((d - 1) / x);
        }
    }

    sort(gaps.begin(), gaps.end());

    int groups = gaps.size() + 1;

    for (int need : gaps) {
        if (k >= need) {
            k -= need;
            groups--;
        } else {
            break;
        }
    }

    cout << groups << '\n';
}



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;
    while (t--) solve();
}
