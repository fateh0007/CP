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
int red = 0;
int white = 0;
void dfs(int node,int color,vector<vector<int> > &adj,vector<int> &vis){
    vis[node]++;
    if(color==1) red++;
    else white++;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,1-color,adj,vis);
        }
    }
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int> > adj(n,vector<int>());
    vector<int> vis(n,0);
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,0,adj,vis);
    cout<<1LL*red*white - (n-1)<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
