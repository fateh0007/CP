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
    int l,r;
    cin>>l>>r;
    int peak = l;
    int k = 1;
    while(peak*2<=r){
        k++;
        peak = peak*2;
    }
    peak/=l;

    int ans = r/peak-l+1;
    peak/=2;
    peak*=3;

    ans += max(0LL,(r/peak-l+1)*(k-1));
    cout<<k<<" "<<ans<<endl;;
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
