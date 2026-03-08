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

int helper(int n,vector<int> &a,int flag,int idx,int takeCount,vector<vector<vector<int> > > &dp){
    if(idx>=n) return 0;
    if(dp[idx][flag][takeCount]!=-1) return dp[idx][flag][takeCount];
    int skipPoints = 0;
    if(flag==1){
        if(a[idx]==1 && takeCount<2){
            int left = INT_MAX;
            int right = INT_MAX;
            if(takeCount==0){
                left = 1 + helper(n,a,flag,idx+1,takeCount+1,dp);
            }else if(takeCount==1){
                right = min(1+ helper(n,a,!flag,idx+1,0,dp), helper(n,a,!flag,idx,0,dp));
            }
            skipPoints = min(left,right);
        }else if(a[idx]==0 && takeCount<2){
            int left = INT_MAX;
            int right = INT_MAX;
            if(takeCount==0){
                left = helper(n,a,flag,idx+1,takeCount+1,dp);
            }else if(takeCount==1){
                right = min(helper(n,a,!flag,idx+1,0,dp), helper(n,a,!flag,idx,0,dp));
            }
            skipPoints = min(left,right);
        }
    }else{
        skipPoints = min(helper(n,a,!flag,idx+1,takeCount,dp), helper(n,a,!flag,idx+2,takeCount,dp));
    }
    return dp[idx][flag][takeCount] = skipPoints;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<vector<int> > > dp(n+1,vector<vector<int> >(2,vector<int>(2,-1)));
    int res = helper(n,a,1,0,0,dp);
    cout<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}