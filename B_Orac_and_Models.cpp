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

int helper(vector<int> &s,int ind, int n,vector<int> &dp){
    if(ind>=n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int take = 1;
    for(int mul = 2*ind;mul<n;mul+=ind){
        if(s[mul]>s[ind])take = max(take,1+helper(s,mul,n,dp));
    }
    return dp[ind] = take;
}

void solve(){
    int n;
    cin>>n;
    vector<int> s(n+1);
    s[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    vector<int> dp(n+1,-1);
    int ans = 1;
    for(int i=1;i<=n;i++){
        ans= max(ans,helper(s,i,n+1,dp));
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
