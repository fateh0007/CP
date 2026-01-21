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
// #define int long long
const int mod = 1e9 + 7;

bool checkPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int n1, m1;
    cin >> n1 >> m1;

    int n = max(n1, m1);
    int m = min(n1, m1);

    vector<vector<int> > ans(n, vector<int>(m, 0));

    if (!checkPrime(n)) {
        int cnt = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][i] = cnt;
                cnt++;
            }
        }
    } else if (!checkPrime(m)) {
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = cnt;
                cnt++;
            }
        }
    } else {
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            ans[i][0] = cnt;
            cnt++;
        }
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                ans[i][j] = ans[i][j - 1] + n + 1;
            }
        }
        for (int j = 1; j < m; j++) {
            int val = j * n + 1;
            int st = n - j;
            for (int i = st; i < n; i++) {
                ans[i][j] = val;
                val++;
            }
        }
    }

    // ✅ Always print the output
    if (n != n1) {
        // transpose when dimensions differ
        vector<vector<int> > res(n1, vector<int>(m1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[j][i] = ans[i][j];
            }
        }

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m1; j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        // directly print
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m1; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
