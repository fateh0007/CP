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
const int INF = LLONG_MAX;
bool helper(vector<int> &a,int n,int x,int y,int ind,vector<int> &dp){
    int add = x+a[ind];
    int xr = x^a[ind];
    if(dp[ind]!=-1) return dp[ind];
    if(ind==n-1) return add==y || xr==y;
    if(add>y || xr>y) return false;
    return dp[ind] = helper(a,n,add,y,ind+1,dp) || helper(a,n,xr,y,ind+1,dp);
}
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> dp(n,-1);
    bool alice = helper(a,n,x,y,0,dp);
    bool bob = helper(a,n,x+3,y,0,dp);
    if(alice){
        cout<<"Alice"<<endl;;
    }
    else{
        cout<<"Bob"<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
