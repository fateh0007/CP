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
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n);
    int asum = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int maxi  =0;
    int sum = 0;
    int ans = 0;
    for(int i=0;i<min(n,k);i++){
        sum+=a[i];
        maxi = max(maxi,b[i]);
        ans = max(ans, sum + maxi*(k - (i+1)));
    }
    cout<<ans<<endl;
    
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
