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

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int> mp;
    mp[1] = 6;
    mp[2] = 5;
    mp[3] = 4;
    mp[4] = 3;
    mp[5] = 2;
    mp[6] = 1;
    vector<vector<int> > dp(n,vector<int>(7,INF));
    for(int i=6;i>=1;i--){
        dp[0][i] = (a[0]==i?0:1);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=6;j++){
            int c = (a[i]==j?0:1);
            for(int k=1;k<=6;k++){
                if(j!=k && mp[j]!=k){
                    dp[i][j] = min(dp[i][j],dp[i-1][k]+c);
                }
            }
        }
    }
    int ans = 1e18;
    for(int i=1;i<=6;i++){
        ans = min(ans,dp[n-1][i]);
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
