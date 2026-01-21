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
const int mod = 1e9+7;

bool pos(vector<int>& a, int x, vector<int>& p, int k, int n, int& ans) {
    for (int i = 1; i <= n; i++) {
        if (i - x >= 0 && x * a[i] - (p[i] - p[i - x]) <= k) {
            ans = a[i];
            return true;
        }
    }
    return false;
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());

    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];

    int start = 1, end = n;
    int ans1 = 0, ans2 = -1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (pos(a, mid, p, k, n, ans2)) {
            ans1 = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << ans1 << " " << ans2 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
