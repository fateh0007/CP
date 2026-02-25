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

int dfs(vector<vector<int> > &adj,vector<bool> &visited,int node,vector<int> &connected){
    visited[node] = true;
    connected.push_back(node);
    int cnt = 1;
    for(auto it:adj[node]){
        if(!visited[it]){
            cnt+=dfs(adj,visited,it,connected);
        }
    }
    return cnt;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adj(n+1);
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        vector<int> nodes(k);
        for(int i=0;i<k;i++){
            cin>>nodes[i];
        }
        for(int i=0;i<k-1;i++){
            adj[nodes[i]].push_back(nodes[i+1]);
            adj[nodes[i+1]].push_back(nodes[i]);
        }
    }
    vector<int> ans(n+1,1);
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        vector<int> connected;
        if(!visited[i]){
            int cnt = dfs(adj,visited,i,connected);
            for(auto it:connected){
                ans[it] = cnt;
            }
        }
        
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
