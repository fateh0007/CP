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
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> pre(n);
    vector<int> suf(n);
    pre[0] = a[0];
    for(int i=1;i<n;i++){
        pre[i] = a[i] + pre[i-1];
    }
    suf[n-1] = a[n-1];
    map<int,int> mp;
    mp[suf[n-1]] = n-1; 
    for(int i=n-2;i>=0;i--){
        suf[i] = a[i] + suf[i+1];
        mp[suf[i]] = i;
    }
    int ans =0 ;
    for(int i=0;i<n;i++){
        if(mp[pre[i]]>i && mp.find(pre[i])!=mp.end() ){
            ans = max(ans,i+1 + (n - mp[pre[i]]));
        }
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
