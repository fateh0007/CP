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

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> factors[n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                factors[i].push_back(j);
                if(j*j!=i) factors[i].push_back(i/j);
            }
        }
    }
    int dp[k+1][n+1];
    for(int i=1;i<=n;i++){
        dp[1][i] = 1;
    }
    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = 0;
            for(auto x:factors[j]){
                dp[i][j] = (dp[i][j]+dp[i-1][x]) % mod;
            }
        }
    }
    int res =0;
    for(int i=1;i<=n;i++){
        res = (res+dp[k][i]) % mod;
    }
    cout<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
