#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long

void solve() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    int sum = 0, cnt = 0;
    while (i < j) {
        if (sum + a[i] >= a[j]) {
            int need = a[j] - sum;
            cnt += need + 1;
            a[i] -= need;
            sum = 0;
            j--;
        } else {
            sum += a[i];
            cnt += a[i];
            i++;
        }
    }
    if (i == j) {
        int x = a[i];
        while (x > 0) {
            int s = 0;
            if (x > sum) s = (x - sum) / 2;
            if (s > 0) {
                cnt += s;
                x -= s;
                sum += s;
            }
            if (sum > 0) {
                cnt++;
                x -= sum;
                sum = 0;
            }
            if (x > 0) {
                cnt++;
                x--;
            }
        }
    }
    cout << cnt <<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
