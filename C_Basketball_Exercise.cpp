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

int helper(vector<vector<int> > &v,int i,int j,int n,vector<vector<int> > &dp){
    if(i>=n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int notTake = helper(v,i+1,j,n,dp);
    int take = v[i][j] + helper(v,i+1,1-j,n,dp);
    return dp[i][j] = max(take,notTake);
}

void solve(){
    int n;
    cin>>n;
    vector<int> h1(n),h2(n);
    for(int i=0;i<n;i++){
        cin>>h1[i];
    }
    for(int i=0;i<n;i++){
        cin>>h2[i];
    }
    vector<vector<int> > v(n,vector<int> (2,0));
    for(int i=0;i<n;i++){
        v[i][0] = h1[i];
        v[i][1] = h2[i];
    }
    vector<vector<int> > dp(n,vector<int> (2,-1));
    int ans1 = helper(v,0,0,n, dp);
    int ans2 = helper(v,0,1,n, dp);
    cout<<max(ans1,ans2)<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
