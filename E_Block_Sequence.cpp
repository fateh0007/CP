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
#include <numeric>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int helper(vector<int> &a,int n,int i,vector<int> &dp){
    int cnt = 0;
    if(i>=n){
        return dp[i] = cnt;
    }
    if(dp[i]!=-1) return dp[i];
    if(i+a[i]<n){
        cnt = min(1+helper(a,n,i+1,dp),helper(a,n,i+a[i]+1,dp));
    }else{
        cnt = 1 + helper(a,n,i+1,dp);
    }
    return dp[i] = cnt;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> dp(n+1,-1);
    int ans = helper(a,n,0,dp);
    // for(int i=0;i<n;i++){
    //     int cnt = i;
    //     int ind = helper(a,n,i);
    //     int removedEl = n-ind;
    //     ans = min(ans,cnt+removedEl);
    // }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
