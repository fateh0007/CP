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
    int n;
    cin>>n;
    vector<int> weights(n+1);
    for(int i=1;i<=n;i++){
        cin>>weights[i];
    }
    vector<vector<int> > adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vec;
    int val = 0;
    for(int i=1;i<=n;i++){
        val+=weights[i];
        int sz = adj[i].size();
        for(int j=0;j<sz-1;j++){
            vec.push_back(weights[i]);
        }
    }
    sort(vec.rbegin(),vec.rend());
    cout<<val<<" ";
    for(int i=0;i<vec.size();i++){
        val+=vec[i];
        cout<<val<<" ";
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}