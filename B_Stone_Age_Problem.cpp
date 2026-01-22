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
#define int long long int
const int mod = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> prev(n, -1);

    int curr_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        curr_sum += a[i];
    }

    int val = -1;
    int timer = 0;
    int last_set = -1; 
    while (q--) {
        timer++;
        int t;
        cin >> t;

        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;

            int pre;
            if (prev[i] < last_set) {
                pre = (val == -1 ? a[i] : val);
            } else {
                pre = a[i];
            }

            curr_sum -= pre;
            curr_sum += x;

            a[i] = x;
            prev[i] = timer;
        }
        else {
            int x;
            cin >> x;
            val = x;
            curr_sum = x * n;
            last_set = timer;
        }

        cout << curr_sum << "\n";
    }
}



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;
    while (t--) solve();
}
