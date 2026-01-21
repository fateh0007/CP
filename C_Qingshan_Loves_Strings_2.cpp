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

bool ok(string s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) return false;
    }
    return true;
}

string s;

void solve() {
    int n; 
    cin >> n;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') cnt0++;
        else cnt1++;
    }

    if (cnt0 != cnt1) {
        cout << -1 << endl;
        return;
    }

    vector<int> z;
    deque<char> q;

    for (int i = 0; i < s.size(); i++) q.push_back(s[i]);

    int d = 0;
    while (!q.empty()) {
        if (q.front() == q.back()) {
            if (q.front() == '0') {
                q.push_back('0');
                q.push_back('1');
                z.push_back(n - d);
            } else {
                q.push_front('1');
                q.push_front('0');
                z.push_back(0 + d);
            }
            n += 2;
        }

        while (!q.empty() && q.front() != q.back()) {
            q.pop_back();
            q.pop_front();
            d++;
        }
    }

    cout << z.size() << endl;
    for (int i = 0; i < z.size(); i++) {
        cout << z[i];
        if (i + 1 == z.size()) cout << endl;
        else cout << " ";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
