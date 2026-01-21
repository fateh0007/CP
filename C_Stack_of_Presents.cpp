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
#include<stack>
// #include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;                       // x - 1
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            b[i]--;                       // x - 1
        }

        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[a[i]] = i;                // pos[a[i]] = i
        }

        long long lst = -1;
        long long res = m;                // initial m (same as Python)

        for (int i = 0; i < m; i++) {
            if (pos[b[i]] > lst) {
                res += 2LL * (pos[b[i]] - i);
                lst = pos[b[i]];
            }
        }

        cout << res << "\n";
    }

    return 0;
}

