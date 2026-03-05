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
int factorial(int n){
    int res = 1;
    for(int i=1;i<=n;i++){
        res*=i;
    }
    return res;
}

// int dfs(vector<int> &fact,int sum, int ind,vector<vector<int> > &dp){
//     if(sum==0) return 0;
//     if(ind==0){
//         if(sum==fact[ind]) return 1;
//         return 1e12;
//     }
//     if(sum<0) return 1e12;
//     if(ind<=0) return 1e12;
//     if(dp[sum][ind]!=-1) return dp[sum][ind];
//     int ans = 1e12;
//     ans = min(1+dfs(fact,sum-fact[ind],ind-1,dp),dfs(fact,sum,ind-1,dp));
//     return dp[sum][ind] = ans;
// }

void solve(vector<int> &fact){
    int n;
    cin>>n;
    int p=1;
    set<int> st;
    while(p<=1e12){
        st.insert(p);
        p*=2;
    }
    if(st.find(n)!=st.end()){
        cout<<1<<endl;
        return;
    }
    int ind = 0;
    for(int i=0;i<fact.size();i++){
        if(fact[i]<=n) ind = i;
    }
    if(fact[ind]==n){
        cout<<1<<endl;
        return;
    }
    int ans = 60;
    for(int mask =0;mask<(1<<14);mask++){
        int sum = 0;
        int cnt = 0;
        for(int i=0;i<14;i++){
            if(mask&(1<<i)){
                sum+=fact[i];
                cnt++;
            }
        }
        if(sum>n) continue;

        int rem = n-sum;
        cnt += __builtin_popcountll(rem);
        ans=min(ans,cnt);
    }
    if(ans==60){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> fact;
    for(int i=1;i<=14;i++){
        int num = factorial(i);
        fact.push_back(num);
    }

    int t;
    cin>>t;
    while(t--) solve(fact);
}