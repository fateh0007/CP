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
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    
    if(k>=n){
        cout<<0<<endl;
        return;
    }
    sort(a.begin(),a.end());
    vector<int> pre(n);
    pre[0] = a[0];
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1] + a[i];
    }

    int ans = 0;
    for(int i=0;i<=k;i++){
        int j = k-i;
        int left = 2*i;
        int right = n-j-1;
        int sum = pre[right] - (left == 0 ? 0 : pre[left-1]);
        ans = max(ans,sum);
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
