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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int last = a[n - 1];
    int i = n - 1;

    while (i >= 0 && a[i] == last) i--;

    if (i < 0) {
        cout << 0 << '\n';
        return;
    }

    int cnt = 0;

    while (i >= 0) {
        int suffixSize = n - 1 - i;
        i -= suffixSize;
        cnt++;
        while (i >= 0 && a[i] == last) i--;
    }

    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
