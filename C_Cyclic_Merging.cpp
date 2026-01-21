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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    a.push_back(a[0]);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int maxi = max(a[i],a[i+1]);
        mp[maxi]++;
    }
    int ans = 0;
    for(auto it:mp){
        int val = it.first;
        int cnt = it.second;
        // cout<<val<<" "<<cnt<<endl;
        int x = val*cnt;
        ans += x;
    }
    ans-=mp.rbegin()->first;
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
