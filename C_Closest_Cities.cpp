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

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> to(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i == 1) to[i] = 2;
        else if (i == n) to[i] = n - 1;
        else {
            int left = abs(a[i] - a[i-1]);
            int right = abs(a[i] - a[i+1]);
            to[i] = (left <= right) ? i - 1 : i + 1;
        }
    }
    vector<int> prefL(n + 1, 0), prefR(n + 1, 0);
    for (int i = 2; i <= n; i++)
        prefL[i] = prefL[i-1] + (to[i] == i-1 ? 1 : abs(a[i] - a[i-1]));
    for (int i = n - 1; i >= 1; i--)
        prefR[i] = prefR[i+1] + (to[i] == i+1 ? 1 : abs(a[i+1] - a[i]));

    int m; cin >> m;
    while (m--) {
        int x, y; cin >> x >> y;
        if (x < y) cout << prefR[x] - prefR[y] << "\n";
        else cout << prefL[x] - prefL[y] << "\n";
    }

}
  
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}