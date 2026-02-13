#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

vector<vector<int> > adj;
vector<int> dp;
map<pair<int,int>,int> ind;

void dfs(int v,int p){
    for(auto x:adj[v]){
        if(x==p) continue;
        if(ind[make_pair(p,v)]<ind[make_pair(v,x)]){
            dp[x]=dp[v];
        }else{
            dp[x]=dp[v]+1;
        }
        dfs(x,v);
    }
}

void solve(){
    int n;
    cin>>n;
    adj.assign(n,vector<int>());
    dp.assign(n,0);
    ind.clear();

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ind[make_pair(a,b)]=i;
        ind[make_pair(b,a)]=i;
    }

    ind[make_pair(-1,0)]=-1;
    dp[0]=1;
    dfs(0,-1);

    cout<<*max_element(dp.begin(),dp.end())<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
