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
#define int  long long 
const int mod = 1e9 + 7;

int helper2(vector<int> &a,vector<int> &b,int n){
    int cnt = 1;
    int maxi = 1;
    map<int,int> mp;
    mp[a[0]] = 1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            cnt++;
            maxi = max(maxi,cnt);
        }else{
            cnt = 1;
        }
        mp[a[i]] = max(mp[a[i]],cnt);
    }

    cnt=1;
    int maxi2 = 1;
    map<int,int> mp2;
    mp2[b[0]] = 1;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            cnt++;
            maxi2 = max(maxi2,cnt);
        }else{
            cnt = 1;
        }
        mp2[b[i]] = max(mp2[b[i]],cnt);
    }
    int ans= 1;
    for(auto it: mp){
        ans = max(ans,it.second);
    }
    for(auto it: mp2){
        ans = max(ans,it.second);
    }
    for(auto it: mp){
        int val = it.first;
        int count1 = it.second;
        int count2 = mp2[val];
        ans = max(ans, count1 + count2);
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int ans = helper2(a,b,n);
    cout<<ans<<endl;
    // int maxi1 = helper(a,b,n);
    // int maxi2 = helper(b,a,n);
    // cout<<max(maxi1,maxi2)<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
